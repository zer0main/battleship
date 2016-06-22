cmake_minimum_required(VERSION 2.6)
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

IF (POLICY CMP0017)
    cmake_policy(SET CMP0017 NEW)
ENDIF (POLICY CMP0017)

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

file(GLOB sources "src/model/*.cpp" "src/bot/*.cpp"
    "src/util/*.cpp" "src/controller/*.cpp"
    "src/desk_functions/*.cpp" "src/view/*.cpp" "src/*.cpp")
file(GLOB uis "src/view/*.ui")
file(GLOB qheaders "src/view/*.hpp")

QT4_WRAP_UI(UISrcs ${uis})
QT4_WRAP_CPP(MOCrcs ${qheaders})
QT4_ADD_RESOURCES(RCSrcs "src/view/qbattleship.qrc")

set(BATTLESHIP_RC_FILENAME "battleship.exe")
set(BATTLESHIP_RC_INTERNAL "battleship")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/build/windows/battleship.rc.in
    ${CMAKE_CURRENT_BINARY_DIR}/battleship.rc @ONLY)
unset(BATTLESHIP_RC_FILENAME)
unset(BATTLESHIP_RC_INTERNAL)

if (CMAKE_RC_COMPILER)
    set(sources ${sources};${CMAKE_CURRENT_BINARY_DIR}/battleship.rc)
endif()

add_executable(battleship ${sources} ${MOCrcs} ${UISrcs}
    ${RCSrcs})
TARGET_LINK_LIBRARIES(battleship ${QT_LIBRARIES})

IF (MINGW)
    SET(CMAKE_EXE_LINKER_FLAGS -mwindows)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/build/windows/wizard.nsi.in
        ${CMAKE_CURRENT_BINARY_DIR}/wizard.nsi @ONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/build/windows/nsis_wizard.sh.in
        ${CMAKE_CURRENT_BINARY_DIR}/nsis_wizard.sh @ONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/build/windows/package.sh.in
        ${CMAKE_CURRENT_BINARY_DIR}/package.sh @ONLY)
ENDIF (MINGW)
