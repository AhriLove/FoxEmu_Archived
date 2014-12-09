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

#ifndef __ENET_LIST_H__
#define __ENET_LIST_H__

#include <stdlib.h>

typedef struct _ENetListNode
{
	struct _ENetListNode* next;
	struct _ENetListNode* previous;
} ENetListNode;

typedef ENetListNode* ENetListIterator;

typedef struct _ENetList
{
	ENetListNode sentinel;
} ENetList;

extern void enet_list_clear(ENetList*);

extern ENetListIterator enet_list_insert(ENetListIterator, void*);
extern void* enet_list_remove(ENetListIterator);
extern ENetListIterator enet_list_move(ENetListIterator, void*, void*);

extern size_t enet_list_size (ENetList*);

#define enet_list_begin(list) ((list)->sentinel.next)
#define enet_list_end(list) (&(list)->sentinel)

#define enet_list_empty(list) (enet_list_begin(list) == enet_list_end(list))

#define enet_list_next(iterator) ((iterator)->next)
#define enet_list_previous(iterator) ((iterator)->previous)

#define enet_list_front(list) ((void*)(list)->sentinel.next)
#define enet_list_back(list) ((void*)(list)->sentinel.previous)

#endif /* __ENET_LIST_H__ */
