cmake_minimum_required(VERSION 2.6)
project(battleship)

file(GLOB sources "src/model/*.cpp", "src/bot/*.cpp",
    "src/util/*.cpp", "src/controller/*.cpp",
    "src/desk_functions/*.cpp", "src/*.cpp")

include_directories(src/bot)
include_directories(src/model)
include_directories(src/util)
include_directories(src/controller)
include_directories(src/desk_functions)
include_directories(src)

add_executable(battleship ${sources})
