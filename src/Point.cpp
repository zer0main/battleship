/*
 * Battleship, classic battleship game
 * Copyriht (C) 2014-2015 Pavel Dolov
 *
 * See the LICENSE file for terms of use.
 */

#include "Point.hpp"

bool Points::isHorizontal() const {
    if (p1.col == p2.col) {
        return true;
    } else {
        return false;
    }
}
