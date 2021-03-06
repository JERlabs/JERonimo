cmake_minimum_required (VERSION 2.6)

project (JERonimo)

include_directories (.)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR})
set (SUBDIRS Space2D ControlInterfaces SDLWrappers GameUtilities)

set (SOURCES)
foreach(subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach(subdir)

#set (SDL2_BUILDING_LIBRARY true)
find_package (SDL2 REQUIRED)
find_package (SDL2_image REQUIRED)

message("SDL2 LIBRARY PATHS ${SDL2_LIBRARY}")
string(REGEX MATCH ";(C:/|/).*libSDL2main.*;" MY_SDL2_MAIN_LIB "${SDL2_LIBRARY}")
message("SDL2 MAIN LIBRARY PATH ${MY_SDL2_MAIN_LIB}")
string(REPLACE ${MY_SDL2_MAIN_LIB} ";" SDL2_JER_LIBRARIES ${SDL2_LIBRARY})
message("REMOVED SDL2 MAIN ${SDL2_JER_LIBRARIES}")

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --std=c++11)

add_library (JERonimo SHARED ${SOURCES})
target_link_libraries (JERonimo ${SDL2_JER_LIBRARIES} ${SDL2_IMAGE_LIBRARY})

install (TARGETS JERonimo DESTINATION usr/local/lib)
install (DIRECTORY DESTINATION /usr/local/include/${PROJECT_NAME})
foreach(subdir ${SUBDIRS})
    install(DIRECTORY DESTINATION /usr/local/include/${PROJECT_NAME}/${subdir})
    FILE(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/*.h")
    install(FILES ${headers} DESTINATION /usr/local/include/${PROJECT_NAME}/${subdir})
    install(FILES "${subdir}.h" DESTINATION /usr/local/include/${PROJECT_NAME})
endforeach(subdir)



foreach(subdir ${SUBDIRS})
    FILE(GLOB tests "${CMAKE_CURRENT_SOURCE_DIR}/test/${subdir}/*Test.cpp")
    foreach(testFile ${tests})
        STRING(REGEX REPLACE ".*test/${subdir}/([a-zA-Z0-9]+Test).*" "\\1" testAspect "${testFile}")
        add_executable(${testAspect} EXCLUDE_FROM_ALL ${testFile})
        target_link_libraries(${testAspect} ${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} )
        #add_custom_target(${testAspect}  ${testAspect} DEPENDS ${testAspect})
    endforeach(testFile)
endforeach(subdir)

#function(compile_test subdir testedComp)
#    add_executable(${testComp} test/${subdir}/${testedComp}Test.cpp)
#    target_link_libraries(${testComp} ${PROJECT_NAME})
#endfunction(compile_test)
