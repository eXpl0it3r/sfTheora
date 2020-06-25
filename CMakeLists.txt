cmake_minimum_required (VERSION 2.6)
project (sfTheora)

set(INCROOT ${PROJECT_SOURCE_DIR}/include)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

set(INCSFTH ${INCROOT}/sfTheora)
set(SRCSFTH ${SRCROOT}/sfTheora)

include_directories(${INCROOT})

set(THEORAPLAYER_SDK_INCLUDE_DIR "THEORAPLAYER_SDK_INCLUDE_DIR" CACHE PATH "")
set(THEORAPLAYER_SDK_LIB_DIR "THEORAPLAYER_SDK_LIB_DIR" CACHE PATH "")

include_directories(${THEORAPLAYER_SDK_INCLUDE_DIR})

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

set(CMAKE_DEBUG_POSTFIX "-d")
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

add_library(sfTheora STATIC
              ${INCSFTH}/Error.h
              ${INCSFTH}/AudioInterface.h
              ${INCSFTH}/MemoryLoader.h
              ${INCSFTH}/Video.h
              ${INCROOT}/sfTheora.h
              ${SRCSFTH}/AudioInterface.cpp
              ${SRCSFTH}/MemoryLoader.cpp
              ${SRCSFTH}/Video.cpp
            )
            
install (TARGETS sfTheora
         DESTINATION lib)
install (FILES ${INCROOT}/sfTheora.h
         DESTINATION include)
install (DIRECTORY ${INCSFTH}
         DESTINATION include)
install (DIRECTORY ${THEORAPLAYER_SDK_INCLUDE_DIR}/theoraplayer
         DESTINATION include)
install (DIRECTORY ${THEORAPLAYER_SDK_INCLUDE_DIR}/theora
         DESTINATION include)
install (DIRECTORY ${THEORAPLAYER_SDK_INCLUDE_DIR}/ogg
         DESTINATION include)
install (DIRECTORY ${THEORAPLAYER_SDK_INCLUDE_DIR}/vorbis
         DESTINATION include)