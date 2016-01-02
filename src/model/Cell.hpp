/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef CELL_HPP_
#define CELL_HPP_

/** Structure Cell contains all information about cell.
*/
struct Cell {
    /** is_ship is true if ship/part of ship situated in
    this cell
    */
    bool is_ship;

    /** is_sunken_ship is true if sunken ship/part of sunken
    ship situated in this cell
    */
    bool is_sunken_ship;

    /** is_visible is true if enemy can see what is
    situated in this cell
    */
    bool is_visible;
};

#endif
