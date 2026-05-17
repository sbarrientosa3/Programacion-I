cmake_minimum_required(VERSION 3.10)
project(MiProyecto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

set(EXECUTABLES)
foreach(src ${SRC_FILES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src}
            "Tarea XI - Archivos binarios/Codigo_Fuente.cpp")
    list(APPEND EXECUTABLES ${name})
endforeach()

add_custom_target(build_all_executables DEPENDS ${EXECUTABLES})