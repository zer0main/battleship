/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

/** Waiting time between moves (msec) */
const int MOVE_WAIT = 3000;

/** Minimum width of game board */
const int MIN_WIDTH = 11;

/** Maximum width of game board */
const int MAX_WIDTH = 16;

/** Minimum height of game board */
const int MIN_LENGTH = 11;

/** Maximum height of game board */
const int MAX_LENGTH = 16;

/** Maximum allowable length of ship */
const int MAX_SHIP_LENGTH = 5;

/** Mimimum allowable length of ship */
const int MIN_SHIP_LENGTH = 2;

/** Total number of ship items in the game board */
const int SHIP_ITEMS = 30;

#endif
