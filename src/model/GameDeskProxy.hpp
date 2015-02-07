/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_DESK_PROXY_HPP_
#define GAME_DESK_PROXY_HPP_

#include "GameDesk.hpp"

/** Proxy class for GameDesk.
Restricts access to data available to 1 of players.
*/
class GameDeskProxy {
public:
    /** Constructor.
    \param desk Source of data for proxy
    \param player_number Player number (1, 2)
    */
    GameDeskProxy(const GameDesk* desk, int player_number);

private:
    const GameDesk* desk_;

    /** Number of player which will be restricted by Proxy
    */
    int player_number;
};

#endif
