/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QtGui>

#include "Game.hpp"

enum GameType {
    BOT_VS_BOT,
    BOT_VS_HUMAN,
    HUMAN_VS_HUMAN
};

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

    QSharedPointer<Game> game_;

    GameType game_type_;

    int moving_player_number_;

    void configureBoard(QTableView* board);

    void settingOfBoards();

    void errorHandling(std::exception& e);

    void helpMessage();

    void changeCursor();

private slots:
    void humanVsHumanMove();

    void botVsHumanMove();

    void on_quitButton_clicked();

    void on_botVsBot_clicked();

    void on_botVsHuman_clicked();

    void on_humanVsHuman_clicked();

    void on_playButton_clicked();

    void on_board2_clicked(const QModelIndex& index);

    void on_nextMove_clicked();
};

#endif
