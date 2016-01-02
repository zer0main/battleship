/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef PLACE_SHIPS_HPP_
#define PLACE_SHIPS_HPP_

#include "GameController.hpp"

/** To place ships in the beginning of game at random.
\param controller GameController to set ships
\param desk Game board to receive information
\param player_number Defines payer-owner of ships (1 or 2)
*/
void placeShips(GameController& controller,
                const GameDesk& desk,
                int player_number);

#endif
