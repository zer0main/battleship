/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef POINT_HPP_
#define POINT_HPP_

/** Structure Point contains cell coordinates.
*/
struct Point {
    /** Constructor */
    Point(int col, int row);

    /** Vertical coordinate */
    int col;

    /** Horizontal coordinate */
    int row;
};

/** Structure Ship contains 2 Point structuries.
Use to specify coordinate of the beginning of ship (p1) and
coordinate of the end of ship (p2).
*/
struct Ship {
    /** Constructor */
    Ship(Point p1, Point p2);

    /** Beginning of ship */
    Point p1;

    /** End of ship */
    Point p2;

    /** Get direction of ship. True if it is horizontal */
    bool isHorizontal() const;
};

#endif
