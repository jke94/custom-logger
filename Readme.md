# Custom logger

A proof of concept about how to write a custom logger in C++ to be consumed by a client in delivered in dynamic library.

Status:

| Command | Description |
| --- | --- |
| Linux build | [![Linux build](https://github.com/jke94/custom-logger/actions/workflows/cmake.yml/badge.svg)](https://github.com/jke94/custom-logger/actions/workflows/cmake.yml) |
| Docker Compose Builder | [![Docker Compose Builder](https://github.com/jke94/custom-logger/actions/workflows/dockercomposebuild.yml/badge.svg)](https://github.com/jke94/custom-logger/actions/workflows/dockercomposebuild.yml) |


## A. Docker compose (as linux builder and custom logger library client)

- Linux:

```
sudo docker compose -f ./docker-compose.yml -p custom-logger-lib up --build
```

- Windows:

```
docker-compose -f ./docker-compose.yml -p custom-logger-lib up --build
```

## B. Interesting links as posible examples.

- [stackoverflow - c-wrapping-a-wrapper-macro-with-variable-arguments](https://stackoverflow.com/questions/22395738/c-wrapping-a-wrapper-macro-with-variable-arguments)

- [Improving Print Logging with Line Pos Info & Modern C+](https://www.cppstories.com/2019/04/file-pos-log/)

- [What are __FILE__, __LINE__, and __FUNCTION__ in C++](https://www.tutorialspoint.com/what-are-file-line-and-function-in-cplusplus)
