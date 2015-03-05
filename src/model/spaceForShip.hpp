/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef SPACE_FOR_SHIP_HPP_
#define SPACE_FOR_SHIP_HPP_

#include "Point.hpp"

// This function is static.
// Returns number of ship's items among the neighbors of
// p.
template<typename T>
int shipItemsNumber(const T& desk, const Point& p,
                    int player_number) {
    int number = 0;
    for (int i = p.row - 1; i <= p.row + 1; i++) {
        if (i < 0) {
            continue;
        } else if (i >= desk.getWidth()) {
            break;
        }
        for (int j = p.col - 1; j <= p.col + 1; j++) {
            if (j < 0) {
                continue;
            } else if (j >= desk.getLength()) {
                break;
            }
            Point pt;
            pt.row = i;
            pt.col = j;
            if (desk.getCellState(pt, player_number)) {
                number++;
            }
        }
    }
    return number;
}

/** Check that new ship may be located in this cells.
Cells specified in ship argument.
*/
template<typename T>
bool spaceForShip(const T& desk, const Points& ship,
                  int player_number) {
    int beginning = (ship.is_horizontal) ? ship.p1.row :
                    ship.p1.col;
    int end = (ship.is_horizontal) ? ship.p2.row :
              ship.p2.col;
    for (int i = beginning; i <= end; i++) {
        Point pt;
        pt.col = (ship.is_horizontal) ? ship.p1.col : i;
        pt.row = (ship.is_horizontal) ? i : ship.p1.row;
        int n = shipItemsNumber<T>(desk, pt,
                                   player_number);
        if (n != 0) {
            return false;
        }
    }
    return true;
}

#endif
