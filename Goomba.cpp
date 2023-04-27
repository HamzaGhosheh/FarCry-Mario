#include "Goomba.h"
#include <cstdlib>

// all header files needed are included above

Goomba::Goomba(){

}

// default constructor

Goomba::~Goomba(){

}

//default destructor

bool Goomba::MarioDefeatsGoomba(){
    int chance = rand() % 100;
    if (chance < 80){ // 80% chance for mario to defeat goomba
        return true;
    }
    return false;
}
