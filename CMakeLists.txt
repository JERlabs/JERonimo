cmake_minimum_required (VERSION 2.6)

project (JERonimo)

include_directories (.)

set (SUBDIRS Space2D SurfaceX ControlInterfaces)

set (SOURCES)
foreach(subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach(subdir)

set (SDL_BUILDING_LIBRARY true)
find_package (SDL REQUIRED)
find_package (SDL_image REQUIRED)


set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --std=c++11)

add_library (JERonimo SHARED ${SOURCES})
target_link_libraries (JERonimo SDL SDL_image)

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
        target_link_libraries(${testAspect} ${PROJECT_NAME})
        #add_custom_target(${testAspect}  ${testAspect} DEPENDS ${testAspect})
    endforeach(testFile)
endforeach(subdir)

#function(compile_test subdir testedComp)
#    add_executable(${testComp} test/${subdir}/${testedComp}Test.cpp)
#    target_link_libraries(${testComp} ${PROJECT_NAME})
#endfunction(compile_test)
