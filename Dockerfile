FROM ubuntu:latest AS builder
RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    && rm -rf /var/lib/apt/lists/*
COPY /Logger /Logger
COPY /Client /Client
COPY CMakeLists.txt /
WORKDIR /build
RUN cmake ..
RUN make

FROM ubuntu:latest
RUN mkdir output
COPY --from=builder /build/libdemologger.a /usr/lib
COPY --from=builder /build/main /output
WORKDIR /output
CMD ["./main"]