/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef BOT_HPP_
#define BOT_HPP_

#include "GameDesk.hpp"

/** Bot class contains all bot logic.
*/
class Bot {
public:
    /** Set pointer to model class GameDesk
    */
    void setDesk(const GameDesk* desk);

    /** This method returns Point structure which contains
    coordinates of cell that bot wants to shoot
    */
    Point getIndex() const;

private:
    const GameDesk* desk_;
};

#endif
