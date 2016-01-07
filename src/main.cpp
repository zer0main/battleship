/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <cstdlib>
#include <ctime>

#include <QtGui/QApplication>

#include "MainWindow.hpp"

int main(int argc, char* argv[]) {
    // FIXME
    // Use boost.random or /dev/urandom instead of rand()
    // and srand()
    srand(time(NULL));
    QApplication a(argc, argv);
    a.setApplicationName("battleship");
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
