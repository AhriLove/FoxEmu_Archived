#ifndef FOXCORE_COMMON_H
#define FOXCORE_COMMON_H

#include "revision.h"

#if PLATFORM == PLATFORM_WINDOWS
# ifdef _WIN64
#  define _FULLVERSION "FoxCore rev. " VER_PRODUCTVERSION_STR " (Win64)"
# else
#  define _FULLVERSION "FoxCore rev. " VER_PRODUCTVERSION_STR " (Win32)"
# endif
#else
#  define _FULLVERSION "FoxCore rev. " VER_PRODUCTVERSION_STR " (Unix)"
#endif
#endif
