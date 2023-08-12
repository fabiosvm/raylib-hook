#!/usr/bin/env bash

set -e

if ! command -v cmake &> /dev/null
then
  echo "cmake could not be found"
  exit
fi

cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
