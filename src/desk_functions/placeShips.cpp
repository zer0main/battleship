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
    for (int i = 4; i >= 1; i--) {
        for (int x = 0; x < 5 - i; x++) {
            int try_number = 0;
            Points ship;
            bool is_valid = false;
            while (!is_valid) {
                try_number++;
                // Check if there is no possibility to
                // place ship (all the board is occupied).
                if (try_number > desk.getWidth() *
                        desk.getLength() * 10) {
                    controller.initialStateOfBoard();
                    placeShips(controller, desk,
                               player_number);
                    return;
                }
                bool rand = std::rand() <= (RAND_MAX / 2);
                int rand_length = std::rand() %
                    (desk.getLength() - i);
                int rand_width = std::rand() %
                    (desk.getWidth() - i);
                ship.p1.col = (rand) ? std::rand() %
                    desk.getLength() : rand_length;
                ship.p2.col = (rand) ?  ship.p1.col :
                    rand_length + i;
                ship.p1.row = (rand) ? rand_width :
                    std::rand() % desk.getWidth();
                ship.p2.row = (rand) ? rand_width + i :
                    ship.p1.row;
                is_valid = spaceForShip(desk, ship,
                                        player_number);
            }
            controller.setShip(player_number, ship);
        }
    }
}
