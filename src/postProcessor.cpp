#include <iostream>
#include <cstdio>
#include <cstring>
#include "utility.h"
#include "postProcessor.h"
#define SIZE_OF_COMMAND 24

PostProcessor::PostProcessor(const char * execution, const char * flags)
{
    executeCommand(flags, execution);
}


void PostProcessor::executeCommand(const char * flags, const char * execution)
{
    char * execute_command = new char[SIZE_OF_COMMAND]; 
    char * delete_command = new char[SIZE_OF_COMMAND]; 
    strcpy(execute_command, "./");
    bool executed = 0;
    if (Utility::thereIsChar(flags, 'e'))
    {
        strcat(execute_command, execution);
        std::system(execute_command);
        executed = 1;
    }
    if (Utility::thereIsChar(flags, 'd'))
    {
        if (!executed)
        {
            strcat(execute_command, execution);
            std::system(execute_command);
        }
        strcpy(delete_command, "rm -R ");
        strcat(delete_command, execution);
        std::system(delete_command);
        std::cout << "File \"" << execution << "\" was deleted!" << std::endl;
    }
    delete[] execute_command;
    delete[] delete_command;
}
