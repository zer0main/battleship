/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "GameController.hpp"
#include "Bot.hpp"
#include "GameDeskProxy.hpp"
#include "TableModel.h"

/** Contains all classes necessary for game */
struct Game {
    GameDesk* desk;
    GameDeskProxy* proxy1;
    GameDeskProxy* proxy2;
    Bot* bot1;
    Bot* bot2;
    TableModel* t_model1;
    TableModel* t_model2;
    TableModel* t_model3;
    TableModel* t_model4;
    GameController* controller;
};

#endif
