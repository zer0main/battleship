/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "random.hpp"

static int vectorOfSums(std::vector<int>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        v[i] = sum;
    }
    return sum;
}

// FIXME
// This solution is non-working. We must use /dev/urandom
// or boost.random for good random function.

unsigned int random(unsigned int end) {
    return rand() / (RAND_MAX / end + 1);
}
