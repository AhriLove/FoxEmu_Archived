/*
 * Copyright (C) 2014 FoxEmu <Website in development>
 * Copyright (C) 2002-2014 Lee Salzman <http://enet.bespin.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#define ENET_BUILDING_LIB 1
#include "enet.h"

static ENetCallbacks callbacks = { malloc, free, rand, abort };

int enet_initialize_with_callbacks(ENetVersion version, const ENetCallbacks* inits)
{
    if (inits->malloc != NULL || inits->free != NULL)
    {
        if (inits->malloc == NULL || inits->free == NULL)
            return -1;

        callbacks.malloc = inits->malloc;
        callbacks.free = inits->free;
    }

    if (inits->rand != NULL)
        callbacks.rand = inits->rand;

    if (version >= ENET_VERSION_CREATE(1, 2, 2))
        if (inits->no_memory != NULL)
            callbacks.no_memory = inits->no_memory;

   return enet_initialize ();
}

void* enet_malloc(size_t size)
{
    void* memory = callbacks.malloc(size);

    if (memory == NULL)
        callbacks.no_memory();

    return memory;
}

void enet_free(void* memory)
{
    callbacks.free(memory);
}

int enet_rand(void)
{
    return callbacks.rand();
}
