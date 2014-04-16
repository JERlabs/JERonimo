cmake_minimum_required (VERSION 2.6)
project (JERonimo)

# set version number
set (JERonimo_VERSION_MAJOR 2)
set (JERonimo_VERSION_MINOR 0)

configure_file
(
	"${PROJECT_SOURCE_DIR}/JERonimoConfig.h.in"
	"${PROJECT_BINARY_DIR}/JERonimoConfig.h"
)

include_directories("${PROJECT_BINARY_DIR}")
add_executable(JERonimo jeronimo.cxx)