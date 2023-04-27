#ifndef MARIO_H
#define MARIO_H

class Mario{
    public:
        Mario();
        ~Mario();
        
        void addCoin(); // adds 1 to numCoins
        void levelingUp(); // adds 1 to powerLevel
        void defeatEnemy(); // adds 1 to enemiesDefeated

        void setLives(int life); 
        void setPowerLevel(int );

        //setters for Mario class

        bool outOfLives(); // returns true if numLives = 0

        int getLives();
        int getCoins();
        int getPowerLevel();

        //getters for Mario class

        void resetDefeatedEnemies(); // set enemiesDefeated to 0
        void losingLife(); // subtract one from numLives if not 0
        void decreasePowerLevel(); // subtract one from powerLevel if not 0

    private:
        int LifeCount; 
        int CoinCount;
        int powerLevel;
        int enemiesDefeated;

        //private variables used in getter functions above
};

#endif