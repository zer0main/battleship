/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <string>
#include <exception>

/** Class for all exceptions */
class Exception: public std::exception {
public:
    /** Constructor */
    Exception(const std::string& message);

    /** Destructor */
    ~Exception() throw();

    /** Error message */
    const char* what() const throw();

private:
    std::string message_;
};

#endif
