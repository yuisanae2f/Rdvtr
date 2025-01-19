cmake_minimum_required(VERSION 3.20)
enable_testing()
include(cmake/Core.cmake)

project(Rdvtr VERSION 0.0.0 LANGUAGES C CXX)
option(PROJECTREFGET "" OFF)

if(PROJECTREFGET)
    execute_process(
        COMMAND 
        git clone 
        https://github.com/yuisanae2f/Rudventure 
        ${ae2f_ProjRoot}/RudventureRef
        RESULT_VARIABLE result
    )
endif()

if(NOT TARGET ${PROJECT_NAME})
    ae2f_CoreLibFetch(ae2f Core main)
    ae2f_CoreLibFetch(ae2f Ds main)
    
    message(${PROJECT_NAME})
    ae2f_CoreLibTent(
        Rdvtr ${ae2f_LIBPREFIX} include Rdvtr
        "include/Rdvtr/Ansi.h"
        "src/Ansi.c"
        
        "include/Rdvtr/Rndr.h"
        "include/Rdvtr/Rndr.hpp"
        "src/Rndr.c"
    )
    target_link_libraries(Rdvtr PUBLIC Core)
    target_link_libraries(Rdvtr PUBLIC Ds)

    find_package(SDL2)
    if(${SDL2_FOUND})
        target_link_libraries(Rdvtr PUBLIC SDL2::SDL2)
    else()
        ae2f_CoreLibFetch(libsdl-org SDL SDL2)
        target_link_libraries(Rdvtr SDL2)
    endif()

    ae2f_CoreTestTent(Rdvtr test)
endif()

