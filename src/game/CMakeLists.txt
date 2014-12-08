# Copyright (C) 2014 FoxEmu <Website in development>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_Chat Chat/*.cpp Chat/*.h)
file(GLOB_RECURSE sources_Entities Entities/*.cpp Entities/*.h)
file(GLOB_RECURSE sources_Map Map/*.cpp Map/*.h)
file(GLOB_RECURSE sources_Network Network/*.cpp Network/*.h)
file(GLOB_RECURSE sources_Spells Spells/*.cpp Spells/*.h)

# Create game-libary

set(game_STAT_SRCS
    ${game_STAT_SRCS}
    ${sources_Chat}
    ${sources_Entities}
    ${sources_Map}
    ${sources_Network}
    ${sources_Spells}
)

include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/dep/enet
    ${CMAKE_SOURCE_DIR}/dep/raf
    ${CMAKE_SOURCE_DIR}/src/shared
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Chat
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Champion
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Fountain
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Minion
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Turret
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Unit
    ${CMAKE_CURRENT_SOURCE_DIR}/Map
    ${CMAKE_CURRENT_SOURCE_DIR}/Network
    ${CMAKE_CURRENT_SOURCE_DIR}/Spells
)

add_library(game STATIC
    ${game_STAT_SRCS}
)

add_dependencies(game revision.h)
