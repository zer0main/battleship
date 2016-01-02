/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_DESK_HPP_
#define GAME_DESK_HPP_

#include <vector>

#include "constants.hpp"
#include "Exception.hpp"
#include "Point.hpp"
#include "Cell.hpp"

/** Main model class. Use to save game board's state.
*/
class GameDesk {
public:
    /** Create new instance.
    \param width Width of game board
    \param length Length of game board
    */
    static GameDesk* make(int width, int length);

    /** Set state of cell specified in Point structure.
    \param player_number Defines player(1 or 2) on
    whose territory current cell is situated
    */
    void setCellState(const Point& point, bool state,
                      int player_number);

    /** Get state of cell specified in Point structure.
    \param player_number Defines player(1 or 2) on
    whose territory current cell is situated
    */
    bool getCellState(const Point& point,
                      int player_number) const;

    /** Set flooding of ship.
    \param is_sunken Must be true if sunken
    ship/part of sunken ship must be situated in cell
    specified in Point structure.
    \param player_number Defines player(1 or 2) on
    whose territory current cell is situated
    */
    void setFlooding(const Point& point, bool is_sunken,
                     int player_number);

    /** Returns true if sunken ship (or part of sunken
    ship) situated in cell specified in Point structure.
    \param player_number Defines player(1 or 2) on
    whose territory current cell is situated
    */
    bool getFlooding(const Point& point,
                     int player_number) const;

    /** Set visibility of cell specified in Point
    structure.
    \param player_number Defines player(1 or 2) on
    whose territory current cell is situated
    */
    void setVisibility(const Point& point, bool is_visible,
                       int player_number);

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
    /* Vector player1_desk_ contains all player1's cells
    (which situated on player1's territory)
    */
    std::vector<Cell> player1_desk_;

    /* Vector player2_desk_ contains all player2's cells
    (which situated on player2's territory)
    */
    std::vector<Cell> player2_desk_;

    int width_;
    int length_;

    GameDesk();
};

#endif
