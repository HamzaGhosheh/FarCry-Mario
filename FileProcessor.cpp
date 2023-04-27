#include "FileProcessor.h"

#include <fstream>
#include <iostream>

FileProcessor::FileProcessor(){

}
// default constructor

FileProcessor::~FileProcessor(){

}
//default destructor

void FileProcessor::readValues(){
    std::ifstream inputFile;
    inputFile.open("spec.txt");
    // reading the input values from the input file and storing them in the member variables
    inputFile >> numberLevels;
    inputFile >> dimensions;
    inputFile >> startingLives;
    inputFile >> coinPercent;
    inputFile >> emptyPercent;
    inputFile >> goombaPercent;
    inputFile >> koopaPercent;
    inputFile >> mushroomPercent;

    // calling in the input files from spec.txt

    inputFile.close();

}

int FileProcessor::getLevels(){
    return numberLevels;
}

int FileProcessor::getDimensions(){
    return dimensions;
}

int FileProcessor::getStartingLives(){
    return startingLives;
}

int FileProcessor::getCoinPercent(){
    return coinPercent;
}

int FileProcessor::getEmptyPercent(){
    return emptyPercent;
}

int FileProcessor::getGoombaPercent(){
    return goombaPercent;
}

int FileProcessor::getKoopaPercent(){
    return koopaPercent;
}

int FileProcessor::getMushroomPercent(){
    return mushroomPercent;
}


// each individual method makes it easier to track when ran in Gameplay.cpp