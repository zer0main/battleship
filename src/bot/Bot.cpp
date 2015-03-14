/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <cstdlib>

#include "Bot.hpp"

static int getEnemysNumber(int my_number) {
    return 3 - my_number;
}

static bool isSunkOrBurning(const Point& point,
                            int bot_number,
                            const GameDeskProxy* desk) {
    if (desk->getVisibility(point, bot_number)) {
        if (desk->getCellState(point, bot_number)) {
            return true;
        }
    }
    return false;
}

static bool isGoodNeighbor(const Point& p1,
                           const Point& p2,
                           int bot_number,
                           const GameDeskProxy* desk) {
    if ((p1.row == p2.row) || (p1.col == p2.col)) {
        if (desk->getFlooding(p1, bot_number)) {
            return false;
        }
    } else if (isSunkOrBurning(p1, bot_number, desk)) {
        return false;
    }
    return true;
}

Bot* Bot::make(const GameDeskProxy* desk, int bot_number) {
    if (desk == NULL) {
        throw Exception("Received NULL pointer to "
                        "GameDeskProxy when try to create "
                        "Bot");
    } else if ((bot_number != 1) && (bot_number != 2)) {
        throw Exception("Invalid bot's number when try to "
                        "create Bot");
    }
    Bot* bot = new Bot();
    bot->bot_number_ = bot_number;
    bot->desk_ = desk;
    return bot;
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
    int enemy = getEnemysNumber(bot_number_);
    while ((!checkNeighboringCells(pt)) || (is_visible)) {
        pt.col = std::rand() % desk_->getLength();
        pt.row = std::rand() % desk_->getWidth();
        is_visible = desk_->getVisibility(pt, enemy);
    }
    return pt;
}

bool Bot::checkCoordinate(const Point& p) const {
    int enemy = getEnemysNumber(bot_number_);
    if (desk_->getVisibility(p, enemy)) {
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
                            (i != p.row)) ||
                           ((i == p.row) &&
                            (j == p.col))) {
                continue;
            } else if (j >= desk_->getLength()) {
                break;
            }
            Point pt;
            pt.row = i;
            pt.col = j;
            if (isSunkOrBurning(pt, enemy, desk_) &&
                    !desk_->getFlooding(pt, enemy)) {
                return true;
            }
        }
    }
    return false;
}

bool Bot::checkNeighboringCells(const Point& p) const {
    int enemy = getEnemysNumber(bot_number_);
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
            if (!isGoodNeighbor(pt, p, enemy, desk_)) {
                return false;
            }
        }
    }
    return true;
}

bool Bot::thereAreMoves() const {
    int enemy = getEnemysNumber(bot_number_);
    for (int i = 0; i < desk_->getLength(); i++) {
        for (int x = 0; x < desk_->getWidth(); x++) {
            Point pt;
            pt.col = i;
            pt.row = x;
            if (checkNeighboringCells(pt)) {
                if (!desk_->getVisibility(pt,
                                          enemy)) {
                    return true;
                }
            }
        }
    }
    return false;
}

Bot::Bot() {
}
