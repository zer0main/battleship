/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "GameController.hpp"
#include "Bot.hpp"
#include "GameDeskProxy.hpp"
#include "TableModel.hpp"

/** Contains all classes necessary for game */
struct Game {
    QSharedPointer<GameDesk> desk;
    QSharedPointer<GameDeskProxy> proxy1;
    QSharedPointer<GameDeskProxy> proxy2;
    QSharedPointer<Bot> bot1;
    QSharedPointer<Bot> bot2;
    QSharedPointer<TableModel> t_model1;
    QSharedPointer<TableModel> t_model2;
    QSharedPointer<TableModel> t_model3;
    QSharedPointer<TableModel> t_model4;
    QSharedPointer<GameController> controller;
};

#endif
