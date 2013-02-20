cmake_minimum_required (VERSION 2.6)
project (sfTheora)

set(INCROOT  ${PROJECT_SOURCE_DIR}/include)
set(INCSFTH ${INCROOT}/sfTheora)
set(INCLTP   ${INCROOT}/theoraplayer)
set(SRCROOT  ${PROJECT_SOURCE_DIR}/src)
set(SRCSFTH ${SRCROOT}/sfTheora)

include_directories(${INCROOT})

set(CMAKE_DEBUG_POSTFIX "_d")

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
            
install (TARGETS sfTheora DESTINATION lib)
install (FILES ${INCROOT}/sfTheora.h DESTINATION include)
install (FILES ${INCSFTH}/Error.h
               ${INCSFTH}/AudioInterface.h
               ${INCSFTH}/MemoryLoader.h
               ${INCSFTH}/Video.h
         DESTINATION include/sfTheora)
install (FILES ${INCLTP}/TheoraAsync.h
               ${INCLTP}/TheoraAudioInterface.h
               ${INCLTP}/TheoraDataSource.h
               ${INCLTP}/TheoraException.h
               ${INCLTP}/TheoraExport.h
               ${INCLTP}/TheoraFrameQueue.h
               ${INCLTP}/TheoraPlayer.h
               ${INCLTP}/TheoraTimer.h
               ${INCLTP}/TheoraUtil.h
               ${INCLTP}/TheoraVideoClip.h
               ${INCLTP}/TheoraVideoFrame.h
               ${INCLTP}/TheoraVideoManager.h
               ${INCLTP}/TheoraWorkerThread.h
         DESTINATION include/theoraplayer)
