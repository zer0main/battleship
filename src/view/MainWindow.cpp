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
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/battleship.ico"));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::prepareGameBoards() {
    if (game_type_ == BOT_VS_HUMAN) {
        ui->board1->setModel(game_->t_model1.data());
        ui->board2->setModel(game_->t_model2.data());
    } else if (game_type_ == BOT_VS_BOT) {
        ui->board5->setModel(game_->t_model1.data());
        ui->board6->setModel(game_->t_model3.data());
    } else {
        ui->board1->setModel(game_->t_model1.data());
        ui->board2->setModel(game_->t_model2.data());
        ui->board3->setModel(game_->t_model3.data());
        ui->board4->setModel(game_->t_model4.data());
    }
}

void MainWindow::configureBoard(QTableView* board) {
    board
    ->setSelectionMode(QAbstractItemView::NoSelection);
    board->horizontalHeader()
    ->setResizeMode(QHeaderView::Stretch);
    board->verticalHeader()
    ->setResizeMode(QHeaderView::Stretch);
}

void MainWindow::settingOfBoards() {
    configureBoard(ui->board1);
    configureBoard(ui->board2);
    configureBoard(ui->board3);
    configureBoard(ui->board4);
    configureBoard(ui->board5);
    configureBoard(ui->board6);
}

void MainWindow::errorHandling(std::exception& e) {
    QString what = QString::fromStdString(e.what());
    QString error = "<b>The error occurred</b>."
                    "<br/><br/>Contact developers! "
                    "<b>pdolgov99@gmail.com</b>";
    what = what.replace("&", "&amp;");
    what = what.replace("'", "&apos;");
    what = what.replace("<", "&lt;");
    what = what.replace(">", "&gt;");
    what = what.replace("\"", "&quot;");
    QString m = error + "<br/><br/>" + what;
    QErrorMessage::qtHandler()->resize(400, 300);
    QErrorMessage::qtHandler()->showMessage(m);
}

void MainWindow::helpMessage() {
    QString help_message = "<b>Do not shoot at cell which "
                           "has already shot down.</b>";
    QErrorMessage::qtHandler()->resize(400, 300);
    QErrorMessage::qtHandler()->showMessage(help_message);
}

void MainWindow::changeCursor() {
    if (moving_player_number_ == 1) {
        ui->board2->setCursor(Qt::ArrowCursor);
    } else {
        ui->board2->setCursor(Qt::PointingHandCursor);
    }
}

void MainWindow::preparingToPlay() {
    settingOfBoards();
    int width = ui->boardWidth->value();
    int length = ui->boardHeight->value();
    game_ = startGame(this, width, length);
    game_->controller->initialStateOfBoard();
    placeShips(*(game_->controller),
               *(game_->desk), 1);
    placeShips(*(game_->controller),
               *(game_->desk), 2);
    prepareGameBoards();
}

void MainWindow::winningActions() {
    if (game_type_ == BOT_VS_HUMAN) {
        if (moving_player_number_ == 1) {
            ui->board2->setModel(game_->t_model3.data());
        }
    }
    QTimer::singleShot(10000, this, SLOT(winMessage()));
}

void MainWindow::winMessage() {
    QString winner =
        QString::number(moving_player_number_);
    QString win_message;
    if (game_type_ == BOT_VS_BOT) {
        win_message = "<b>Bot under number " + winner +
                      " won!</b>";
    } else if (game_type_ == HUMAN_VS_HUMAN) {
        win_message = "<b>You won!</b>";
    } else {
        if (moving_player_number_ == 2) {
            win_message = "<b>You won!</b>";
        } else {
            win_message = "<b>Bot won...</b>";
        }
    }
    QMessageBox winInfo;
    winInfo.setText(win_message);
    winInfo.exec();
}

void MainWindow::botVsBotMove() {
    try {
        if (moving_player_number_ == 1) {
            Point p = game_->bot1->getIndex();
            game_->controller->makeMove(1, p);
            game_->t_model1->updateData();
            if (!game_->desk->getCellState(p, 2)) {
                moving_player_number_ = 2;
            }
        } else {
            Point p = game_->bot2->getIndex();
            game_->controller->makeMove(2, p);
            game_->t_model3->updateData();
            if (!game_->desk->getCellState(p, 1)) {
                moving_player_number_ = 1;
            }
        }
        QTimer::singleShot(3000, this,
                           SLOT(botVsBotMove()));
    } catch (std::exception& e) {
        errorHandling(e);
    }
}

