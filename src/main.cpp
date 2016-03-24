/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <cstdlib>
#include <ctime>
#include <exception>

#include <QtGui/QApplication>

#include "MainWindow.hpp"

class MyApplication : public QApplication {
public:
    MyApplication(int& argc, char* argv[]):
        QApplication(argc, argv) {
    }

    bool notify(QObject* receiver, QEvent* event) {
        try {
            return QApplication::notify(receiver, event);
        } catch (const std::exception& error) {
            QString what = QString::fromStdString(error.what());
            QString message = "<b>The error occurred</b>."
                              "<br/><br/>Contact developers! "
                              "<b>pdolgov99@gmail.com</b>";
            what = what.replace("&", "&amp;");
            what = what.replace("'", "&apos;");
            what = what.replace("<", "&lt;");
            what = what.replace(">", "&gt;");
            what = what.replace("\"", "&quot;");
            QString m = message + "<br/><br/>" + what;
            QErrorMessage::qtHandler()->resize(400, 300);
            QErrorMessage::qtHandler()->showMessage(m);
            return false;
        }
    }
};

int main(int argc, char* argv[]) {
    // FIXME
    // Use boost.random or /dev/urandom instead of rand()
    // and srand()
    srand(time(NULL));
    MyApplication a(argc, argv);
    a.setApplicationName("battleship");
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
