#include "Mario.h"

#include <string>
#include <iostream>

//all header files are included above

Mario::Mario(){ 
    powerLevel = 0;
    CoinCount = 0;
    enemiesDefeated = 0;
}
// default constructor

Mario::~Mario(){

} 
// default destructor

void Mario::addCoin(){ 
    CoinCount++;
    if (CoinCount == 20){ // if mario collects 20 coins, LifeCount increases by 1, and coinCount is reset to 0
        LifeCount++;
        CoinCount = 0;
    }
}

void Mario::levelingUp(){
    if (powerLevel < 2){ // increases power level unless already at max power level
        powerLevel++;
    }
}

void Mario::defeatEnemy(){
    enemiesDefeated++;
    if (enemiesDefeated == 7){ // if mario beats 7 enemies on the same lifeline, then he gains a another life
        LifeCount++;
        enemiesDefeated = 0;
    }
}

void Mario::setLives(int lives){
    LifeCount = lives;
}

void Mario::setPowerLevel(int PL){
    powerLevel = PL;
}

bool Mario::outOfLives(){
    if (LifeCount == 0){
        return true;
    }
    return false;
}

int Mario::getLives(){
    return LifeCount;
}

int Mario::getCoins(){
    return CoinCount;
}


int Mario::getPowerLevel(){
    return powerLevel;
}

void Mario::resetDefeatedEnemies(){
    enemiesDefeated = 0;
}

void Mario::losingLife(){
    LifeCount--;
}

void Mario::decreasePowerLevel(){
    if (powerLevel > 0){
        powerLevel--;
    }
}




