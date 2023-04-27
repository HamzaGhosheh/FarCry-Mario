#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>
#include <fstream>
#include "Mario.h"
#include "Level.h"
#include "FileProcessor.h"

// all header files needed are included above

class Gameplay{
    public:
        Gameplay();
        ~Gameplay();

        void interactNothing(); // interaction when he moves to an empty space
        void interactCoin(); // interaction with a coin
        void interactMushroom(); // interaction with a mushroom
        void encounteringGoomba(); // interaction with a goomba
        void encounteringKoopa(); // interaction with a koopa
        void encounteringBoss(); // interaction with a boss
        void Warping(); // warping to the next level
        bool outOfLives(); // returns true if mario is out of lives
        void findNextDirection(); // predicts where Mario will move next
        void initialPlacement(); // prints mario's starting location
        void MovingAround(); // random number generator of all Mario's movements
        void printGameWorld(); // prints all the levels at the start
        void playGame(); // A full run of the complete game

        private:
            std::ofstream outputFile; // ofstream used to print to the output file
            FileProcessor processor; // used to read values from input file
            Level level; // the game world
            Mario mario; // our mario object
            char tempChar; // the char Mario will interact with
            int row_location; // mario's row index
            int column_location; // mario's column index
            int currentLevel; // index of the current level mario is on
            bool defeatedBoss; // is the boss of the level defeated
            bool gameEnd; // has the game been beaten
};
#endif