/*
 * Battleship, classic battleship game
 * Copyriht (C) 2014-2015 Pavel Dolov
 *
 * See the LICENSE file for terms of use.
 */

#include "Point.hpp"

Point::Point(int col, int row):
    col(col), row(row) {
}

Points::Points(Point p1, Point p2):
    p1(p1), p2(p2) {
}

bool Points::isHorizontal() const {
    if (p1.col == p2.col) {
        return true;
    } else {
        return false;
    }
}
