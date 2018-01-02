# Huffman
`jskyzero` `2018/01/02`

## Overview
+ Huffman Image Encoding Using OpenCV
+ Huffman code is a particular type of optimal prefix code that is commonly used for lossless data compression.

## Install & Run

+ Install
```Shell
# mkdir a build folder
mkdir build
# change dir
cd build
# use cmake
cmake ..
# then make
make
```
+ Run
```Shell
# suppose you are in build folder
# see help
../out help
# run test
../out test
# compress
../out -d image_path
# decomress
../out -u image_path.huffman
```

## Structure
```
.
├── CMakeLists.txt
├── include
│   ├── BitBuffer.hpp
│   ├── Huffman.hpp
│   └── ImageEncoding.hpp
├── README.md
└── src
    ├── CMakeLists.txt
    └── Huffman.cpp
```
