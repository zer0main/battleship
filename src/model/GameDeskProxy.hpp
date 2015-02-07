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

    /** Get state of cell specified in Point structure.
    \param player_number Defines player(1 or 2) on
    whose territory current cell is situated
    */
    bool getCellState(const Point& point,
                      int player_number) const;

    /** Returns true if sunken ship (or part of sunken
    ship) situated in cell specified in Point structure.
    \param player_number Defines player(1 or 2) on
    whose territory current cell is situated
    */
    bool getFlooding(const Point& point,
                     int player_number) const;

    /** Get visibility of cell specified in Point
    structure.
    \param player_number Defines player(1 or 2) on
    whose territory current cell is situated
    */
    bool getVisibility(const Point& point,
                       int player_number) const;

    /** Get width of game board */
    int getWidth() const;

    /** Get length of game board */
    int getLength() const;

private:
    const GameDesk* desk_;

    /** Number of player which will be restricted by Proxy
    */
    int player_number;
};

#endif
