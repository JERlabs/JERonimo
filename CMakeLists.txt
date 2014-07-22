cmake_minimum_required (VERSION 2.6)

project (JERonimo)

include_directories (.)

set (SOURCES)
add_subdirectory (Space2D)
add_subdirectory (GameControl)
add_subdirectory (Entity)
add_subdirectory (SurfaceX)
add_subdirectory (ControlInterfaces)

set (SDL_BUILDING_LIBRARY true)
find_package (SDL REQUIRED)
find_package (SDL_image REQUIRED)


set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --std=c++11)

add_library (JERonimo SHARED ${SOURCES})
target_link_libraries (JERonimo SDL SDL_image)

install (TARGETS JERonimo DESTINATION usr/local/lib)
file(MAKE_DIRECTORY /usr/local/include/JERonimo)
file(MAKE_DIRECTORY /url/local/include/JERonimo/Space2D)
file(MAKE_DIRECTORY /usr/local/include/JERonimo/GameControl)
file(MAKE_DIRECTORY /usr/local/include/JERonimo/SurfaceX)
file(MAKE_DIRECTORY /usr/local/include/JERonimo/ControlInterfaces)

FILE(GLOB fSpace2D "${CMAKE_CURRENT_SOURCE_DIR}/Space2D/*.h")
FILE(GLOB fSurfaceX "${CMAKE_CURRENT_SOURCE_DIR}/SurfaceX/*.h")
FILE(GLOB fGameControl "${CMAKE_CURRENT_SOURCE_DIR}/GameControl/*.h")
FILE(GLOB fControlInterfaces "${CMAKE_CURRENT_SOURCE_DIR}/ControlInterfaces/*.h")
FILE(GLOB fHeaders "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

install(FILES ${fSpace2D} DESTINATION /usr/local/include/JERonimo/Space2D)
install(FILES ${fGameControl} DESTINATION /usr/local/include/JERonimo/GameControl)
install(FILES ${fControlInterfaces} DESTINATION /usr/local/include/JERonimo/ControlInterfaces)
install(FILES ${fSurfaceX} DESTINATION /usr/local/include/JERonimo/SurfaceX)
install(FILES ${fHeaders} DESTINATION /usr/local/include/JERonimo)