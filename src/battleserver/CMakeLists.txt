# Copyright (C) 2014 FoxEmu <http://www.foxemu.ovh/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

IF (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    SET(CMAKE_CXX_FLAGS "-g -std=c++11 -pedantic")
ELSEIF (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    SET(CMAKE_CXX_FLAGS "/EHsc") #So it doesn't constantly throw warnings
ELSEIF (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    IF (WIN32)
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
    ${CMAKE_SOURCE_DIR}/dep/enet
    ${CMAKE_SOURCE_DIR}/dep/raf
    ${CMAKE_SOURCE_DIR}/src/game/Chat
    ${CMAKE_SOURCE_DIR}/src/game/Entities
    ${CMAKE_SOURCE_DIR}/src/game/Entities/Champion
    ${CMAKE_SOURCE_DIR}/src/game/Entities/Fountain
    ${CMAKE_SOURCE_DIR}/src/game/Entities/Minion
    ${CMAKE_SOURCE_DIR}/src/game/Entities/Turret
    ${CMAKE_SOURCE_DIR}/src/game/Entities/Unit
    ${CMAKE_SOURCE_DIR}/src/game/Map
    ${CMAKE_SOURCE_DIR}/src/game/Network
    ${CMAKE_SOURCE_DIR}/src/game/Spells
    ${CMAKE_SOURCE_DIR}/src/shared
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if (WIN32)
    if (MSVC)
        set(battleserver_SRCS
            ${battleserver_SRCS}
            battleserver.rc
        )
    endif()
endif()

add_executable(battleserver
    ${battleserver_SRCS}
)

add_dependencies(battleserver revision.h)

target_link_libraries(battleserver
    enet
    raf
    game
    scripts
    shared
    ${Boost_LIBRARIES}
)

if ( WIN32 )
    if ( MSVC )
        add_custom_command(TARGET battleserver
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/battleserver.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
        )
    elseif ( MINGW )
        add_custom_command(TARGET battleserver
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/battleserver.conf.dist ${CMAKE_BINARY_DIR}/bin/
        )
    endif()
endif()

if( UNIX )
    install(TARGETS battleserver DESTINATION bin)
    install(FILES battleserver.conf.dist DESTINATION ${CONF_DIR})
elseif( WIN32 )
    install(TARGETS battleserver DESTINATION "${CMAKE_INSTALL_PREFIX}")
    install(FILES battleserver.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
