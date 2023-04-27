#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

// all header files needed are included above

Level::Level(){

}
// default constructor

Level::~Level(){

}
// default destructor

void Level::generateLevel(int numLevels, int length, int coin, int nothing, 
int goomba, int koopa, int mushroom){ // these parameters are from the input file

    DimensionSize = length; // DimensionSize of each level
    LevelSize = numLevels; // max amount of levels in the World

    int coinEnd = coin; // index for the end of the coin percentage
    int nothingStart = coinEnd + 1; 
    int nothingEnd = coinEnd + nothing; // index for the end of the nothing percentage
    int goombaStart = nothingEnd + 1; 
    int goombaEnd = nothingEnd + goomba; // index for the end of the coin percentage
    int koopaStart = goombaEnd + 1;
    int koopaEnd = goombaEnd + koopa; // index for the end of the koopa percentage
    int mushroomStart = koopaEnd + 1;
    int mushroomEnd = koopaEnd + mushroom; // index for the end of the mushroom percentage

    char ***levels = new char**[LevelSize]; 
    for (int i = 0; i < LevelSize; i++){
        levels[i] = new char*[DimensionSize];
        for (int j = 0; j < DimensionSize; j++){ 
            levels[i][j] = new char[5];
            for (int k = 0; k < DimensionSize; k++){
                levels[i][j][k] = 'n';
            }
        }
    }



    for (int i = 0; i < LevelSize; i++){ // 2 is the same test value of amount of levels
        for (int j = 0; j < DimensionSize; j++){
            for (int k = 0; k < DimensionSize; k++){
                int random_num = rand() % 100 + 1;
                if (random_num <= coinEnd && random_num >= 1){
                    levels[i][j][k] = 'c';

                }
                if (random_num <= nothingEnd && random_num >= nothingStart){
                    levels[i][j][k] = 'x';

                }
                if (random_num <= goombaEnd && random_num >= goombaStart){
                    levels[i][j][k] = 'g';

                }
                if (random_num <= koopaEnd && random_num >= koopaStart){
                    levels[i][j][k] = 'k';

                }
                if (random_num <= mushroomEnd && random_num >= mushroomStart){
                    levels[i][j][k] = 'm';

                }
            }
        }
    }

    for (int i = 0; i < LevelSize; i++) { // placing the boss and the warp pipe
        int pipeRow;
        int pipeColumn;
        if (i != LevelSize - 1){
            int pipeRow = rand() % DimensionSize; // get random_num location for the warp pipe
            int pipeColumn = rand() % DimensionSize;
            levels[i][pipeRow][pipeColumn] = 'w';
        }
        int bossRow = rand() % DimensionSize;
        int bossColumn = rand() % DimensionSize;
        while (bossRow == pipeRow && bossColumn == pipeColumn){ // make sure pipe and boss are not on the same index
            int bossRow = rand() % DimensionSize; // regenerate random_num numbers
            int bossColumn = rand() % DimensionSize;
        }
        levels[i][bossRow][bossColumn] = 'B';
    }

    gameWorld = levels;

}

void Level::printLevel(int index, std::ofstream& outputFile){ // index is which level will be printed
    for (int i = 0; i < DimensionSize; i++) { // uses the ofstream outputFile to print to log.txt
        for (int j = 0; j < DimensionSize; j++){
            outputFile << gameWorld[index][i][j] << " ";
            
        }
        outputFile << std::endl;
    }
    outputFile << "==========================" << std::endl;
}

void Level::printLevel(std::ofstream& outputFile){
    for (int i = 0; i < LevelSize; i++){ // iterates printLevel i amount of times
        printLevel(i, outputFile);
    }
}