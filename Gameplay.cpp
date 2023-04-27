#include "Gameplay.h"
#include "Level.h"
#include "Mario.h"
#include "Goomba.h"
#include "Koopa.h"
#include "Boss.h"
#include "FileProcessor.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

// all header files needed are included above


Gameplay::Gameplay(){
    processor.readValues(); // read values from the input file

    level.generateLevel(processor.getLevels(), processor.getDimensions(), processor.getCoinPercent(), 
    processor.getEmptyPercent(), processor.getGoombaPercent(), processor.getKoopaPercent(),
    processor.getMushroomPercent()); // generateLevels the gamelevel with the values from the input file

    mario.setLives(processor.getStartingLives());

    // get a random location for mario
    row_location = rand() % level.DimensionSize;
    column_location = rand() % level.DimensionSize; 
    
    currentLevel = 0;
    defeatedBoss = false;
    gameEnd = false;
}

// default constructor

Gameplay::~Gameplay(){

}

//defualt destructor

void Gameplay::interactNothing(){
    outputFile << "Mario lands on an empty space. ";

}

void Gameplay::interactCoin(){
    mario.addCoin();
    tempChar = 'x'; // coin is repl
    outputFile << "1 coin collected! ";
}

void Gameplay::interactMushroom(){
    mario.levelingUp();
    tempChar = 'x'; // mushroom is replaced with an x
    outputFile << "Mario leveled up. ";
}

void Gameplay::encounteringGoomba(){
    Goomba goomba;
    if (goomba.MarioDefeatsGoomba()){
        mario.defeatEnemy();
        // sets the tempChar from 'g' to 'x' to show that the goomba is replaced with an x
        tempChar = 'x';
        outputFile << "Mario fought a goomba and won. ";
    } else {
        if (mario.getPowerLevel() > 0){ // mario loses a power level
            mario.decreasePowerLevel();
        } else { // if power level is 0, then loses a life instead
            mario.losingLife();
            mario.resetDefeatedEnemies(); // enemies defeated are no longer on the same life
        }
        outputFile << "Mario fought a goomba and lost. ";
    }
}

void Gameplay::encounteringKoopa(){
    Koopa koopa;
    if (koopa.MarioDefeatsKoopa()){
        mario.defeatEnemy();
        // sets the tempChar from 'k' to 'x' to show that the koopa is replaced with an x
        tempChar = 'x';
        outputFile << "Mario fought a koopa troopa and won. ";
    } else {
        if (mario.getPowerLevel() > 0){ // mario loses a power level
            mario.decreasePowerLevel();
        } else { // if power level is 0, then loses a life instead
            mario.losingLife();
            mario.resetDefeatedEnemies(); // enemies defeated are no longer on the same life
        }
        outputFile << "Mario fought a koopa troopa and lost. ";
    }
}

void Gameplay::encounteringBoss(){
    Boss boss;
    if (boss.BossLoses()){
        mario.defeatEnemy();
        // sets the tempChar from 'b' to 'x' to show that the boss is replaced with an x
        tempChar = 'x';
        outputFile << "Mario encountered the level boss and won. ";
        defeatedBoss = true;
    } else {
        if (mario.getPowerLevel() > 0){ // mario loses up to two power levels
            mario.setPowerLevel(0);
        } else { // if power level is already 0, then he loses a life
            mario.losingLife();
            mario.resetDefeatedEnemies(); // enemies defeated are no longer on the same life
        }
        outputFile << "Mario encountered the level boss and lost. ";
    }
}

void Gameplay::Warping(){
    currentLevel++; // mario gets sent to the next level
    row_location = rand() % level.DimensionSize; // generate a new random location
    column_location = rand() % level.DimensionSize;
    outputFile << "Mario will WARP." << std::endl;
}

bool Gameplay::outOfLives(){
    return mario.outOfLives(); // returns true if mario is out of lives
}

