# Copyright (C) 2014 FoxEmu <Website in development>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

add_subdirectory(genrev)
add_subdirectory(shared)

if (LOGINSERVER)
    add_subdirectory(loginserver)
endif()

if (BATTLESERVER)
    add_subdirectory(battleserver)
    add_subdirectory(game)
    add_subdirectory(scripts)
endif()
