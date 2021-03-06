#ifndef FOXEMU_COMMON_H
#define FOXEMU_COMMON_H

#include "revision.h"

#if PLATFORM == PLATFORM_WINDOWS
# ifdef _WIN64
#  define _FULLVERSION "FoxEmu rev. " VER_PRODUCTVERSION_STR " (Win64)"
# else
#  define _FULLVERSION "FoxEmu rev. " VER_PRODUCTVERSION_STR " (Win32)"
# endif
#else
#  define _FULLVERSION "FoxEmu rev. " VER_PRODUCTVERSION_STR " (Unix)"
#endif

#define CLIENTVERSION "Version 4.20.0.315 [PUBLIC]"

#endif //FOXEMU_COMMON_H
