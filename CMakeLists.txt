cmake_minimum_required(VERSION 3.21)

project(ASIO
    DESCRIPTION "Networking with asio"
    LANGUAGES CXX C
)

include(cmake/setup.cmake)
include(cmake/findDependencies.cmake)
include(cmake/compilerFlags.cmake)

add_subdirectory(basic)

include(cmake/summary.cmake)
