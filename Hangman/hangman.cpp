//Kirin Hardinger
//April 24-26, 2022

#include "hangman.h"

int Hangman::getFail() {
    return numFails;
}

int Hangman::getState() {
    return gameState;
}

void Hangman::setState(int state) {
    gameState = state;
}

int Hangman::getDifficulty() {
    return difficultyLevel;
}

void Hangman::setDifficulty(int level) {
    difficultyLevel = level;
}

std::string Hangman::getPhrase() {
    return phrase;
}

void  Hangman::setPhrase() {
    if(difficultyLevel == 0) {
        phrase = "DR LANCASTER";
    } else if(difficultyLevel == 1) {
        phrase = "FIVE THIRTY";
    } else {
        phrase = "YOU HAVE BEEN RICKROLLED";
    }
}

std::string  Hangman::getHint() {
    return hint;
}

void Hangman::setHint() {
    if(difficultyLevel == 0) {
        hint = "The name of a professor in the Department of Computer Science.";
    } else if(difficultyLevel == 1) {
        hint = "What time does the projector always burn out? (spelled out)";
    } else {
        hint = "The greatest song of all time.";
    }
}

std::string Hangman::getGuessedPhrase() {
    return guessedPhrase;
}

void Hangman::initialize() {
    if (gameState == 1) {
        setPhrase();
        setHint();

        //initializes the guessedPhrase
        guessedPhrase = phrase;
        for (int i = 0; i < guessedPhrase.length(); i++) {
            if(guessedPhrase[i] != ' ') {
                guessedPhrase[i] = '_';
            }
        }

        gameState = 2;
    }
}

void Hangman::processGuess(std::string letterGuessed) {
    int correctGuess = 0;
    for (int i = 0; i < phrase.length(); i++) {
        if(phrase[i] == letterGuessed[0]) {
            guessedPhrase[i] = letterGuessed[0];
            correctGuess++;
        }
    }
    if(correctGuess == 0) numFails += 1;
    checkForWin();
}

void Hangman::checkForWin() {
    for (int i = 0; i < guessedPhrase.length(); i++) {
        if(numFails == 6) {
            gameState = 3;
        }

        if(guessedPhrase[i] == '_') {
            return;
        }
    }
    gameState = 4;
}
