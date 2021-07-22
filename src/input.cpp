#include "input.h"
#include "utility.h"
#include <exception>
#include <fstream>
#include <regex>


Input::Input(const char * input[], int length)
{
    if (length == 1)
    {
       throw std::runtime_error("Invalid command!");
    }

    bool file_was_found = 0;
    bool right_file = 0;
    bool right_flags = 0;

    for (int i = 1; i < length; i++)
    {
        std::regex file_regex("([a-zA-Z0-9\-\_\.])+.(cpp|c)");
        std::regex compile_flags("-[0 | 1 | 2 | 3]?");
        std::regex command_flags("-[d | e | n | p | w]*");
        if (std::regex_match(input[i], file_regex))
        { 
            right_file = !checkSourceCode(input[i]);
            file_was_found = 1;
            int file_length = static_cast<int>(Utility::length(input[i]));
            this->source_code = new char[file_length + 1];
            this->source_code[file_length] = '\0';
            strcpy(this->source_code, input[i]);
        }
        else if (std::regex_match(input[i], compile_flags) || std::regex_match(input[i], command_flags))
        {
            if (std::regex_match(input[i], compile_flags))
            {
                if (this->compile_flag != INT32_MIN)
                {
                    throw std::invalid_argument("It was obtained more one flag!");
                }
                this->compile_flag = input[i][1] - '0';
            }
            else
            {
                if (this->file_flags != nullptr)
                {
                    throw std::invalid_argument("It was obtained more one flag!");
                }
                int flags_length = static_cast<int>(Utility::length(input[i]));
                this->file_flags = new char[flags_length + 1];
                this->file_flags[flags_length] = '\0';
                strcpy(this->file_flags, input[i]);
            }
        }
        else
        {
            right_flags = 1;
        }
    }

    if (!file_was_found)
    {
        throw std::runtime_error("File wasn't found!");
    }
    if (right_file)
    {
        throw std::invalid_argument("Source file doesn't exist!");
    }
    if (right_flags)
    {
        throw std::invalid_argument("The obtained flag or flags are invalid!");     
    }
    
    if (this->compile_flag == INT32_MIN)
    {
        this->compile_flag = 0;
    }
    if (this->file_flags == nullptr)
    {
        this->file_flags = new char[2];
        strcpy(this->file_flags, "0\0");
    }
}


bool Input::checkSourceCode(const char * source_code)
{
    std::fstream file(source_code);
    return file.good();
}


// Getters block
char * Input::getSourceCode() const
{
    return this->source_code;
}


char * Input::getFileFlags() const
{
    return this->file_flags;
}


int Input::getCompileFlag() const
{
    return this->compile_flag;
}


// Setters block
void Input::setSourceCode(char * source_code)
{
    int length = static_cast<int>(Utility::length(source_code));
    this->source_code = new char[length + 1];
    this->source_code[length] = '\0';
    strcpy(this->source_code, source_code);
}


void Input::setFileFlags(char * file_flags)
{
    int length = static_cast<int>(Utility::length(file_flags));
    this->file_flags = new char[length + 1];
    this->file_flags[length] = '\0';
    strcpy(this->file_flags, file_flags);
}


void Input::setCompileFlag(int compile_flag)
{
    this->compile_flag = compile_flag;
}



Input & Input::operator=(const Input & other)
{
   if (this == &other)
   {
       return * this;
   }
   this->setSourceCode(other.getSourceCode());
   this->setCompileFlag(other.getCompileFlag());
   this->setFileFlags(other.getFileFlags());
   return * this;
}


// Destructor
Input::~Input()
{
    if (source_code == nullptr)
    {
        delete[] source_code;
    }
    if (file_flags == nullptr)
    {
        delete[] file_flags;
    }
}
