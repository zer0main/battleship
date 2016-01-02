/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "checkWin.hpp"
#include "random.hpp"
#include "Bot.hpp"

/* Check that coordinates (specified in argument) belongs
   to interval [0, max_length/max_width).
*/
static bool isValidCoordinate(const Point& p,
                              const GameDeskProxy* desk) {
    bool greater = (p.col >= 0) && (p.row >= 0);
    bool less = (p.col < desk->getLength()) &&
                (p.row < desk->getWidth());
    return less && greater;
}

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

/* p2 is neighbor of p1. Get coordinates of another
   p1's neighbor in direction p1-p2 (p1, p2, result belongs
   to one line)
*/
static Point getCellOfLine(const Point& p1,
                           const Point& p2) {
    Point result(p1.col, p1.row);
    result.col += p1.col - p2.col;
    result.row += p1.row - p2.row;
    return result;
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
    std::vector<Point> good_cells;
    if (checkWin(*desk_, bot_number_)) {
        throw Exception("Bot won and shouldn't make any "
                        "moves.");
    }
    for (int i = 0; i < desk_->getLength(); i++) {
        for (int x = 0; x < desk_->getWidth(); x++) {
            Point pt(i, x);
            if (checkCoordinate(pt)) {
                good_cells.push_back(pt);
            }
        }
    }
    if (good_cells.size() != 0) {
        return theBestCell(good_cells);
    }
    return randomRationalCell();
}

bool Bot::checkCoordinate(const Point& p) const {
    if (visibleOrSunksNeighbor(p)) {
        return false;
    }
    try {
        Point pt = neighboringBurningCell(p);
        return true;
    } catch (...) {
        return false;
    }
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
            Point pt(j, i);
            if (!isGoodNeighbor(pt, p, enemy, desk_)) {
                return false;
            }
        }
    }
    return true;
}

Point Bot::randomRationalCell() const {
    /* search random cell which isn't visible and which
       hasn't sunken ship near itself
    */
    Point pt(random(desk_->getLength()),
             random(desk_->getWidth()));
    while (visibleOrSunksNeighbor(pt)) {
        pt.col = random(desk_->getLength());
        pt.row = random(desk_->getWidth());
    }
    return pt;
}

bool Bot::visibleOrSunksNeighbor(const Point& p) const {
    int enemy = getEnemysNumber(bot_number_);
    if (desk_->getVisibility(p, enemy) ||
            !checkNeighboringCells(p)) {
        return true;
    }
    return false;
}

std::vector<int> Bot::evaluateCells(const std::vector
                                    <Point>& cells) const {
    std::vector<int> estimates;
    for (int i = 0; i < cells.size(); i++) {
        estimates.push_back(evaluateCell(cells[i]));
    }
    return estimates;
}

int Bot::evaluateCell(const Point& p) const {
    int mark = 1;
    Point p2 = neighboringBurningCell(p);
    Point next = getCellOfLine(p, p2);
    Point saver = p;
    while (isValidCoordinate(next, desk_)) {
        if (visibleOrSunksNeighbor(next)) {
            break;
        }
        p2 = saver;
        saver = next;
        next = getCellOfLine(saver, p2);
        mark++;
    }
    return mark;
}

Point Bot::neighboringBurningCell(const Point& p) const {
    int enemy = getEnemysNumber(bot_number_);
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
            Point pt(j, i);
            if (isSunkOrBurning(pt, enemy, desk_) &&
                    !desk_->getFlooding(pt, enemy)) {
                return pt;
            }
        }
    }
    throw Exception("");
}

Point Bot::theBestCell(const std::vector<Point>&
                       cells) const {
    std::vector<int> estimates = evaluateCells(cells);
    int rand_index = randomWithUnequalChances(estimates);
    return cells[rand_index];
}

Bot::Bot() {
}

