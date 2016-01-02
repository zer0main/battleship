/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "random.hpp"

/* Function retunrns sum of all elements of vector
   (argument). All the elements of argument will be
   replaced by sums of elements before it (include current
   element).
*/
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

unsigned int randomWithUnequalChances(std::vector<int>&
                                      chances) {
    int sum = vectorOfSums(chances);
    int random_number = random(sum);
    int start = 0;
    for (int i = 0; i < chances.size(); i++) {
        if (random_number >= start) {
            if (random_number < chances[i]) {
                return i;
            }
        }
        start = chances[i];
    }
}

