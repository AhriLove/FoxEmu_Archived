# Copyright (C) 2014 FoxEmu <Website in development>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_Network Network/*.cpp Network/*.h)

# Create game-libary

set(game_STAT_SRCS
  ${game_STAT_SRCS}
  ${sources_Network}
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/enet
  ${CMAKE_SOURCE_DIR}/dep/raf
  ${CMAKE_SOURCE_DIR}/src/shared
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Network
)

add_library(game STATIC
  ${game_STAT_SRCS}
)

add_dependencies(game revision.h)
