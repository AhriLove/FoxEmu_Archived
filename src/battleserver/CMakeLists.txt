# Copyright (C) 2014 FoxEmu <Website in development>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

IF(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    SET(CMAKE_CXX_FLAGS "-g -std=c++11 -pedantic")
ELSEIF(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    SET(CMAKE_CXX_FLAGS "/EHsc") #So it doesn't constantly throw warnings
ELSEIF(CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    IF(WIN32)
        SET(CMAKE_CXX_FLAGS "/Qstd=c++11")
    ELSE()
        SET(CMAKE_CXX_FLAGS "-std=c++11")
    ENDIF()
ELSEIF(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    SET(CMAKE_CXX_FLAGS "-std=c++11")
ENDIF()

file(GLOB battleserver_files *.cpp *.h)

set(battleserver_SRCS
    ${battleserver_SRCS}
    ${battleserver_files}
)

include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/dep/raf
    ${CMAKE_SOURCE_DIR}/src/shared
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if( WIN32 )
    if ( MSVC )
        set(battleserver_SRCS
            ${battleserver_SRCS}
            battleserver.rc
        )
    endif ()
endif()

add_executable(battleserver
    ${battleserver_SRCS}
)

add_dependencies(battleserver revision.h)

target_link_libraries(battleserver
    raf
)