void Gameplay::findNextDirection(){ // determines the next course of action
    // if this is the last level and the boss is defeated, then the game is beaten
    if (currentLevel == level.LevelSize - 1 && defeatedBoss == true){
        outputFile << "The princess has been saved! Mario Wins! " << std::endl;
        gameEnd = true;
        return;
    }
    // if mario encounters a warp pipe or has defeated the boss (if it is not the last level), he warps
    if (tempChar == 'w' || defeatedBoss == true){
        Warping();
        defeatedBoss = false;
        return;
    }
    // if mario is out of lives, then the game is lost
    if (outOfLives()){
        outputFile << "0 Lives remaining. Game Over :(." << std::endl;
        return;
    }
    // random number to determine next direction of movement
    int moveChance = rand() % 100 + 1;
    if (moveChance <= 25 && moveChance >= 1){ // mario moves UP
        outputFile << "Mario will move UP." << std::endl;
        if (row_location == 0){
            row_location = level.DimensionSize - 1; // accounts for mario being all the way up
        } else {
            row_location--;
        }
    }
    if (moveChance <= 50 && moveChance >= 26){ // mario moves RIGHT
        outputFile << "Mario will move RIGHT." << std::endl;
        if (column_location == level.DimensionSize - 1){ 
            column_location = 0; // accounts for mario being all the way to the right
        } else {
            column_location++;
        }
    }
    if (moveChance <= 75 && moveChance >= 51){ // mario moves DOWN
        outputFile << "Mario will move DOWN." << std::endl;
        if (row_location == level.DimensionSize - 1){ 
            row_location = 0; // accounts for mario being all the way down
        } else {
            row_location++;
        }
    }
    if (moveChance <= 100 && moveChance >= 76){ // mario moves LEFT
        outputFile << "Mario will move LEFT." << std::endl;
        if (column_location == 0){
            column_location = level.DimensionSize - 1; // accounts for mario being all the way to the left
        } else {
            column_location--;
        }
    }
}


void Gameplay::initialPlacement(){ // prints mario's starting location at the beginning of the game
    outputFile << "Mario is starting in position (" << row_location << + ", " << column_location << ")" << std::endl;
    outputFile << "==========================" << std::endl;
}

void Gameplay::MovingAround(){ // does a single turn in the game
    // store the character mario will interact with and then place him at the spot
    tempChar = level.gameWorld[currentLevel][row_location][column_location]; 
    level.gameWorld[currentLevel][row_location][column_location] = 'H';

    level.printLevel(currentLevel, outputFile); // prints the current level mario is on

    outputFile << "Level: " << currentLevel << ": ";
    outputFile << "Mario is at position: (" << row_location << ", " << column_location << "). ";

    if (tempChar == 'x'){
        interactNothing();
    }
    if (tempChar == 'c'){
        interactCoin();
    }
    if (tempChar == 'm'){
        interactMushroom();
    }
    if (tempChar == 'g'){
        encounteringGoomba();
    }
    if (tempChar == 'k'){
        encounteringKoopa();
    }
    if (tempChar == 'B'){
        encounteringBoss();
    }
    if (tempChar == 'w'){
        outputFile << "Mario has encountered a warp pipe. ";
    }
    outputFile << "Mario is at Power Level " << mario.getPowerLevel() << ". ";
    outputFile << "Mario has " << mario.getLives() << " lives left. ";
    outputFile << "Mario has " << mario.getCoins() << " coins. ";
    
    // sets the space mario was on back to what it was or to being empty depending on the results of the interaction
    level.gameWorld[currentLevel][row_location][column_location] = tempChar;
    // determine and print mario's next course of action or whether the game was lost or won
    findNextDirection();
    outputFile << "==========================" << std::endl;
}

void Gameplay::printGameWorld(){ // prints the game level to the output file
    level.printLevel(outputFile);
}

void Gameplay::playGame(){ // plays the entire game

    outputFile.open("log.txt"); // open the output file
    printGameWorld(); // print the game level to the file 
    initialPlacement(); // print mario's starting location

    // continously iterate and print each turn until the game is beaten or all lives are lost
    while (gameEnd != true && outOfLives() != true){
        MovingAround();
    }

    outputFile.close(); // close the file
}





