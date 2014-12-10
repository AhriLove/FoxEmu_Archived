# Copyright (C) 2014 FoxEmu <http://www.foxemu.ovh/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "-g -std=c++11 -pedantic")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "/EHsc") #So it doesn't constantly throw warnings
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    if (WIN32)
        set(CMAKE_CXX_FLAGS "/Qstd=c++11")
    else ()
        set(CMAKE_CXX_FLAGS "-std=c++11")
    endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

file(GLOB loginserver_files *.cpp *.h)

set(loginserver_SRCS
    ${loginserver_SRCS}
    ${loginserver_files}
)

include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/dep/raf
    ${CMAKE_SOURCE_DIR}/src/shared
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if ( WIN32 )
    if ( MSVC )
        set(loginserver_SRCS
            ${loginserver_SRCS}
            loginserver.rc
        )
    endif ()
endif()

add_executable(loginserver
    ${loginserver_SRCS}
)

add_dependencies(loginserver revision.h)

target_link_libraries(loginserver
    raf
    ${Boost_LIBRARIES}
)

if ( WIN32 )
    if ( MSVC )
        add_custom_command(TARGET loginserver
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/loginserver.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
        )
    elseif ( MINGW )
        add_custom_command(TARGET loginserver
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/loginserver.conf.dist ${CMAKE_BINARY_DIR}/bin/
        )
    endif()
endif()

if( UNIX )
    install(TARGETS loginserver DESTINATION bin)
    install(FILES loginserver.conf.dist DESTINATION ${CONF_DIR})
elseif( WIN32 )
    install(TARGETS loginserver DESTINATION "${CMAKE_INSTALL_PREFIX}")
    install(FILES loginserver.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
