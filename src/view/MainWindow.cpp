/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "placeShips.hpp"
#include "startGame.hpp"
#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::settingOfBoards()
{
    ui->board1
    ->setSelectionMode(QAbstractItemView::NoSelection);
    ui->board1->horizontalHeader()
    ->setResizeMode(QHeaderView::Stretch);
    ui->board1->verticalHeader()
    ->setResizeMode(QHeaderView::Stretch);
    ui->board2
    ->setSelectionMode(QAbstractItemView::NoSelection);
    ui->board2->horizontalHeader()
    ->setResizeMode(QHeaderView::Stretch);
    ui->board2->verticalHeader()
    ->setResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_quitButton_clicked()
{
    QApplication::quit();
}

void MainWindow::on_botVsBot_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_botVsHuman_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_humanVsHuman_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_playButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->gamepage);
    settingOfBoards();
    int width = ui->boardWidth->value();
    int length = ui->boardHeight->value();
    game_ = startGame(this, width, length);
    game_->controller->initialStateOfBoard();
    placeShips(*(game_->controller), *(game_->desk), 1);
    placeShips(*(game_->controller), *(game_->desk), 2);
    ui->board1->setModel(game_->t_model1.data());
    ui->board2->setModel(game_->t_model2.data());
}
