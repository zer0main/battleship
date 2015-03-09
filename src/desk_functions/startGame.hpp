/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef START_GAME_HPP_
#define START_GAME_HPP_

#include "Game.hpp"

QSharedPointer<Game> startGame(QObject* window,
                               int width, int length);

#endif
