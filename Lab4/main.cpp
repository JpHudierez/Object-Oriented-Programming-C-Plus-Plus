#include <iostream>
#include "Game.h"
using namespace std;

int main() {
    Game g;

    int num_players = 10;   // fixed value to match professor’s output
    g.generatePlayers(num_players);

    g.gameLoop();
    g.printFinalResults();

    return 0;
}
