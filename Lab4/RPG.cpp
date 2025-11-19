#include "RPG.h"
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

RPG::RPG() {

    name = "NPC";
    hits_taken = 0;
    luck = 0.1f;
    exp = 0.0f;
    level = 1;
}

RPG::RPG(string name, int hits_taken, float luck, float exp, int level) {
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}

bool RPG::isAlive() const{
    return hits_taken < 3;
}

string RPG::getName() const {
    return name;
}

int RPG::getHitsTaken() const {
    return hits_taken;
}

float RPG::getLuck() const{
    return luck;
}

float RPG::getExp() const{
    return exp;
}

int RPG::getLevel() const {
    return level;
}

void RPG::setHitsTaken(int new_hits) {
    hits_taken = new_hits;
}

void RPG::setName(string name) {
    this->name = name;
}

void RPG::updateExpLevel() {
    exp += 50.0f;

    if (exp >= 100.0f){
        level += 1;
        exp = 0.0f;
        luck += 0.1f;
    }
}

void RPG::attack(RPG* opponent) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    float random_num = dis(gen);

    const float HIT_FACTOR = 0.5f;

    bool hit = (random_num > HIT_FACTOR * opponent->luck);

    if (hit) {
        opponent->setHitsTaken(opponent->getHitsTaken() + 1);
    }
}

void RPG::printStats() {
cout << fixed << setprecision(6);

    cout << "Name: " << name
         << "\tHits Taken: " << hits_taken
         << "\tLuck: " <<luck
         << "\tExp: " << exp
         << "\tLevel: " << level
         << "\tStatus: " << (isAlive() ? "Alive" : "Dead")
         << endl;
}
RPG::~RPG() {
}