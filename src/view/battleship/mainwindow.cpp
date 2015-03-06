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
