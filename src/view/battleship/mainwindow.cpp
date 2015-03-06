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

void MainWindow::on_QuitButton_clicked()
{
    QApplication::quit();
}

void MainWindow::on_BotVsBot_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_BotVsHuman_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_HumanVsHuman_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}
