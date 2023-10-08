# Custom logger

A proof of concept about how to write a custom logger in C++ to be consumed by a client in delivered in static library.

Status:

| Command | Description |
| --- | --- |
| Linux build | [![Linux build](https://github.com/jke94/custom-logger/actions/workflows/cmake.yml/badge.svg)](https://github.com/jke94/custom-logger/actions/workflows/cmake.yml) |
| Docker Compose Builder | [![Docker Compose Builder](https://github.com/jke94/custom-logger/actions/workflows/dockercomposebuild.yml/badge.svg)](https://github.com/jke94/custom-logger/actions/workflows/dockercomposebuild.yml) |


## A. Quick start: How to use it.

Sample code:

```
#include <string>
#include "logger_api.h"

int main()
{
    // Set the log channels that you want use.
    init_logger("application.log", LoggerLevel::TRACE_CHANNEL | LoggerLevel::INFO_CHANNEL);

    WRITE_TRACE("This message wtriten in TRACE channel.");           // Channel activated: YES
    WRITE_INFO("This message wtriten in INFO channel.");             // Channel activated: YES
    WRITE_WARNING("This message wtriten in WARNING channel.");       // Channel activated: NO
    WRITE_ERROR("This message wtriten in ERROR channel.");           // Channel activated: NO
    WRITE_CRITICAL("This message wtriten in CRITICAL channel.");     // Channel activated: NO

    end_logger();

    return 0;
}
```
The **application.log** file will be created will a content similar like this:

```
2023-10-08 16:45:18.718 | [TRACE] | [main.cpp:main:18] This message wtriten in TRACE channel.
2023-10-08 16:45:18.719 | [INFO] | [main.cpp:main:19] This message wtriten in INFO channel.
```

## B. Docker compose (as linux builder and custom logger library client)

- Linux:

```
sudo docker compose -f ./docker-compose.yml -p custom-logger-lib up --build
```

- Windows:

```
docker-compose -f ./docker-compose.yml -p custom-logger-lib up --build
```

## C. Interesting links as posible examples.

- [stackoverflow - c-wrapping-a-wrapper-macro-with-variable-arguments](https://stackoverflow.com/questions/22395738/c-wrapping-a-wrapper-macro-with-variable-arguments)

- [Improving Print Logging with Line Pos Info & Modern C+](https://www.cppstories.com/2019/04/file-pos-log/)

- [What are __FILE__, __LINE__, and __FUNCTION__ in C++](https://www.tutorialspoint.com/what-are-file-line-and-function-in-cplusplus)
