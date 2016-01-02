/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef START_GAME_HPP_
#define START_GAME_HPP_

#include "Game.hpp"

/** Create all objects necessary for every type of game.
\param window MainWindow
\param width Width of game board
\param length Length of game board
*/
QSharedPointer<Game> startGame(QObject* window,
                               int width, int length);

#endif
