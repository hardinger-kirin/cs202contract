# cs202contract
Contract course project for CS 202 spring semester at the University of Nevada Reno

How to run
/////
In order to run the project, extract the Hangman-Executable-Kirin-Hardinger folder and run YES.exe.
It was named this because I got very excited when everything started to work and I just left it that way... :)

Description
/////
This project builds upon a contract course I had done in the previous fall semester for CS 135 at UNR.
There, I made a terminal-based Hangman game in C. There were a few restrictions put it place, one of them being staying away from strings and instead using only char arrays.

Here, I have now refactored the program into C++ and made a GUI using the Qt framework.
This project was easier in certain respects: I wasn't restricted to any particular libraries or methods, and so I was able to use strings instead of char arrays.
That being said, Qt has some restrictions of its own. I ended up treating my strings as arrays of characters because of the nature of QStrings.
Most of my time spent on this project was struggling with Qt itself: I spent an entire day following an online tutorial of making a basic scientific calculator with a Qt GUI.
I also spent another day figuring out how to deploy the application so that it could be downloaded and run by any Windows user.

Overall, I was very happy with the outcome of this application!

Expected performance
/////
Upon running, you should see three difficulty settings on the lefthand side. Below these three buttons should be a "Restart" button and a "Quit" button.
Selecting a difficulty will begin the game. You can see underscores to represent the letters to be guessed for the Hangman phrase.
Below the main display, you can click on the letter you would like to guess.
Below that, there is a box giving you a hint to the phrase.
At any time, you can click "Restart" to choose a difficulty and try again. If you win or lose a round and wish to play again, you must click on "Restart" or relaunch the project.
Pressing the Quit button will exit the window.
You are allowed up to 6 failed guesses.