void MainWindow::humanVsHumanMove() {
    ui->stackedWidget->setCurrentWidget(ui->waitingpage);
    if (moving_player_number_ == 1) {
        ui->board3->setCursor(Qt::ArrowCursor);
        ui->board4->setCursor(Qt::PointingHandCursor);
    } else {
        ui->board1->setCursor(Qt::ArrowCursor);
        ui->board2->setCursor(Qt::PointingHandCursor);
    }
}

void MainWindow::botVsHumanMove() {
    try {
        Point p = game_->bot1->getIndex();
        game_->controller->makeMove(1, p);
        game_->t_model1->updateData();
        if (game_->desk->getCellState(p, 2)) {
            QTimer::singleShot(3000, this,
                               SLOT(botVsHumanMove()));
        } else {
            moving_player_number_ = 2;
            changeCursor();
        }
    } catch (std::exception& e) {
        errorHandling(e);
    }
}

void MainWindow::on_quitButton_clicked() {
    QApplication::quit();
}

void MainWindow::on_botVsBot_clicked() {
    game_type_ = BOT_VS_BOT;
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_botVsHuman_clicked() {
    game_type_ = BOT_VS_HUMAN;
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_humanVsHuman_clicked() {
    game_type_ = HUMAN_VS_HUMAN;
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_playButton_clicked() {
    moving_player_number_ = 2;
    try {
        preparingToPlay();
        if (game_type_ == BOT_VS_BOT) {
            ui->stackedWidget
            ->setCurrentWidget(ui->botpage);
            QTimer::singleShot(3000, this,
                               SLOT(botVsBotMove()));
        } else {
            changeCursor();
            ui->stackedWidget
            ->setCurrentWidget(ui->gamepage);
        }
    } catch (std::exception& e) {
        errorHandling(e);
    }
}

void MainWindow::on_board2_clicked(const QModelIndex&
                                   index) {
    if (moving_player_number_ != 2) {
        return;
    }
    Point pt(index.column(), index.row());
    if (game_->desk->getVisibility(pt, 1)) {
        helpMessage();
        return;
    }
    try {
        game_->controller->makeMove(2, pt);
        game_->t_model2->updateData();
        if (game_->desk->getCellState(pt, 1)) {
            return;
        }
        if (game_type_ == BOT_VS_HUMAN) {
            moving_player_number_ = 1;
            changeCursor();
            QTimer::singleShot(3000, this,
                               SLOT(botVsHumanMove()));
        } else if (game_type_ == HUMAN_VS_HUMAN) {
            moving_player_number_ = 1;
            ui->board2->setCursor(Qt::ArrowCursor);
            QTimer::singleShot(3000, this,
                               SLOT(humanVsHumanMove()));
        }
    } catch (std::exception& e) {
        errorHandling(e);
    }
}

void MainWindow::on_board4_clicked(const QModelIndex&
                                   index) {
    if (moving_player_number_ != 1) {
        return;
    }
    Point pt(index.column(), index.row());
    if (game_->desk->getVisibility(pt, 2)) {
        helpMessage();
        return;
    }
    try {
        game_->controller->makeMove(1, pt);
        game_->t_model4->updateData();
        if (game_->desk->getCellState(pt, 2)) {
            return;
        }
        ui->board4->setCursor(Qt::ArrowCursor);
        moving_player_number_ = 2;
        QTimer::singleShot(3000, this,
                           SLOT(humanVsHumanMove()));
    } catch (std::exception& e) {
        errorHandling(e);
    }
}

void MainWindow::on_nextMove_clicked() {
    if (moving_player_number_ == 1) {
        ui->stackedWidget->setCurrentWidget(ui->gamepage2);
    } else {
        ui->stackedWidget->setCurrentWidget(ui->gamepage);
    }
}
