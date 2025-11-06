#ifndef RPG_H
#define RPG_H

#include <string>
using std::string;

const int   INVENTORY_SIZE = 10;
const float HIT_FACTOR     = 0.05f;
const int   MAX_HITS_TAKEN = 3;

class RPG {
public:
    RPG();
    RPG(string name, int hits_taken, float luck, float exp, int level);

    void  setHitsTaken(int new_hits);
    bool  isAlive() const;

    string getName() const;
    int    getHitsTaken() const;
    float  getLuck() const;
    float  getExp() const;
    int    getLevel() const;

//Added for Lab 4
void setname (string newname); //rename the RPG
void updateExpLevel();
void attack (RPG* opponent); //tries to hit opponent
void printStats();
~RPG(); //destructor

private:
    string name;
    int    hits_taken;
    float  luck;
    float  exp;
    int    level;
};

#endif
