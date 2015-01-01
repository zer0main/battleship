/*
 * Battleship, classic battleship game
 * Copyright (C) 2014 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_DESK_HPP_
#define GAME_DESK_HPP_

#include <vector>

#include "Point.hpp"
#include "Cell.hpp"

/** Main model class. Use to save game board's state.
*/
class GameDesk {
public:
    /** Set state of cell specified in Point structure.
    \boolean variable player is true if cell belongs to
    player (situated on player's territory)
    */
    void setCellState(const Point& point, bool state,
            bool player);

    /** Get state of cell specified in Point structure.
    \boolean variable player is true if cell belongs to
    player (situated on enemy's territory)
    */
    bool getCellState(const Point& point, bool
            player) const;

    /** Resize desk_ vector */
    void resize(int width, int length);

    /** Get width of game board */
    int getWidth() const;

    /** Get length of game board */
    int getLength() const;

private:
    /** Vector players_desk_ contains states of all
    player's cells (which situated on player's territory)
    */
    std::vector<Cell> players_desk_;
    /** Vector enemys_desk_ contains states of all
    enemy's cells (which situated on enemy's territory)
    */
    std::vector<Cell> enemys_desk_;
    int width_;
    int length_;
};

#endif
