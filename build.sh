#!/bin/sh

if [[ "$@" == "refresh" ]]; then
                cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
fi

cmake --build build && ./build/rtxi
