#ifndef compilation_h
#define compilation_h

#include <map>


class Compilation 
{
    public:
        Compilation(const char * source_code, const char * execution, const int & flag);
    private:
        const std::map<int, const char *> compile_command = 
        {
            {0, "g++ "},
            {1, "g++ -Wall "},
            {2, "g++ -Wall -pedantic "},
            {3, "g++ -Wall -pedantic -std=c++17 "}
        };

};

#endif // Compilation_h
