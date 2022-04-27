//Kirin Hardinger
//April 24-26, 2022

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "hangman.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //updates the window
    void updateUI(int gameState);

    //updates the hangman
    void updateHangman(int numFails);

    //enables/disables buttons
    void updateButtons(bool on);

    //instantiates a hangman object
    Hangman hangman;

private slots:
    void letterPressed();
    void difficultyPressed();
    void quitPressed();
    void restartPressed();
};
#endif // MAINWINDOW_H
