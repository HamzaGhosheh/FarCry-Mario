#include "Boss.h"
#include <cstdlib>

Boss::Boss(){

}
//default destructor

Boss::~Boss(){

}
// default destructor


bool Boss::BossLoses(){
    int chance = rand() % 100;
    if (chance < 50){ // 50% chance for mario to defeat the level boss
        return true;
    }
    return false;
}