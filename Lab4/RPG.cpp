#include "RPG.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Default player (NPC) per spec
RPG::RPG()
    : name("NPC"), hits_taken(0), luck(0.1f), exp(50.0f), level(1) {}

RPG::RPG(string name, int hits_taken, float luck, float exp, int level)
    : name(name), hits_taken(hits_taken), luck(luck), exp(exp), level(level) {}

void RPG::setHitsTaken(int new_hits) { hits_taken = new_hits; }

bool RPG::isAlive() const { return hits_taken < MAX_HITS_TAKEN; }

string RPG::getName() const      { return name; }
int    RPG::getHitsTaken() const { return hits_taken; }
float  RPG::getLuck() const      { return luck; }
float  RPG::getExp() const       { return exp; }
int    RPG::getLevel() const     { return level; }

//Added for Lab 4

//Change the players name
void RPG::setname (string newName) {
    name = newName; 
}

//exp and level up
void RPG::updateExpLevel() {
    exp += 50.0f; 

    if (exp >= 100.0f) { // if XP bar is full
        level += 1;      //level up
        exp = 0.0f;      //reset exp
        luck += 0.1f;    // get luckier
    }
}

void RPG::attack (RPG* opponent) {

    float chance = static_cast<float>(rand()) / RAND_MAX; //random chance from 0.0 to 1.0
    
    //hit if chance is greater than opponent's luck
    if (chance > opponent->luck){
       opponent->setHitsTaken(opponent->getHitsTaken() + 1);
        
    }
}

void RPG::printStats() {
    cout<<name
        <<" | Hits Taken: " << hits_taken 
        <<" | Luck: " << luck
        <<" | Exp: " << exp 
        <<" | Level: " << level
        <<" | Status: " << (isAlive() ? "Alive" : "Dead")
        << '\n';
        
}

RPG::~RPG() {

}

