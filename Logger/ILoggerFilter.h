#include <iostream>

class ILoggerFilter
{
    public:
        virtual bool apply_filter() = 0;
};
