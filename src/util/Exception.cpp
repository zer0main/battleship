/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "Exception.hpp"

Exception::Exception(const std::string& message):
    message_(message) {
}

Exception::~Exception() throw() {
}

const char* Exception::what() const throw() {
    return message_.c_str();
}
