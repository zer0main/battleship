/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <cstdlib>

#include "random.hpp"

// FIXME
// This solution is non-working. We must use /dev/urandom
// or boost.random for good random function.

unsigned int random(unsigned int end) {
    return rand() / (RAND_MAX / end + 1);
}
