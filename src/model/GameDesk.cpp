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
                            bool state,
                            int player_number) {
    int index = getIndex(point, width_);
    if (player_number == 1) {
        player1_desk_[index].is_ship = state;
    } else if (player_number == 2) {
        player2_desk_[index].is_ship = state;
    } else {
        throw Exception("Invalid player number. It must "
                        "be 1 or 2");
    }
}

bool GameDesk::getCellState(const Point& point,
                            int player_number) const {
    int index = getIndex(point, width_);
    if (player_number == 1) {
        return player1_desk_[index].is_ship;
    } else if (player_number == 2) {
        return player2_desk_[index].is_ship;
    } else {
        throw Exception("Invalid player number. It must "
                        "be 1 or 2");
    }
}

void GameDesk::setFlooding(const Point& point,
                           bool is_sunken,
                           int player_number) {
    int index = getIndex(point, width_);
    if (player_number == 1) {
        player1_desk_[index].is_sunken_ship = is_sunken;
    } else if (player_number == 2) {
        player2_desk_[index].is_sunken_ship = is_sunken;
    } else {
        throw Exception("Invalid player number. It must "
                        "be 1 or 2");
    }
}

bool GameDesk::getFlooding(const Point& point,
                           int player_number) const {
    int index = getIndex(point, width_);
    if (player_number == 1) {
        return player1_desk_[index].is_sunken_ship;
    } else if (player_number == 2) {
        return player2_desk_[index].is_sunken_ship;
    } else {
        throw Exception("Invalid player number. It must "
                        "be 1 or 2");
    }
}

void GameDesk::setVisibility(const Point& point,
                             bool is_visible,
                             int player_number) {
    int index = getIndex(point, width_);
    if (player_number == 1) {
        player1_desk_[index].is_visible = is_visible;
    } else if (player_number == 2) {
        player2_desk_[index].is_visible = is_visible;
    } else {
        throw Exception("Invalid player number. It must "
                        "be 1 or 2");
    }
}

bool GameDesk::getVisibility(const Point& point,
                             int player_number) const {
    int index = getIndex(point, width_);
    if (player_number == 1) {
        return player1_desk_[index].is_visible;
    } else if (player_number == 2) {
        return player2_desk_[index].is_visible;
    } else {
        throw Exception("Invalid player number. It must "
                        "be 1 or 2");
    }
}

void GameDesk::resize(int width, int length) {
    int square = width * length;
    player1_desk_.resize(square);
    player2_desk_.resize(square);
    width_ = width;
    length_ = length;
}

int GameDesk::getWidth() const {
    return width_;
}

int GameDesk::getLength() const {
    return length_;
}
