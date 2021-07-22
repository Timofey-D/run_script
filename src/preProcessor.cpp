#include <iostream>
#include "utility.h"
#include "preProcessor.h"
#include <cstring>
#include <fstream>
#include <algorithm>
#define SIZE_OF_FLAGS 5


PreProcessor::PreProcessor(const char * source_code, const char * flags)
{
    int filename_length = static_cast<int>(Utility::filenameLength(source_code, '.'));
    this->execution_file = new char[filename_length + 1];
    getFilename(source_code, this->execution_file, filename_length);
    this->execution_file[filename_length] = '\0';
        
    if (flags != 0)
    {
        this->createExeFile(Utility::thereIsChar(flags, 'n'), Utility::thereIsChar(flags, 'w'), filename_length);

        if (Utility::thereIsChar(flags, 'p'))
        {
            std::cout << this->execution_file << std::endl;
        }
    }
}


void PreProcessor::getFilename(const char * source_code, char * target_file, int name_length)
{
    for (int i = 0; i < name_length; i++)
    {
        target_file[i] = source_code[i];
    }
}


void PreProcessor::createExeFile(const bool & new_file, const bool & extension, int name_length)
{
    int ID = 1;
    if (!extension)
    {
        name_length += 4;
    }
    char * temp_filename = new char[name_length + 1];
    temp_filename[name_length] = '\0';
    strcpy(temp_filename, this->execution_file);

    // if extension equalls 0, then it needs to add extension
    if (!extension)
    {
        strcat(temp_filename, ".exe\0"); 
    }

    // if this statement equalls 0 and 0, then 
    if (!checkFileExe(temp_filename) || !new_file)
    {
        this->setExecutionFile(temp_filename);
        delete[] temp_filename;
        return;
    }

    do 
    {
        delete[] temp_filename;

        char * temp_filename = new char[name_length + 1];
        temp_filename[name_length] = '\0';
        strcpy(temp_filename, this->execution_file);
        strcat(temp_filename, "_\0");
        strcat(temp_filename, std::to_string(ID++).c_str());

        if (!extension)
        {
            strcat(temp_filename, ".exe\0"); 
        }
    } while(checkFileExe(temp_filename) || !new_file);
    
    this->setExecutionFile(temp_filename);

    delete[] temp_filename;
}


bool PreProcessor::checkFileExe(const char * filename)
{
    std::fstream file(filename);
    return file.good();
}


bool PreProcessor::thereIsChar(const char * source, const char symbol)
{
   for (int i = 0; source[i] != '\0'; i++)
   {
       if (source[i] == symbol)
       {
           return 1;
       }
   }
   return 0;
}


char * PreProcessor::getExecutionFile() const
{
    return this->execution_file;
}


void PreProcessor::setExecutionFile(const char * filename)
{
    delete[] this->execution_file;
    int length = static_cast<int>(Utility::length(filename));
    this->execution_file = new char[length + 1];
    this->execution_file[length] = '\0';
    strcpy(this->execution_file, filename);
}


PreProcessor::~PreProcessor()
{
    delete[] execution_file;
}
