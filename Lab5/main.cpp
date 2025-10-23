#include <iostream>
#include "Mewtwo.h"
using namespace std;

int main() 
{

    vector<string> pokemonType;
    pokemonType.push_back("Psychic");

    vector<string> skills;
    skills.push_back("Confusion");
    skills.push_back("Psybeam");

    cout << "----- Contructor Created -----\n";

    Mewtwo mew = Mewtwo("Mewtwo", 120, 130, 90, pokemonType, skills);

    cout << "\n----- Direct Speak -----\n";
    mew.speak();

    Pokemon * p1 = &mew;
    cout << "\n----- Speak called from Pokemon Pointer -----\n";
    (*p1).speak();

    Mewtwo * c1 = &mew;
    cout << "\n----- Speak called from Mewtwo Pointer -----\n";
    (*c1).speak();

    cout << "\n----- Print Stats -----\n";
    mew.printStats();
}