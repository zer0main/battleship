/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

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
}
