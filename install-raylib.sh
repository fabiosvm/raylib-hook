#!/usr/bin/env bash

set -e

sudo apt install build-essential git
sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev

git clone https://github.com/raysan5/raylib.git
cd raylib
mkdir build && cd build
cmake -DBUILD_SHARED_LIBS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE=ON ..
make
sudo make install
cd ../..
