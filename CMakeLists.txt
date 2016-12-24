cmake_minimum_required(VERSION 3.4.3)

project(sdl-test)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

message(STATUS "CMAKE_MODULE_PATH:" ${CMAKE_MODULE_PATH})
find_package(SDL2 REQUIRED)
find_package(SDL2IMAGE REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2IMAGE_INCLUDE_DIR})

find_package(CHIPMUNK REQUIRED)

include_directories(${CHIPMUNK_INCLUDE_DIR})

add_executable(game src/main.c src/sdl_setup.c src/game.c src/grb.c)
target_link_libraries(game ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY} ${CHIPMUNK_LIBRARY} m)


##install(TARGETS sdl-test RUNTIME DESTINATION ${BIN_DIR})
