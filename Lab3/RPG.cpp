#include "RPG.h"

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
