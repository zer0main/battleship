cmake_minimum_required(VERSION 2.6)
project(battleship)

include_directories(src/bot)
include_directories(src/model)
include_directories(src/util)
include_directories(src/controller)
include_directories(src/desk_functions)
include_directories(src/view)
include_directories(src)

include_directories("${PROJECT_SOURCE_DIR}/src/view"
    "${PROJECT_BINARY_DIR}/src/view"
    "${PROJECT_BINARY_DIR}")

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

file(GLOB sources "src/model/*.cpp", "src/bot/*.cpp",
    "src/util/*.cpp", "src/controller/*.cpp",
    "src/desk_functions/*.cpp", "src/view/*.cpp",
    "src/*.cpp")
file(GLOB uis "src/view/*.ui")
file(GLOB qheaders "src/view/*.h")

QT4_WRAP_UI(UISrcs ${uis})
QT4_WRAP_CPP(MOCrcs ${qheaders})
QT4_ADD_RESOURCES(RCSrcs "src/view/qbattleship.qrc")

add_executable(battleship ${sources} ${MOCrcs} ${UISrcs}
    ${RCSrcs})
TARGET_LINK_LIBRARIES(battleship ${QT_LIBRARIES})
