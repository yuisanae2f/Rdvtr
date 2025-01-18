cmake_minimum_required(VERSION 3.20)
enable_testing()
include(cmake/Core.cmake)
message(${ae2f_IS_SHARED})
message(${ae2f_packcount})
message(${ae2f_LibDirGlob})
message(${ae2f_LIBPREFIX})

project(Core-Template VERSION 1.3.5 LANGUAGES C CXX)

if(NOT TARGET ${PROJECT_NAME})
    message(${PROJECT_NAME})
endif()