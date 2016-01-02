/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <cstdlib>

#include "Exception.hpp"
#include "random.hpp"
#include "constants.hpp"
#include "placeShips.hpp"
#include "spaceForShip.hpp"

static bool getOneHalf() {
    return rand() <= (RAND_MAX / 2);
}

static Ship findPlace(const GameDesk& desk,
                      int player, int length) {
    int square = desk.getWidth() * desk.getLength();
    int attempts = square * 10;
    for (int i = 0; i < attempts; i++) {
        bool horizontal = getOneHalf();
        int col1, col2, row1, row2;
        if (horizontal) {
            col1 = random(desk.getLength());
            col2 = col1;
            row1 = random(desk.getWidth() - length + 1);
            row2 = row1 + length - 1;
        } else {
            col1 = random(desk.getLength() - length + 1);
            col2 = col1 + length - 1;
            row1 = random(desk.getWidth());
            row2 = row1;
        }
        try {
            Ship ship(Point(col1, row1),
                      Point(col2, row2));
            spaceForShip(desk, ship, player);
            return ship;
        } catch (...) {
        }
    }
    throw Exception("");
}

static void tryPlaceShips(GameController& controller,
                          const GameDesk& desk,
                          int player) {
    int max = MAX_SHIP_LENGTH;
    int min = MIN_SHIP_LENGTH;
    // len is ship_length
    for (int len = max; len >= min; len--) {
        for (int n = 0; n < max + 1 - len; n++) {
            Ship ship = findPlace(desk, player, len);
            controller.setShip(player, ship);
        }
    }
}

void placeShips(GameController& controller,
                const GameDesk& desk, int player) {
    while (true) {
        try {
            tryPlaceShips(controller, desk, player);
            break;
        } catch (...) {
            controller.initialStateOfBoard();
        }
    }
}
