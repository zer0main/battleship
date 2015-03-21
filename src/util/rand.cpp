/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <cstdlib>

#include "rand.hpp"

unsigned int random(unsigned int end) {
    return std::rand() / (RAND_MAX / end + 1);
}
