#include "Gameplay.h"
#include "FileProcessor.h"
#include <chrono>

// all header files needed are included above


int main(){ 
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    // needed to have chrono included or else no seeding would have occurred
    // also produced an infinitely long piece of code if it was not included
    srand(seed);
    Gameplay gameplay;
    gameplay.playGame(); // plays the entire game
    return 0;
}