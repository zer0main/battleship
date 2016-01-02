/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef SPACE_FOR_SHIP_HPP_
#define SPACE_FOR_SHIP_HPP_

#include "Exception.hpp"
#include "Point.hpp"

// This function is static.
// Returns number of ship's items among the neighbors of
// p.
template<typename T>
int shipItemsNumber(const T& desk, const Point& p,
                    int player_number) {
    int number = 0;
    int correct_cells_number = 0;
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
            Point pt(j, i);
            correct_cells_number++;
            if (desk.getCellState(pt, player_number)) {
                number++;
            }
        }
    }
    if (correct_cells_number < 4) {
        number = 1;
    }
    return number;
}

/** Check that new ship may be located in this cells.
Cells specified in ship argument.
*/
template<typename T>
void spaceForShip(const T& desk, const Ship& ship,
                  int player_number) {
    int beginning = (ship.isHorizontal()) ? ship.p1.row :
                    ship.p1.col;
    int end = (ship.isHorizontal()) ? ship.p2.row :
              ship.p2.col;
    for (int i = beginning; i <= end; i++) {
        int col = (ship.isHorizontal()) ? ship.p1.col : i;
        int row = (ship.isHorizontal()) ? i : ship.p1.row;
        Point pt(col, row);
        int n = shipItemsNumber<T>(desk, pt,
                                   player_number);
        if (n != 0) {
            throw Exception("No space for this ship");
        }
    }
}

#endif
