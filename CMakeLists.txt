cmake_minimum_required (VERSION 2.6)
#set (CMAKE_C_COMPILER gcc)
#set (CMAKE_CXX_COMPILER g++)

project (JERonimo)

include_directories (.)

set (SOURCES)
add_subdirectory (Space2D)
add_subdirectory (GameControl)
add_subdirectory (Entity)
add_subdirectory (SurfaceX)

set (SDL_BUILDING_LIBRARY true)
find_package (SDL REQUIRED)
find_package (SDL_image REQUIRED)


set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --std=c++11)

add_library (JERonimo SHARED ${SOURCES})
target_link_libraries (JERonimo SDL SDL_image)
