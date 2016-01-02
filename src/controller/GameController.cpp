/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "GameController.hpp"
#include "getShipCoordinates.hpp"
#include "spaceForShip.hpp"

static int getEnemysNumber(int player_number) {
    return 3 - player_number;
}

GameController* GameController::make(GameDesk* desk) {
    if (desk == NULL) {
        throw Exception("Received NULL pointer to "
                        "GameDesk when try to create "
                        "GameController");
    }
    GameController* controller = new GameController();
    controller->desk_ = desk;
    return controller;
}

void GameController::initialStateOfBoard() {
    for (int i = 0; i < desk_->getLength(); i++) {
        for (int x = 0; x < desk_->getWidth(); x++) {
            Point pt(i, x);
            desk_->setCellState(pt, false, 1);
            desk_->setCellState(pt, false, 2);
            desk_->setFlooding(pt, false, 1);
            desk_->setFlooding(pt, false, 2);
            desk_->setVisibility(pt, false, 1);
            desk_->setVisibility(pt, false, 2);
        }
    }
}

void GameController::makeMove(int player_number,
                              const Point& point) {
    int enemy = getEnemysNumber(player_number);
    if (desk_->getVisibility(point, enemy)) {
        throw Exception("Some of players wants to shoot "
                        "at cell which has already shot "
                        "down");
    }
    desk_->setVisibility(point, true, enemy);
    if (desk_->getCellState(point, enemy)) {
        Ship ship = getShipCoordinates(*desk_, point,
                                        enemy);
        if (checkBurst(ship, enemy)) {
            int beginning = (ship.isHorizontal()) ?
                            ship.p1.row : ship.p1.col;
            int end = (ship.isHorizontal()) ?
                      ship.p2.row : ship.p2.col;
            for (int i = beginning; i <= end; i++) {
                int col = (ship.isHorizontal()) ?
                          ship.p1.col : i;
                int row = (ship.isHorizontal()) ? i :
                          ship.p1.row;
                Point pt(col, row);
                desk_->setFlooding(pt, true, enemy);
            }
        }
    }
}

void GameController::setShip(int player_number,
                             const Ship& ship) {
    try {
        spaceForShip(*desk_, ship, player_number);
    } catch (...) {
        throw Exception("Can't set ship in cells with "
                        "this location");
    }
    int beginning = (ship.isHorizontal()) ?
                        ship.p1.row : ship.p1.col;
    int end = (ship.isHorizontal()) ?
                  ship.p2.row : ship.p2.col;
    for (int i = beginning; i <= end; i++) {
        int col = (ship.isHorizontal()) ?
                  ship.p1.col : i;
        int row = (ship.isHorizontal()) ? i :
                  ship.p1.row;
        Point pt(col, row);
        desk_->setCellState(pt, true, player_number);
    }
}

GameController::GameController() {
}

bool GameController::checkBurst(const Ship& ship,
                                int player_number) const {
    int beginning = (ship.isHorizontal()) ? ship.p1.row :
                    ship.p1.col;
    int end = (ship.isHorizontal()) ? ship.p2.row :
              ship.p2.col;
    for (int i = beginning; i <= end; i++) {
        int col = (ship.isHorizontal()) ? ship.p1.col : i;
        int row = (ship.isHorizontal()) ? i : ship.p1.row;
        Point pt(col, row);
        if (!desk_->getVisibility(pt, player_number)) {
            return false;
        }
    }
    return true;
}
