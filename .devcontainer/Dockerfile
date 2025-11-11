FROM alpine:latest

RUN apk add --no-cache \
	git \
  gcc \
  gdb \
  clang \
  lldb \
  make \
  ninja-build \
  cmake \
  valgrind

COPY . .
