#!/usr/bin/env bash

set -e

git clone https://github.com/fabiosvm/hook-lang
cd hook-lang
scripts/build.sh
cd ..
