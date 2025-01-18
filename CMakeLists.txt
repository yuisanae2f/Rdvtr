cmake_minimum_required(VERSION 3.20)
enable_testing()
include(cmake/Core.cmake)

project(libRudventure VERSION 0.0.0 LANGUAGES C CXX)
option(PROJECTREFGET "" OFF)

if(NOT TARGET ${PROJECT_NAME})
    message(${PROJECT_NAME})
    if(PROJECTREFGET)
        execute_process(
            COMMAND 
            git clone 
            https://github.com/yuisanae2f/Rudventure 
            ${ae2f_ProjRoot}/RudventureRef
            RESULT_VARIABLE result
        )
    endif()
endif()

project(Rudventure VERSION 0.0.0 LANGUAGES C CXX)
if(NOT TARGET ${PROJECT_NAME})
    message(${PROJECT_NAME})
endif()
