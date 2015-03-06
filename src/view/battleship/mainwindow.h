#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_QuitButton_clicked();

    void on_BotVsBot_clicked();

    void on_BotVsHuman_clicked();

    void on_HumanVsHuman_clicked();
};

#endif // MAINWINDOW_H
