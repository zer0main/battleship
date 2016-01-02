/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_CONTROLLER_HPP_
#define GAME_CONTROLLER_HPP_

#include "GameDesk.hpp"

/** Class to make and control moves.
*/
class GameController {
public:
    /** Create new instance.
    \param desk Model that will be changeable by
    GameController
    */
    static GameController* make(GameDesk* desk);

    /** Set the initial state of game board.
    (no ships, no visible cells, no sunken ships).
    */
    void initialStateOfBoard();

    /** Shoot at some cell of game board.
    \param player_number Defines who is shooting (1 or 2)
    \param point Specifies cell to being shot
    */
    void makeMove(int player_number, const Point& point);

    /** Set ship at the beginning of game.
    \param player_number Defines whose ship is setting
    (1 or 2)
    \param ship Specifies ship to set
    */
    void setShip(int player_number, const Ship& ship);

    /** Move ship at the beginning of game.
    \param payer_number Defines who wants to move (1 or 2)
    \param starting_position Specifies position of ship
    before move
    \param end_position Specifies position of ship after
    move
    */
    //void moveShip(int player_number,
    //              const Ship& starting_position,
    //              const Ship& end_position);

private:
    GameDesk* desk_;

    GameController();

    bool checkBurst(const Ship& ship,
                    int player_number) const;
};

#endif
