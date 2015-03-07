#include "tb.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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
    ui->board1->setModel(new TableModel(this));
    ui->board1->setSelectionMode(QAbstractItemView::NoSelection);
    ui->board1->horizontalHeader()
    ->setMinimumSectionSize(25);
    ui->board1->horizontalHeader()
    ->setResizeMode(QHeaderView::Stretch);
    ui->board1->verticalHeader()
    ->setResizeMode(QHeaderView::Stretch);
}
