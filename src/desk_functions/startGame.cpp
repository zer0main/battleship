/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "startGame.hpp"

QSharedPointer<Game> startGame(QObject* window,
                               int width, int length) {
    QSharedPointer<Game> game =
        QSharedPointer<Game>(new Game());
    game->desk = QSharedPointer<GameDesk>
                 (GameDesk::make(width, length));
    game->proxy1 = QSharedPointer<GameDeskProxy>
                   (GameDeskProxy::make(game
                                        ->desk.data(), 1));
    game->proxy2 = QSharedPointer<GameDeskProxy>
                   (GameDeskProxy::make(game
                                        ->desk.data(), 2));
    game->bot1 = QSharedPointer<Bot>
                 (Bot::make(game->proxy1.data(), 1));
    game->bot2 = QSharedPointer<Bot>
                 (Bot::make(game->proxy2.data(), 2));
    game->t_model1 = QSharedPointer<TableModel>
                     (new TableModel(window,
                                     game->proxy2.data(),
                                     false));
    game->t_model2 = QSharedPointer<TableModel>
                     (new TableModel(window,
                                     game->proxy2.data(),
                                     true));
    game->t_model3 = QSharedPointer<TableModel>
                     (new TableModel(window,
                                     game->proxy1.data(),
                                     false));
    game->t_model4 = QSharedPointer<TableModel>
                     (new TableModel(window,
                                     game->proxy1.data(),
                                     true));
    game->controller =
        QSharedPointer<GameController>
        (GameController::make(game->desk.data()));
    return game;
}
