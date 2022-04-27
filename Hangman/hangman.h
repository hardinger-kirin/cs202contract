//Kirin Hardinger
//April 24-26, 2022

#ifndef HANGMAN_H
#define HANGMAN_H

#include <QString>
#include <QDebug>

class Hangman {
private:
    //game state
    //0 is difficulty selection, 1 is setup, 2 is playing, 3 is lose end, 4 is win end
    int gameState = 0;

    //number of incorrect guesses
    int numFails = 0;

    //difficulty level. 0 is easy, 1 is medium, 2 is hard
    int difficultyLevel = 0;

    //string for the phrase to be guessed and the hint
    std::string phrase = "";
    std::string hint = "";

    //string for the phrase guessed thus far
    std::string guessedPhrase = "";

    //functions to set phrase and hint
    void setPhrase();
    void setHint();
public:
    //constructor and destructor
    Hangman() {}
    ~Hangman() {}

    //getters and setters for game state
    int getState();
    void setState(int state);

    //getters and setters for difficulty level
    int getDifficulty();
    void setDifficulty(int level);

    //getters for the phrase and hint
    std::string getPhrase();
    std::string getHint();

    //getter for guessed phrase
    std::string getGuessedPhrase();

    //getter for number of fails
    int getFail();

    //processes initialization
    void initialize();

    //processes the guessed letter
    void processGuess(std::string letterGuessed);

    //processes win or lose
    void checkForWin();
};

#endif // HANGMAN_H
