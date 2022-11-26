cmake_minimum_required(VERSION 3.20)

if (NOT EXISTS "build/")
    file(MAKE_DIRECTORY "build")
    message("> Created build folder")
endif()

#get the folder name to use as executable nme
get_filename_component(folder_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" folder_name ${folder_name})
project(${folder_name})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_BUILD_FLAGS "-O3")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory("${CMAKE_SOURCE_DIR}/../submodules/fmt")

add_executable(${PROJECT_NAME} main.cpp data.cpp)

target_precompile_headers(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/../include/pch.h")

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}/../submodules/fmt/include"
    "${CMAKE_SOURCE_DIR}/../include"
)

target_link_libraries(${PROJECT_NAME} "fmt")

#this just writes the folder name in last.txt because doing that in bash is more complicated
write_file("${CMAKE_SOURCE_DIR}/../last.txt" "${folder_name}")