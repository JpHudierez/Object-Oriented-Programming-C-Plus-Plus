#ifndef Game_H
#define Game_H

#include <vector>
#include <set>
#include <string>
#include "RPG.h"

class Game {
    public:
        Game(); //makes some default players
        ~Game(); //deletes any new'ed players 

        void generatePlayers(int n); 
        int selectPlayers() const; 
        void endRound(RPG* a, RPG* b, int winner); //updates exp and remmoves loser
        void battleRound(); 
        void gameLoop(); //run until one survivor
        void printFinalResults() const;

    private:
        std::vector<RPG*> players;
        std::set<int> live_players;
};
#endif