cmake_minimum_required(VERSION 3.13)
project(camin)

set(CAMIN_VERSION_MAJOR 0)
set(CAMIN_VERSION_MINOR 1)
set(CAMIN_VERSION_PATCH 2)
set(CAMIN_VERSION_STRING ${CAMIN_VERSION_MAJOR}.${CAMIN_VERSION_MINOR}.${CAMIN_VERSION_PATCH})

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig)

pkg_search_module(LIBXML2 libxml++-2.6)

add_subdirectory(libamin)

link_directories(libamin)

include_directories(libamin)

add_executable(camin camin.cpp)

include_directories(camin PUBLIC ${LIBXML2_INCLUDE_DIRS})
link_libraries(camin ${LIBXML2_LIBRARIES})

target_link_libraries(camin amin)

install(TARGETS camin DESTINATION bin)