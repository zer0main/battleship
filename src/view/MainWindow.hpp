/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;

    void settingOfBoards();

private slots:
    void on_quitButton_clicked();

    void on_botVsBot_clicked();

    void on_botVsHuman_clicked();

    void on_humanVsHuman_clicked();

    void on_playButton_clicked();
};

#endif // MAINWINDOW_H
