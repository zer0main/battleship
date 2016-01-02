/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GET_SHIP_COORDINATES_HPP_
#define GET_SHIP_COORDINATES_HPP_

#include "Point.hpp"
#include "Exception.hpp"

// This function is static.
// Retunrns true if the neighbor is ship's item.
// Save neighbor's coordinate to p.
template<typename T>
bool nextNeighbor(const T& desk, Point& p,
                  int player_number, bool direction) {
    Point p_saver = p;
    if (direction) {
        if (p.row != desk.getWidth() - 1) {
            p.row += 1;
            if (desk.getCellState(p, player_number)) {
                return true;
            }
        }
        p = p_saver;
        if (p.col != desk.getLength() - 1) {
            p.col += 1;
            if (desk.getCellState(p, player_number)) {
                return true;
            }
        }
        p = p_saver;
    } else {
        if (p.row != 0) {
            p.row -= 1;
            if (desk.getCellState(p, player_number)) {
                return true;
            }
        }
        p = p_saver;
        if (p.col != 0) {
            p.col -= 1;
            if (desk.getCellState(p, player_number)) {
                return true;
            }
        }
        p = p_saver;
    }
    return false;
}

/** Get coordinates of ship. */
template<typename T>
Ship getShipCoordinates(const T& desk, const Point& p,
                        int player_number) {
    if (!desk.getCellState(p, player_number)) {
        throw Exception("No possibility to get "
                        "coordinates of nonexistent "
                        "ship");
    }
    Ship out(p, p);
    while (nextNeighbor<T>(desk, out.p1, player_number,
                           false)) {
    }
    while (nextNeighbor<T>(desk, out.p2, player_number,
                           true)) {
    }
    return out;
}

#endif
