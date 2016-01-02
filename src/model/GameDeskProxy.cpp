/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "GameDeskProxy.hpp"

GameDeskProxy::GameDeskProxy() {
}

GameDeskProxy* GameDeskProxy::make(const GameDesk* desk,
                                   int player_number) {
    if ((player_number != 1) && (player_number != 2)) {
        throw Exception("Invalid payer number when try to "
                        "create GameDeskProxy");
    } else if (desk == NULL) {
        throw Exception("Received NULL pointer to "
                        "GameDesk when try to create "
                        "GameDeskProxy");
    } else {
        GameDeskProxy* proxy = new GameDeskProxy();
        proxy->desk_ = desk;
        proxy->player_number_ = player_number;
        return proxy;
    }
}

bool GameDeskProxy::getCellState(const Point& point,
                                 int player_number) const {
    if (player_number == player_number_) {
        return desk_->getCellState(point, player_number);
    } else if (desk_->getVisibility(point,
                                    player_number)) {
        return desk_->getCellState(point, player_number);
    } else {
        throw Exception("Player tries to get state of "
                        "cell that is not visible for "
                        "him.");
    }
}

bool GameDeskProxy::getFlooding(const Point& point,
                                int player_number) const {
    return desk_->getFlooding(point, player_number);
}

bool GameDeskProxy::getVisibility(const Point& point,
                                  int player_number) const
{
    return desk_->getVisibility(point, player_number);
}

int GameDeskProxy::getWidth() const {
    return desk_->getWidth();
}

int GameDeskProxy::getLength() const {
    return desk_->getLength();
}

int GameDeskProxy::getPlayerNumber() const {
    return player_number_;
}
