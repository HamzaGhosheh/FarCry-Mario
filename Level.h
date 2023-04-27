#ifndef Level_H
#define Level_H

#include <fstream>
#include <iostream>

// all header files included above

class Level{
    public:
        Level();
        ~Level();

        void generateLevel(int numLevels, int length, int coin, int nothing, 
        int goomba, int koopa, int mushroom); // Constructs the 3d array of chars

        void printLevel(int index, std::ofstream& outputFile); // prints a single level to the log file
        void printLevel(std::ofstream& outputFile); // prints the entire Level to the log file

        char*** gameWorld; // the 3d array which represents the entire game
        int LevelSize; // how many levels there are in the Level array
        int DimensionSize; // sets dimensions of each level in the Level array
};

#endif
