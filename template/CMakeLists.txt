cmake_minimum_required(VERSION 3.16)

if (NOT EXISTS "build/")
    file(MAKE_DIRECTORY "build")
    message("> Created build folder")
endif()

# get the folder name to use as executable name
get_filename_component(folder_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" folder_name ${folder_name})
project(${folder_name})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_BUILD_FLAGS "-O3")

# set c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# add submodules
add_subdirectory("${CMAKE_SOURCE_DIR}/../submodules/fmt" "${CMAKE_CURRENT_BINARY_DIR}/submodules/fmt")

add_executable(${PROJECT_NAME} main.cpp)

target_precompile_headers(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/../include/pch.h")

# include the include folder and submodule include folders
target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}/../submodules/fmt/include"
    "${CMAKE_SOURCE_DIR}/../include"
)

# link submodles
target_link_libraries(${PROJECT_NAME} "fmt")
