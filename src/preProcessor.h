#ifndef preProcessor_h
#define preProcessor_h
#include <fstream>
#include <cstring>

class PreProcessor
{
    public:
        PreProcessor(const char * source_code, const char * file_flags);
        ~PreProcessor();
        char * getExecutionFile() const;
        void setExecutionFile(const char * filename);
    private:
       char * execution_file = nullptr;

       static constexpr const char * all_pre_compile_flags = "nwp\0";

       static size_t FilenameLength(const char * source_file, char symbol);
       static void getFilename(const char * source_code, char * target_file, int name_length);
       static bool thereIsChar(const char * source, const char symbol);
       bool checkFileExe(const char * filename);
       void createExeFile(const bool & new_file, const bool & extension, int name_length);
};

#endif // PreProcessor_h
