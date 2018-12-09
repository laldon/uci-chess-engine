cmake_minimum_required(VERSION 3.13)
project(laser_dev)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/syzygy)

add_executable(laser_dev
        src/syzygy/tbcore.c
        src/syzygy/tbcore.h
        src/syzygy/tbprobe.cpp
        src/syzygy/tbprobe.h
        src/bbinit.cpp
        src/bbinit.h
        src/board.cpp
        src/board.h
        src/common.cpp
        src/common.h
        src/eval.cpp
        src/eval.h
        src/evalhash.cpp
        src/evalhash.h
        src/hash.cpp
        src/hash.h
        src/Makefile
        src/moveorder.cpp
        src/moveorder.h
        src/search.cpp
        src/search.h
        src/searchparams.h
        src/timeman.h
        src/uci.cpp
        src/uci.h)
