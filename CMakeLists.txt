cmake_minimum_required(VERSION 3.5)
project(battleship)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 2)
set(VERSION_PATCH 2)

if (EXISTS ${PROJECT_SOURCE_DIR}/.git)
    execute_process(COMMAND
        git --git-dir=${PROJECT_SOURCE_DIR}/.git rev-parse HEAD
        OUTPUT_VARIABLE VERSION_COMMIT)
    string(STRIP ${VERSION_COMMIT} VERSION_COMMIT)
else ()
    set(VERSION_COMMIT "unknown")
endif ()

set(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

set(PRODUCT_NAME "battleship")
set(COMPANY_NAME "zer0main's classic games")
set(PRODUCT_DESCRIPTION "Battleship game with bot and many other modes")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/build/linux/package.sh.in
    ${CMAKE_CURRENT_BINARY_DIR}/package.sh @ONLY)

include_directories(
    src/bot
    src/model
    src/util
    src/controller
    src/desk_functions
    src/view
    src
    "${PROJECT_BINARY_DIR}"
)

# Qt5 Setup
find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Source files
file(GLOB sources
    "src/model/*.cpp"
    "src/bot/*.cpp"
    "src/util/*.cpp"
    "src/controller/*.cpp"
    "src/desk_functions/*.cpp"
    "src/view/*.cpp"
    "src/*.cpp"
)

file(GLOB headers "src/view/*.hpp")
file(GLOB uis "src/view/*.ui")
set(resources "src/view/qbattleship.qrc")

# Windows .rc generation
set(BATTLESHIP_RC_FILENAME "battleship.exe")
set(BATTLESHIP_RC_INTERNAL "battleship")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/build/windows/battleship.rc.in
    ${CMAKE_CURRENT_BINARY_DIR}/battleship.rc @ONLY)
unset(BATTLESHIP_RC_FILENAME)
unset(BATTLESHIP_RC_INTERNAL)

if (CMAKE_RC_COMPILER)
    list(APPEND sources ${CMAKE_CURRENT_BINARY_DIR}/battleship.rc)
endif()

add_executable(battleship
    ${sources}
    ${headers}
    ${uis}
    ${resources}
)

target_link_libraries(battleship Qt5::Widgets)

if (MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "-mwindows")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/build/windows/wizard.nsi.in
        ${CMAKE_CURRENT_BINARY_DIR}/wizard.nsi @ONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/build/windows/nsis_wizard.sh.in
        ${CMAKE_CURRENT_BINARY_DIR}/nsis_wizard.sh @ONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/build/windows/package.sh.in
        ${CMAKE_CURRENT_BINARY_DIR}/package.sh @ONLY)
endif ()
