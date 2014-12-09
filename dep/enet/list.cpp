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

#define ENET_BUILDING_LIB 1
#include "list.h"

/**
    @defgroup list ENet linked list utility functions
    @ingroup private
    @{
*/
void enet_list_clear(ENetList* list)
{
    list->sentinel.next = &list->sentinel;
    list->sentinel.previous = & list->sentinel;
}

ENetListIterator enet_list_insert(ENetListIterator position, void* data)
{
    ENetListIterator result = (ENetListIterator)data;

    result->previous = position->previous;
    result->next = position;

    result->previous->next = result;
    position->previous = result;

    return result;
}

void* enet_list_remove(ENetListIterator position)
{
    position->previous->next = position->next;
    position->next->previous = position->previous;

    return position;
}

ENetListIterator enet_list_move(ENetListIterator position, void* dataFirst, void* dataLast)
{
    ENetListIterator first = (ENetListIterator)dataFirst, last = (ENetListIterator)dataLast;

    first->previous->next = last->next;
    last->next->previous = first->previous;

    first->previous = position->previous;
    last->next = position;

    first->previous->next = first;
    position->previous = last;

    return first;
}

size_t enet_list_size(ENetList* list)
{
    size_t size = 0;
    ENetListIterator position;

    for (position = enet_list_begin(list); position != enet_list_end(list); position = enet_list_next(position))
        ++ size;

    return size;
}

/** @} */
