# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.26
cmake_policy(SET CMP0009 NEW)

# MY_SOURCES at CMakeLists.txt:28 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "C:/Code/Raylib/src/*.cpp")
set(OLD_GLOB
  "C:/Code/Raylib/src/Player.cpp"
  "C:/Code/Raylib/src/PlayerCamera.cpp"
  "C:/Code/Raylib/src/main.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/Code/Raylib/cmake-build-default/CMakeFiles/cmake.verify_globs")
endif()
