#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

class FileProcessor{
    public:
        FileProcessor();
        ~FileProcessor();

        void readValues(); // read values from the input file 

        int getLevels();
        int getDimensions();
        int getStartingLives();
        int getCoinPercent();
        int getEmptyPercent();
        int getGoombaPercent();
        int getKoopaPercent();
        int getMushroomPercent();
        // functions above are "getters" for each of the private variables below
    private:
        // these integers are set to the values read from the input file
        int numberLevels; 
        int dimensions;
        int startingLives;
        int coinPercent;
        int emptyPercent;
        int goombaPercent;
        int koopaPercent;
        int mushroomPercent;
};
#endif