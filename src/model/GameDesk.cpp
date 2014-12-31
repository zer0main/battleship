/*
 * Battleship, classic battleship game
 * Copyright (C) 2014 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "GameDesk.hpp"

void GameDesk::setCellState(const Point& point, bool state) {
    /* get global coordinate from horizontal and
       vertical coordinates
    */
    desk_[point.col * width + point.row] = state;
}

bool GameDesk::getCellState(const Point& point) const {
    return desk_[point.col * width + point.row];
}

void GameDesk::resize(int width, int length) {
    int square = width * length;
    desk_.resize(square);
    width_ = width;
    length_ = length;
}

int GameDesk::getWidth() const {
    return width_;
}

int GameDesk::getLength() const {
    return length_;
}
