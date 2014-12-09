/*
 * Copyright (C) 2014 FoxEmu <http://www.foxemu.ovh/>
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

#ifndef _OPCODES_H
#define _OPCODES_H

enum Opcodes
{
    // Client
    CMSG_ATTENTION_PING                               = 0x57,
    CMSG_AUTOATTACK_OPTION                            = 0x47,
    CMSG_BUY_ITEM_REQ                                 = 0x82,
    CMSG_CAST_SPELL                                   = 0x9A,
    CMSG_CHAR_LOADED                                  = 0xBE,
    CMSG_CLICK                                        = 0xAF,
    CMSG_CLIENT_READY                                 = 0x64,
    CMSG_EMOTION                                      = 0x48,
    CMSG_EXIT                                         = 0x8F,
    CMSG_HEART_BEAT                                   = 0x08,
    CMSG_MOVE_CONFIRM                                 = 0x77,
    CMSG_MOVE_REQ                                     = 0x72,
    CMSG_LOCK_CAMERA                                  = 0x81,
    CMSG_PING_LOAD_INFO                               = 0x16,
    CMSG_QUERY_STATUS_REQ                             = 0x14,
    CMSG_SCORE_BOARD                                  = 0x56,
    CMSG_SELL_ITEM                                    = 0x09,
    CMSG_SKILL_UP                                     = 0x39,
    CMSG_START_GAME                                   = 0x52,
    CMSG_STATS_CONFIRM                                = 0xA8,
    CMSG_SURRENDER                                    = 0xA4,
    CMSG_SWAP_ITEMS                                   = 0x20,
    CMSG_SYNCH_VERSION                                = 0xBD,
    CMSG_VIEW_REQ                                     = 0x2E,

    // Global
    MSG_BATCH                                         = 0xFF,
    MSG_CHAT_BOX_MESSAGE                              = 0x68,
    MSG_KEYCHECK                                      = 0x00,
    MSG_SEND_GAME_NUMBER                              = 0x92,

    // Server
    SMSG_ADD_BUFF                                     = 0xB7,
    SMSG_ADD_GOLD                                     = 0x22,
    SMSG_ANNOUNCE                                     = 0x45,
    SMSG_ATTENTION_PING                               = 0x40,
    SMSG_BEGIN_AUTO_ATTACK                            = 0x1A,
    SMSG_BUY_ITEM_ANS                                 = 0x6F,
    SMSG_CAST_SPELL_ANS                               = 0xB5,
    SMSG_CHAMPION_DIE                                 = 0x5E,
    SMSG_CHAMPION_RESPAWN                             = 0x2F,
    SMSG_CHAR_STATS                                   = 0xC4,
    SMSG_DAMAGE_DONE                                  = 0x65,
    SMSG_DASH                                         = 0x64,
    SMSG_DEBUG_MESSAGE                                = 0xF7,
    SMSG_DELETE_OBJECT                                = 0x35,
    SMSG_DESTROY_PROJECTILE                           = 0x5A,
    SMSG_EDIT_BUFF                                    = 0x1C,
    SMSG_EMOTION                                      = 0x42,
    SMSG_END_SPAWN                                    = 0x11,
    SMSG_EXTENDED                                     = 0xFE,
    SMSG_FACE_DIRECTION                               = 0x50,
    SMSG_FOG_UPDATE2                                  = 0x23,
    SMSG_GAME_TIMER                                   = 0xC1,
    SMSG_GAME_TIMER_UPDATE                            = 0xC2,
    SMSG_HERO_SPAWN                                   = 0x4C,
    SMSG_LEAVE_VISION                                 = 0x51,
    SMSG_LEVEL_PROP_SPAWN                             = 0xD0,
    SMSG_LEVEL_UP                                     = 0x3F,
    SMSG_LOAD_HERO                                    = 0x65,
    SMSG_LOAD_NAME                                    = 0x66,
    SMSG_LOAD_SCREEN_INFO                             = 0x67,
    SMSG_NEXT_AUTO_ATTACK                             = 0x0C,
    SMSG_NPC_HIDE                                     = 0x9E,
    SMSG_OBJECT_SPAWN                                 = 0xBA,
    SMSG_PING_LOAD_INFO                               = 0x95,
    SMSG_PLAYER_INFO                                  = 0x2A,
    SMSG_QUERY_STATUS_ANS                             = 0x88,
    SMSG_REMOVE_BUFF                                  = 0x7B,
    SMSG_REMOVE_ITEM                                  = 0x0B,
    SMSG_SET_ANIMATION                                = 0xB6,
    SMSG_SET_COOLDOWN                                 = 0x85,
    SMSG_SET_HEALTH                                   = 0xAE,
    SMSG_SET_TARGET                                   = 0x6A,
    SMSG_SET_TARGET2                                  = 0xC0,
    SMSG_SHOW_PROJECTILE                              = 0x6E,
    SMSG_SKILL_UP                                     = 0x15,
    SMSG_SPAWN_PARTICLE                               = 0x87,
    SMSG_SPAWN_PROJECTILE                             = 0x3B,
    SMSG_SPELL_ANIMATION                              = 0xB0,
    SMSG_START_GAME                                   = 0x5C,
    SMSG_START_SPAWN                                  = 0x62,
    SMSG_STOP_AUTO_ATTACK                             = 0x43,
    SMSG_SWAP_ITEMS                                   = 0x3E,
    SMSG_SYNCH_VERSION                                = 0x54,
    SMSG_TURRET_SPAWN                                 = 0x9D,
    SMSG_VIEW_ANS                                     = 0x2C,
};

#endif
/// @}
