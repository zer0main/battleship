/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef CHECK_WIN_HPP_
#define CHECK_WIN_HPP_

#include "constants.hpp"
#include "Point.hpp"

/** Check that one of players won.
\param desk Game board
\param player Number of player (1, 2) who checked for win
*/
template<typename T>
bool checkWin(const T& desk, int player) {
    // Enemy's number
    int en = 3 - player;
    int blasted = 0;
    for (int i = 0; i < desk.getLength(); i++) {
        for (int x = 0; x < desk.getWidth(); x++) {
            Point pt(i, x);
            if (desk.getVisibility(pt, en)) {
                if (desk.getCellState(pt, en)) {
                    blasted++;
                }
            }
        }
    }
    return (blasted == SHIP_ITEMS);
}

#endif
