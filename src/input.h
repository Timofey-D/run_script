#ifndef input_h
#define input_h
#include <cstring>
#include <cstdint>
#include "utility.h"

class Input
{
    public:
        Input() {};
        ~Input();
        Input(const char * input[], int length);
        char * getSourceCode() const;
        char * getFileFlags() const;
        int getCompileFlag() const;
        void setSourceCode(char * source_code);
        void setFileFlags(char * file_flags);
        void setCompileFlag(int compile_flag);
        Input & operator=(const Input & other);
    private:
        char * source_code = nullptr;
        char * file_flags = nullptr;
        int compile_flag = INT32_MIN;
        static bool checkSourceCode(const char * input_code);
};

#endif // input_h
