#ifndef postProcessor_h
#define postProcessor_h

class PostProcessor
{
    public:
        PostProcessor(const char * execution, const char * flags);

    private:
        static constexpr const char * all_post_compile_flags = "de\0";

        void executeCommand(const char * flags, const char * execution);
};
#endif // postProcessor_h
