/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <cstdlib>

#include "Bot.hpp"

static bool isSunkOrBurning(const Point& point,
                            int bot_number) {
    if (desk_->getVisibility(point, bot_number)) {
        if (desk_->getCellState(point, bot_number)) {
            return true;
        }
    }
    return false;
}

static bool isGoodNeighbor(const Point& p1,
                           const Point& p2,
                           int bot_number) {
    if ((p1.row == p2.row) || (p1.col == p2.col)) {
        if (desk_->getFlooding(p1, bot_number)) {
            return false;
        }
    } else if (isSunkOrBurning(p1, bot_number)) {
        return false;
    }
    return true;
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
    if (!thereAreMoves()) {
        throw Exception("Bot can't make any move, there "
                        "is no possibility to make moves "
                        "with this state of board");
    }
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
        is_visible = desk_->getVisibility(pt,
                                          bot_number_);
    }
    return pt;
}

bool Bot::checkCoordinate(const Point& p) const {
    if (desk_->getVisibility(p, bot_number_)) {
        return false;
    } else if (!checkNeighboringCells(p)) {
        return false;
    }
    for (int i = p.row - 1; i <= p.row + 1; i++) {
        if (i < 0) {
            continue;
        } else if (i >= desk_->getWidth()) {
            break;
        }
        for (int j = p.col - 1; j <= p.col + 1; j++) {
            if ((j < 0) || ((j != p.col) &&
                (i != p.row)) || ((i == p.row) &&
                (j == p.col))) {
                continue;
            } else if (j >= desk_->getLength()) {
                break;
            }
            Point pt;
            pt.row = i;
            pt.col = j;
            if (isSunkOrBurning(pt, bot_number_) &&
                !desk_->getFlooding(pt, bot_number_)) {
                return true;
            }
        }
    }
    return false;
}

bool Bot::checkNeighboringCells(const Point& p) const {
    for (int i = p.row - 1; i <= p.row + 1; i++) {
        if (i < 0) {
            continue;
        } else if (i >= desk_->getWidth()) {
            break;
        }
        for (int j = p.col - 1; j <= p.col + 1; j++) {
            if ((j < 0) || ((i == p.row) &&
                (j == p.col))) {
                continue;
            } else if (j >= desk_->getLength()) {
                break;
            }
            Point pt;
            pt.row = i;
            pt.col = j;
            if (!isGoodNeighbor(pt, p, bot_number_)) {
                return false;
            }
        }
    }
    return true;
}

bool Bot::thereAreMoves() const {
    for (int i = 0; i < desk_->getLength(); i++) {
        for (int x = 0; x < desk_->getWidth(); x++) {
            Point pt;
            pt.col = i;
            pt.row = x;
            if (checkNeighboringCells(pt)) {
                if (!desk_->getVisibility(pt,
                                          bot_number_)) {
                    return true;
                }
            }
        }
    }
    return false;
}
