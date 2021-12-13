cmake_minimum_required(VERSION 3.20)
project(blockchanin)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        blockchanin main.cpp
        include/TransactionData.h
        include/Block.h
        include/Blockchain.h src/Block.cpp src/Blockchain.cpp src/TransactionData.cpp main.h)
