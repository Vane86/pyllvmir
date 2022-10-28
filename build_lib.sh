#!/usr/bin/bash

clang++ -Wall -O3 -std=c++11 -fPIC -shared $(llvm-config --cxxflags --system-libs --ldflags --libs) module.cpp -o libmodule.so

