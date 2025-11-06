#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

// random float in [a,b]
static float frand(float a, float b) {
    return a+(b-a) * (static_cast<float>(rand()) / RAND_MAX);
}

Game::Game(){
    // seed RNG
    srand(static_cast<unsigned>(time(nullptr)));

}

Game::~Game() {
    //clean up plaers
    for(RPG* p: players) {
        delete p;
    }
    players.clear();
    live_players.clear();

}
// Make n playeres and mark them as alive
void Game::generatePlayers(int n) {
    int startIndex = static_cast<int>(players.size());
    for (int i = 0; i < n; ++i) {

        string name = "NPC " + to_string(startIndex + i);
        int hits = 0;
        float luck = frand(0.10f, 0.50f);
        float exp = 50.0f;
        int level = 1;

        RPG* r = new RPG(name, hits, luck, exp, level);
        players.push_back(r);
        live_players.insert(static_cast<int>(players.size()) - 1);
    }
}
//Picks a random index from the set amount of live players
int Game::selectPlayers() const{
    if (live_players.empty()) return -1;

    int k = rand() % static_cast<int>(live_players.size());
    auto it = live_players.begin();

    while (k--> 0) ++it;

    return *it;
}

void Game::endRound(RPG* a, RPG* b, int winner) {
    int ia = -1, ib = -1;
    for (int i = 0; i < (int)players.size(); ++i) {
        if (players[i] == a) ia = i;
        if (players[i] == b) ib = i;
    }

    if (winner == 0) {
        a->updateExpLevel();
        a->setHitsTaken(0);
        cout << a->getName() << " won against " << b->getName() << "\n";
        if (ib != -1) live_players.erase(ib);
    } else {
        b->updateExpLevel();
        b->setHitsTaken(0);
        cout << b->getName() << " won against " << a->getName() << "\n";
        if (ia != -1) live_players.erase(ia);
    }
}


void Game::battleRound() {
    if (live_players.size() < 2) return;

    int i = selectPlayers();
    int j = selectPlayers();
    while (j == i) j = selectPlayers();

    RPG* a = players[i];
    RPG* b = players[j];

    bool a_turn = true;
    while (a->isAlive() && b->isAlive()) {
        if (a_turn) a->attack(b);
        else        b->attack(a);
        a_turn = !a_turn;
    }
    int winner = a->isAlive() ? 0 : 1;
    endRound(a, b, winner);
}


void Game::gameLoop() {
    //keep fighting until 1 survivor
    while (live_players.size() > 1) {
        battleRound();
    }
}

void Game::printFinalResults() const {
    cout << "=== Game Over ===\n";
    if (!live_players.empty()) {
        int winnerIndex = *live_players.begin();
        cout << "Winner: " << players[winnerIndex]->getName() << "\n\n";
    }

    cout << "Final Player Stats: \n";
    for (size_t i = 0; i < players.size(); ++i) {
        cout << "[" << i << "] ";
        players[i]->printStats();
    }
}    