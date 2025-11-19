#include "Game.h"
#include <iostream>
#include <random>
using namespace std;

Game::Game() {

}

void Game::generatePlayers(int n) 
{
    for (int i=0; i < n; i++){
        players.push_back(new RPG());
        //rename players
        string new_name = "NPC_" +to_string(i);
        players[i]->setName(new_name);
        live_players.insert(i);
    }
}

int Game::selectPlayer()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, live_players.size() - 1);
    //pick random index
    int randomIndex = dist(gen);
    //Advance iterator to that index
    set<int>::iterator it = live_players.begin();
    advance(it, randomIndex);

    int selectedIndex = *it;
    return selectedIndex;
}

void Game::endRound(RPG *winner, RPG *loser, int loserIndex)
{
    winner->setHitsTaken(0);
    live_players.erase(loserIndex);
    winner->updateExpLevel();
    cout << winner->getName() << " won against "
    << loser->getName() << endl;
}

void Game::battleRound()
{
    int playerIndex1 = selectPlayer();
    int playerIndex2 = selectPlayer();
    if (playerIndex1  == playerIndex2) {
        battleRound();
        return;
    }
    RPG* player1 = players[playerIndex1];
    RPG* player2 = players[playerIndex2];
    while (player1->isAlive() && player2->isAlive()) {
        player1->attack(player2);
        player2->attack(player1);
    }
    RPG* winner;
    RPG* loser;
    int loserIndex;
    if (player1->isAlive()){
        winner = player1;
        loser = player2;
        loserIndex = playerIndex2;
    }
    else {
        winner = player2;
        loser = player1;
        loserIndex = playerIndex1;
    }
    endRound(winner, loser, loserIndex);
}

void Game::gameLoop()
{
    while (live_players.size() > 1) {
        battleRound();
    }
}

void Game::printFinalResults()
{
    for (auto p : players) {
        p->printStats();
    }
}
Game::~Game() 
{}