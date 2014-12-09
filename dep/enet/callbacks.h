/*
 * Copyright (C) 2014 FoxEmu <http://www.foxemu.ovh/>
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

#ifndef __ENET_CALLBACKS_H__
#define __ENET_CALLBACKS_H__

#include <stdlib.h>

typedef struct _ENetCallbacks
{
    void* (ENET_CALLBACK * malloc) (size_t size);
    void  (ENET_CALLBACK * free) (void * memory);
    int   (ENET_CALLBACK * rand) (void);
    void  (ENET_CALLBACK * no_memory) (void);
} ENetCallbacks;

/** @defgroup callbacks ENet internal callbacks
    @{
    @ingroup private
*/
extern void* enet_malloc (size_t);
extern void  enet_free (void *);
extern int   enet_rand (void);

/** @} */

#endif /* __ENET_CALLBACKS_H__ */
