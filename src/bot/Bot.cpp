/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <cstdlib>

#include "Bot.hpp"

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
