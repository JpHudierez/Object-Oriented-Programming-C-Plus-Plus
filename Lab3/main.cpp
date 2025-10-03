#include <iostream>
#include <cstdio>
#include "RPG.h"
using namespace std;

int main() {
    RPG hero("KnightJP", 1, 0.25f, 42.0f, 2);

    RPG npc; // "NPC", 0 hits, 0.1 luck, 50 exp, level 1

    // Print hero
    printf("%s Current Stats\n", hero.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n",
           hero.getHitsTaken(), hero.getLuck(), hero.getExp(), hero.getLevel());

    // Print NPC
    printf("%s Current Stats\n", npc.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n",
           npc.getHitsTaken(), npc.getLuck(), npc.getExp(), npc.getLevel());

    // Demonstrate mutator + alive check 
    npc.setHitsTaken(2);            // not 3—keeps it clearly different
    hero.setHitsTaken(3);           // push hero to the limit to show false

    cout << "\nHits after combat demo:\n";
    cout << hero.getName() << ": " << hero.getHitsTaken() << "\n";
    cout << npc.getName()  << ": " << npc.getHitsTaken()  << "\n";

    cout << "\n0 = dead, 1 = alive\n";
    cout << "Hero alive? " << (hero.isAlive() ? 1 : 0) << "\n";
    cout << "NPC  alive? " << (npc.isAlive()  ? 1 : 0) << "\n";

    return 0;
}
