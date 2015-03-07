/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <cstdlib>

#include "placeShips.hpp"
#include "spaceForShip.hpp"

void placeShips(GameController& controller,
                const GameDesk& desk, int player_number) {
    for (int i = 1; i <= 4; i++) {
        for (int x = 0; x < 5 - i; x++) {
            Points ship;
            bool is_valid = false;
            while (!is_valid) {
                if (std::rand() <= (RAND_MAX / 2)) {
                    ship.is_horizontal = true;
                    ship.p1.col = std::rand() %
                                  desk.getLength();
                    ship.p2.col = ship.p1.col;
                    ship.p1.row = std::rand() %
                                  desk.getWidth() - i;
                    ship.p2.row = ship.p1.row + i;
                    is_valid = spaceForShip(desk,
                                            ship,
                                            player_number);
                } else {
                    ship.is_horizontal = false;
                    ship.p1.row = std::rand() %
                                  desk.getWidth();
                    ship.p2.row = ship.p1.row;
                    ship.p1.col = std::rand() %
                                  desk.getLength() - i;
                    ship.p2.col = ship.p1.col + i;
                    is_valid = spaceForShip(desk,
                                            ship,
                                            player_number);
                }
            }
            controller.setShip(player_number, ship);
        }
    }
}
