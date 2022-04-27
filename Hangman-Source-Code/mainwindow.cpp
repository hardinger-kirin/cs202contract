//Kirin Hardinger
//April 24-26, 2022

#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //setting up letter buttons and connecting them to appropriate slots
    QPushButton *letterButtons[26];
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 26; i++) {
        std::string s = "";
        s.push_back(alphabet[i]);
        QString butName = QString::fromStdString(s) + "But";
        letterButtons[i] = MainWindow::findChild<QPushButton*>(butName);

        //initially, they are disabled so that players cannot start the game before selecting a difficulty
        letterButtons[i]->setEnabled(false);

        connect(letterButtons[i], SIGNAL(released()), this, SLOT(letterPressed()));
    }

    //setting up difficulty buttons and connecting them to appropriate slots
    connect(ui->easyBut, SIGNAL(released()), this, SLOT(difficultyPressed()));
    connect(ui->mediumBut, SIGNAL(released()), this, SLOT(difficultyPressed()));
    connect(ui->hardBut, SIGNAL(released()), this, SLOT(difficultyPressed()));

    //setting up quit and restart buttons and connecting them to the appropriate slots
    connect(ui->quitBut, SIGNAL(released()), this, SLOT(quitPressed()));
    connect(ui->restartBut, SIGNAL(released()), this, SLOT(restartPressed()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateButtons(bool on) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    QPushButton *button;

    if(on) {
        for (int i = 0; i < 26; i++) {
            std::string s = "";
            s.push_back(alphabet[i]);
            QString butName = QString::fromStdString(s) + "But";
            button = MainWindow::findChild<QPushButton*>(butName);
            button->setEnabled(true);
        }
    } else {
        for (int i = 0; i < 26; i++) {
            std::string s = "";
            s.push_back(alphabet[i]);
            QString butName = QString::fromStdString(s) + "But";
            button = MainWindow::findChild<QPushButton*>(butName);
            button->setEnabled(false);
        }
    }
}

void MainWindow::updateUI(int gameState) {
    if (gameState == 0 ) {
        //initialize text displays to be empty
        ui->textHint->setText("");
        ui->guessedDisplay->setText("");

        updateButtons(false);
    } else if (gameState == 1) {
        updateButtons(true);

        hangman.initialize();

        ui->textHint->setText(QString::fromStdString(hangman.getHint()));
        ui->guessedDisplay->setText(QString::fromStdString(hangman.getGuessedPhrase()));
    } else if (gameState == 2) {
        ui->guessedDisplay->setText(QString::fromStdString(hangman.getGuessedPhrase()));
    } else if (gameState == 3) {
        ui->textDisplay->setText("YOU LOSE!! Better luck next time.");
        ui->guessedDisplay->setText(QString::fromStdString(hangman.getGuessedPhrase()));

        updateButtons(false);
    } else if (gameState == 4) {
        ui->textDisplay->setText("YOU WIN!! Wonderful job.");
        ui->guessedDisplay->setText(QString::fromStdString(hangman.getGuessedPhrase()));

        updateButtons(false);
    }
}

void MainWindow::letterPressed() {
    QPushButton *button = (QPushButton*)sender();

    button->setEnabled(false); //that letter can no longer be guessed, so the button is disabled

    ui->textDisplay->setText("You have guessed " + button->text());

    hangman.processGuess(button->text().toStdString());
    updateHangman(hangman.getFail());
    hangman.checkForWin();

    updateUI(hangman.getState());
}

void MainWindow::updateHangman(int numFails) {
    switch(numFails) {
        case 0:
            ui->textHangman->setText("     -----------\n"
                                     "     |         |\n"
                                     "               |\n"
                                     "               |\n"
                                     "               |\n"
                                     "               |\n"
                                     "     -----------\n");
            break;
        case 1:
            ui->textHangman->setText("     -----------\n"
                                     "     |         |\n"
                                     "     O         |\n"
                                     "               |\n"
                                     "               |\n"
                                     "               |\n"
                                     "     -----------\n");
            break;
        case 2:
            ui->textHangman->setText("     -----------\n"
                                     "     |         |\n"
                                     "     O         |\n"
                                     "     |         |\n"
                                     "               |\n"
                                     "               |\n"
                                     "     -----------\n");
            break;
        case 3:
            ui->textHangman->setText("     -----------\n"
                                     "     |         |\n"
                                     "     O         |\n"
                                     "     |\\        |\n"
                                     "               |\n"
                                     "               |\n"
                                     "     -----------\n");
            break;
        case 4:
            ui->textHangman->setText("     -----------\n"
                                     "     |         |\n"
                                     "     O         |\n"
                                     "    /|\\        |\n"
                                     "               |\n"
                                     "               |\n"
                                     "     -----------\n");
            break;
        case 5:
            ui->textHangman->setText("     -----------\n"
                                     "     |         |\n"
                                     "     O         |\n"
                                     "    /|\\        |\n"
                                     "      \\        |\n"
                                     "               |\n"
                                     "     -----------\n");
            break;
        case 6:
            ui->textHangman->setText("     -----------\n"
                                     "     |         |\n"
                                     "    X          |\n"
                                     "   /|\\         |\n"
                                     "   / \\         |\n"
                                     "               |\n"
                                     "     -----------\n");
            break;
    }
}

void MainWindow::difficultyPressed() {
    //if the difficulty has already been selected, return
    if(hangman.getState() != 0) {
        return;
    }

    QPushButton *button = (QPushButton*)sender();

    //disabling all other difficulties and highlighting only the chosen difficulty
    if(button == ui->easyBut) {
        ui->textDisplay->setText("You have selected easy mode... are you sure you don't want to challenge \nyourself?");
        ui->mediumBut->setEnabled(false);
        ui->hardBut->setEnabled(false);

        hangman.setDifficulty(0);
    } else if (button == ui->mediumBut) {
        ui->textDisplay->setText("You have selected medium mode... boring, but to be expected.");
        ui->easyBut->setEnabled(false);
        ui->hardBut->setEnabled(false);

        hangman.setDifficulty(1);
    } else {
        ui->textDisplay->setText("You have selected hard mode... good luck.");
        ui->easyBut->setEnabled(false);
        ui->mediumBut->setEnabled(false);

        hangman.setDifficulty(2);
    }

    //difficulty has been selected, we now set the state to playing
    hangman.setState(1);
    updateUI(hangman.getState());
}

void MainWindow::quitPressed() {
    this->close();
}

void MainWindow::restartPressed() {
    if(hangman.getPreviousOutcome() == 0) {
        ui->textDisplay->setText("Restarting, huh? Was it really that hard?");
    } else if (hangman.getPreviousOutcome() == 1) {
        ui->textDisplay->setText("Trying again? I do not have high hopes for you...");
    } else if (hangman.getPreviousOutcome() == 2) {
        ui->textDisplay->setText("Now you're just being greedy...");
    }


    hangman.setState(0);
    hangman.setFail(0);

    ui->easyBut->setEnabled(true);
    ui->mediumBut->setEnabled(true);
    ui->hardBut->setEnabled(true);

    updateHangman(hangman.getFail());
    updateUI(hangman.getState());
}
