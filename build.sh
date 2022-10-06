#!/bin/bash
set -x 
${LLVM_INSTALL_DIR}/bin/clang++ -g -O3 -I. -std=libc++ *.cpp `${LLVM_INSTALL_DIR}/bin/llvm-config --cxxflags`
