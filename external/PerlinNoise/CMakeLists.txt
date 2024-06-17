cmake_minimum_required(VERSION 3.12)

project(PerlinNoise)

add_library(PerlinNoise STATIC
	include/PerlinNoise.hpp
	src/example.cpp
)

target_include_directories(PerlinNoise PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${PerlinNoise_SOURCE_DIR}/src
)

target_link_libraries(PerlinNoise PUBLIC raylib ImGui)

target_compile_features(PerlinNoise PUBLIC cxx_std_17)