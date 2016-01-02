/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "GameDesk.hpp"

/* get global coordinate from horizontal and
   vertical coordinates
*/
static int getIndex(const Point& point, int width,
                    int length) {
    bool less = ((point.col < 0) || (point.row < 0));
    bool greater = ((point.col >= length) || (point.row >=
                    width));
    if (less || greater) {
        throw Exception("Model: index of cell in some "
                        "arguments of GameDesk's methods "
                        "is out of range.");
    }
    int index = point.col * width + point.row;
    return index;
}

GameDesk* GameDesk::make(int width, int length) {
    if ((width < MIN_WIDTH) || (width > MAX_WIDTH)) {
        throw Exception("width of desk is out of "
                        "allowable range");
    } else if ((length < MIN_LENGTH) || (length >
                                         MAX_LENGTH)) {
        throw Exception("length of desk is out of "
                        "allowable range");
    }
    GameDesk* desk = new GameDesk();
    int square = width * length;
    desk->player1_desk_.resize(square);
    desk->player2_desk_.resize(square);
    desk->width_ = width;
    desk->length_ = length;
    return desk;
}

void GameDesk::setCellState(const Point& point,
                            bool state,
                            int player_number) {
    int index = getIndex(point, width_, length_);
    if (player_number == 1) {
        player1_desk_[index].is_ship = state;
    } else if (player_number == 2) {
        player2_desk_[index].is_ship = state;
    } else {
        throw Exception("Received invalid player_number "
                        "argument in setCellState method "
                        "of GameDesk. It must be 1 or 2.");
    }
}

bool GameDesk::getCellState(const Point& point,
                            int player_number) const {
    int index = getIndex(point, width_, length_);
    if (player_number == 1) {
        return player1_desk_[index].is_ship;
    } else if (player_number == 2) {
        return player2_desk_[index].is_ship;
    } else {
        throw Exception("Received invalid player_number "
                        "argument in getCellState method "
                        "of GameDesk. It must be 1 or 2.");
    }
}

void GameDesk::setFlooding(const Point& point,
                           bool is_sunken,
                           int player_number) {
    int index = getIndex(point, width_, length_);
    if (player_number == 1) {
        player1_desk_[index].is_sunken_ship = is_sunken;
    } else if (player_number == 2) {
        player2_desk_[index].is_sunken_ship = is_sunken;
    } else {
        throw Exception("Received invalid player_number "
                        "argument in setFlooding method "
                        "of GameDesk. It must be 1 or 2.");
    }
}

bool GameDesk::getFlooding(const Point& point,
                           int player_number) const {
    int index = getIndex(point, width_, length_);
    if (player_number == 1) {
        return player1_desk_[index].is_sunken_ship;
    } else if (player_number == 2) {
        return player2_desk_[index].is_sunken_ship;
    } else {
        throw Exception("Received invalid player_number "
                        "argument in getFlooding method "
                        "of GameDesk. It must be 1 or 2.");
    }
}

void GameDesk::setVisibility(const Point& point,
                             bool is_visible,
                             int player_number) {
    int index = getIndex(point, width_, length_);
    if (player_number == 1) {
        player1_desk_[index].is_visible = is_visible;
    } else if (player_number == 2) {
        player2_desk_[index].is_visible = is_visible;
    } else {
        throw Exception("Received invalid player_number "
                        "argument in setVisibility method "
                        "of GameDesk. It must be 1 or 2.");
    }
}

bool GameDesk::getVisibility(const Point& point,
                             int player_number) const {
    int index = getIndex(point, width_, length_);
    if (player_number == 1) {
        return player1_desk_[index].is_visible;
    } else if (player_number == 2) {
        return player2_desk_[index].is_visible;
    } else {
        throw Exception("Received invalid player_number "
                        "argument in getVisibility method "
                        "of GameDesk. It must be 1 or 2.");
    }
}

int GameDesk::getWidth() const {
    return width_;
}

int GameDesk::getLength() const {
    return length_;
}

GameDesk::GameDesk() {
}
