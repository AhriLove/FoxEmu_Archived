# Copyright (C) 2014 FoxEmu <Website in development>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_Champions Champions/*.cpp Champions/*.h)
file(GLOB_RECURSE sources_Commands Commands/*.cpp Commands/*.h)
file(GLOB_RECURSE sources_Maps Maps/*.cpp Maps/*.h)

# Create scripts-library
set(scripts_STAT_SRCS
    ${scripts_STAT_SRCS}
    ${sources_Champions}
    ${sources_Commands}
    ${sources_Maps}
)

include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Champions
    ${CMAKE_CURRENT_SOURCE_DIR}/Commands
    ${CMAKE_CURRENT_SOURCE_DIR}/Maps
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
)

add_library(scripts STATIC
    ${scripts_STAT_SRCS}
)
