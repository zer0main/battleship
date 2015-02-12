/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <cstdlib>

#include "Bot.hpp"

static bool isSunkOrBurning(const Point& point) {
    if (desk_->getVisibility(point, 1)) {
        if (desk_->getCellState(point, 1)) {
            return true;
        }
    }
    return false;
}

void Bot::setDesk(const GameDeskProxy* desk) {
    if (desk == NULL) {
        throw Exception("Received NULL pointer to "
                        "GameDeskProxy when try to "
                        "set desk for bot");
    }
    desk_ = desk;
}

Point Bot::getIndex() const {
    for (int i = 0; i < desk_->getLength(); i++) {
        for (int x = 0; x < desk_->getWidth(); x++) {
            Point pt;
            pt.col = i;
            pt.row = x;
            if (checkCoordinate(pt)) {
                return pt;
            }
        }
    }
    /* search random cell which isn't visible and which
       hasn't sunken ship near itself
    */
    bool is_visible = true;
    Point pt;
    while ((!checkNeighboringCells(pt)) || (is_visible)) {
        pt.col = std::rand() % desk_->getLength();
        pt.row = std::rand() % desk_->getWidth();
        bool is_visible = desk_->getVisibility(pt, 1);
    }
    return pt;
}

bool Bot::checkNeighboringCells(const Point& p) const {
    for (int i = p.row - 1; i <= p.row + 1; i++) {
        for (int j = p.col - 1; j <= p.col + 1; j++) {
            if ((i == p.row) && (j == p.col)) {
                continue;
            }
            Point pt;
            pt.row = i;
            pt.col = j;
            if (isSunkOrBurning(pt)) {
                return false;
            }
        }
    }
    return true;
}
