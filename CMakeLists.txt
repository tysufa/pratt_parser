cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Pratt_parser)

add_executable(Pratt_parser main.cpp lexer.hh lexer.cc parser.cc)
