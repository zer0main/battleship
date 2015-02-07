/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "GameDeskProxy.hpp"

GameDeskProxy::GameDeskProxy(const GameDesk* desk,
                             int player_number):
    desk_(desk),
    player_number_(player_number) {
}
