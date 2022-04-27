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

    //keeps track of the last state of the game in order to display an accurate statement to the player upon restart
    //0 is fresh game, 1 is last lost, 2 is last won
    int previousOutcome = 0;

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

    //getters and setters for the phrase and hint
    std::string getPhrase();
    std::string getHint();

    //getter for guessed phrase
    std::string getGuessedPhrase();

    //getters and setters for number of fails
    int getFail();
    void setFail(int num);

    //gets previous game outcome
    int getPreviousOutcome();

    //processes initialization
    void initialize();

    //processes the guessed letter
    void processGuess(std::string letterGuessed);

    //processes win or lose
    void checkForWin();
};

#endif // HANGMAN_H
