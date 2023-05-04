// gamestate.cpp

#include "gamestate.h"

using namespace std::chrono;

long long gettimescore(GameState &state){ // return score by time
    long long scr = 100 * duration_cast<milliseconds>(state.getCurrentDuration()).count();
    return scr;
    
}

long long getotherscore(GameState &state){

}

long long getallscore(long long a, long long b){
    return a + b;
}


