/*
 * Battleship, classic battleship game
 * Copyright (C) 2014 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_DESK_HPP_
#define GAME_DESK_HPP_

#include <vector>

/** Main model class. Use to save game board's state.
*/
class GameDesk {
public:
    /** Set state of cell specified in Point structure */
    void setCellState(const Point& point, bool state);

    /** Get state of cell specified in Point structure */
    bool getCellState(const Point& point) const;

    /** Resize desk_ vector */
    void resize(int width, int length);

    /** Get width of game board */
    int getWidth() const;

    /** Get length of game board */
    int getLength() const;

private:
    /** Vector desk_ contains states of all cells */
    std::vector<bool> desk_;
    int width_;
    int length_;
};

#endif
