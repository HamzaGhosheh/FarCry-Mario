#include "Koopa.h"
#include <cstdlib>


// all header files needed are included above

Koopa::Koopa(){

}
//default constructor

Koopa::~Koopa(){

}
// default destructor

//boolean method since this will be called in Mario
bool Koopa::MarioDefeatsKoopa(){
    int chance = rand() % 100;
    if (chance < 65){ // 65% chance for mario to defeat koopa
        return true;
    }
    return false;
}