/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef BOT_HPP_
#define BOT_HPP_

#include <vector>

#include "GameDeskProxy.hpp"

/** Bot class contains all bot logic.
*/
class Bot {
public:
    /** Create new instance.
    \param desk Proxy and source of data for Bot
    \param bot_number Number of player for Bot (1, 2)
    */
    static Bot* make(const GameDeskProxy* desk,
                     int bot_number);

    /** This method returns Point structure which contains
    coordinates of cell that bot wants to shoot
    */
    Point getIndex() const;

private:
    const GameDeskProxy* desk_;

    int bot_number_;

    /* This method returns true if bot wants cell with
    coordinates described in point to shoot.
    This method will be called from getIndex function.
    */
    bool checkCoordinate(const Point& point) const;

    /* Check that cell with coordinates described in
    point hasn't sunken ships near itself or burning
    ships diagonally.
    */
    bool checkNeighboringCells(const Point& point) const;

    /* Get random cell which isn't visible and which
       hasn't sunken ship near itself.
    */
    Point randomRationalCell() const;

    /* This method returns true if cell with coordinates
       described in point argument is visible or if it has
       sunken ships near itself or burning ships
       diagonally.
    */
    bool visibleOrSunksNeighbor(const Point& point) const;

    std::vector<int> evaluateCells(const std::vector
                                   <Point>& cells) const;

    int evaluateCell(const Point& point) const;

    /* This method returns Point structure which contains
       coordinates of the neighboring (for cell with
       coordinates specified in argument) burning cell.
       It throws Exception if there is no neighboring
       burning cell for this argument.
    */
    Point neighboringBurningCell(const Point& point) const;

    Point theBestCell(const std::vector<Point>&
                      cells) const;

    Bot();
};

#endif
