cmake_minimum_required (VERSION 3.6)
project ("voxeltronik")
file (GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")
include_directories("./include" "libcuckoo/libcuckoo" "external/sol2" "/usr/include/luajit-2.0/" "external/nanovg/src")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O2")
set(CMAKE_C_FLAGS "-fPIC")
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
add_executable(vtk ${SOURCES})

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)
target_link_libraries(vtk SDL2 GL GLEW GLU "luajit-5.1" ${CMAKE_THREAD_LIBS_INIT})


