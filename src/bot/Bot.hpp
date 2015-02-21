/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef BOT_HPP_
#define BOT_HPP_

#include "GameDeskProxy.hpp"

/** Bot class contains all bot logic.
*/
class Bot {
public:
    /** Set pointer to model class GameDeskProxy
    */
    void setDesk(const GameDeskProxy* desk);

    /** This method returns Point structure which contains
    coordinates of cell that bot wants to shoot
    */
    Point getIndex() const;

private:
    const GameDeskProxy* desk_;

    int bot_number_;

    /* This method returns true if bot wants cell with
    coordinates described in point to shoot.
    This method will be called from getIndex function.
    */
    bool checkCoordinate(const Point& point) const;

    /* Check that cell with coordinates described in
    point hasn't sunken ships near itself or burning
    ships diagonally.
    */
    bool checkNeighboringCells(const Point& point) const;

    /* Check that the current state of the board allows
    to make a move.
    */
    bool thereAreMoves() const;
};

#endif
