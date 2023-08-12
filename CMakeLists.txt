
cmake_minimum_required(VERSION 3.13)

project(raylib_mod)

set(CMAKE_C_STANDARD 99)

set(SOURCES
  src/raylib_mod.c)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

if(NOT DEFINED ENV{HOOK_HOME})
  message(FATAL_ERROR "HOOK_HOME environment variable is not defined")
endif()

if(UNIX AND NOT APPLE)
  set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH $ENV{HOOK_HOME}/lib)
elseif(APPLE)
  set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "@loader_path/")
endif()

find_path(HOOK_INCLUDE_DIR
  NAMES hook.h 
  PATHS $ENV{HOOK_HOME}/include
  NO_DEFAULT_PATH)

find_library(HOOK_LIBRARY
  NAMES hook
  PATHS $ENV{HOOK_HOME}/lib
  NO_DEFAULT_PATH)

target_include_directories(${PROJECT_NAME} PUBLIC ${HOOK_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} ${HOOK_LIBRARY})

install(TARGETS ${PROJECT_NAME} 
  LIBRARY DESTINATION $ENV{HOOK_HOME}/lib)
