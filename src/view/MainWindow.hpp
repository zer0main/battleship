/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
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

    bool end_of_game_;

    void configureLabel();

    void configureSpinBox();

    void prepareGameBoards();

    void configureBoard(QTableView* board);

    void settingOfBoards();

    void helpMessage();

    void changeCursor();

    void preparingToPlay();

    void winningActions();

    void botMove();

private slots:
    void winMessage();

    void botVsBotMove();

    void humanVsHumanMove();

    void botVsHumanMove();

    void on_quitButton_clicked();

    void on_botVsBot_clicked();

    void on_botVsHuman_clicked();

    void on_humanVsHuman_clicked();

    void on_playButton_clicked();

    void on_board2_clicked(const QModelIndex& index);

    void on_board4_clicked(const QModelIndex& index);

    void on_nextMove_clicked();
};

#endif
