#!/bin/bash

LD_LIBRARY_PATH="$(pwd)/lib"
export LD_LIBRARY_PATH
valgrind ./bin/tetris
