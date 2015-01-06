/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "GameDesk.hpp"

/* get global coordinate from horizontal and
   vertical coordinates
*/
static int getIndex(const Point& point, int width) {
    int index = point.col * width + point.row;
    return index;
}

void GameDesk::setCellState(const Point& point,
                            bool state, bool player) {
    int index = getIndex(point, width_);
    if (player) {
        players_desk_[index].is_ship = state;
    } else {
        enemys_desk_[index].is_ship = state;
    }
}

bool GameDesk::getCellState(const Point& point,
                            bool player) const {
    int index = getIndex(point, width_);
    if (player) {
        return players_desk_[index].is_ship;
    } else {
        return enemys_desk_[index].is_ship;
    }
}

void GameDesk::setVisibility(const Point& point, bool
                             state, bool player) {
    int index = getIndex(point, width_);
    if (player) {
        players_desk_[index].is_visible = state;
    } else {
        enemys_desk_[index].is_visible = state;
    }
}

bool GameDesk::getVisibility(const Point& point,
                             bool player) const {
    int index = getIndex(point, width_);
    if (player) {
        return players_desk_[index].is_visible;
    } else {
        return enemys_desk_[index].is_visible;
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
