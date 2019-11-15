#!/bin/bash

if ! cd build; then
  mkdir build
  cd build
fi
cmake ..
make
