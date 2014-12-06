# Copyright (C) 2014 FoxEmu <Website in development>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB sources_localdir *.cpp *.h)

set(shared_STAT_SRCS
  ${shared_STAT_SRCS}
  ${sources_localdir}
)
include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_CURRENT_SOURCE_DIR}
)
add_library(shared STATIC
  ${shared_STAT_SRCS}
)
