cmake_minimum_required(VERSION 3.12)

project(ludo_cpp)
cmake_policy(SET CMP0076 NEW)
set(CMAKE_CXX_FLAGS "-Wall -std=c++17 -g -O0")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GodotCpp ../../godot-cpp)

add_library(ludo_engine SHARED)




set(SourcesI src/GdRegClass.cpp src/LudoEngine.cpp src/PPiece.cpp src/GameDisplay.cpp src/Player.cpp src/GameManager.cpp src/BoardDisplay.cpp)
set(IncDirs ${GodotCpp}/godot_headers ${GodotCpp}/include ${GodotCpp}/include/core ${GodotCpp}/include/gen ${GodotCpp}/bin includes )


target_include_directories(ludo_engine PUBLIC ${IncDirs} )
target_link_directories(ludo_engine PUBLIC ${GodotCpp}/bin)







target_sources(ludo_engine PUBLIC  ${SourcesI})
target_link_libraries(ludo_engine PUBLIC  libgodot-cpp.linux.debug.64.a)


