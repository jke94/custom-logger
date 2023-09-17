#include <string>

class ILogger
{
    public:

        virtual void log_trace(std::string msg) = 0;
        virtual void log_info(std::string msg) = 0;
        virtual void log_warning(std::string msg) = 0;
        virtual void log_error(std::string msg) = 0;
        virtual void log_critical(std::string msg) = 0;
};