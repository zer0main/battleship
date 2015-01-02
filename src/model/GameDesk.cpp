/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "GameDesk.hpp"

void GameDesk::setCellState(const Point& point,
        bool state, bool player) {
    /* get global coordinate from horizontal and
       vertical coordinates
    */
    int global_coordinate = point.col * width_ + point.row;
    if (player) {
        players_desk_[global_coordinate].is_ship = state;
    } else {
        enemys_desk_[global_coordinate].is_ship = state;
    }
}

bool GameDesk::getCellState(const Point& point,
        bool player) const {
    if (player) {
        return players_desk_[point.col * width_
            + point.row].is_ship;
    } else {
        return enemys_desk_[point.col * width_
            + point.row].is_ship;
    }
}

void GameDesk::setVisibility(const Point& point, bool
        state, bool player) {
    int global_coordinate = point.col * width_ + point.row;
    if (player) {
        players_desk_[global_coordinate].is_visible =
            state;
    } else {
        enemys_desk_[global_coordinate].is_visible = state;
    }
}

void GameDesk::resize(int width, int length) {
    int square = width * length;
    players_desk_.resize(square);
    enemys_desk_.resize(square);
    width_ = width;
    length_ = length;
}

int GameDesk::getWidth() const {
    return width_;
}

int GameDesk::getLength() const {
    return length_;
}
