#include <iostream>
#include <stdio.h>
#include "Mewtwo.h"

/**
 * @brief construct a new mewtwo:: mewtwo object
 * 
 */
Mewtwo::Mewtwo() : Pokemon() {
    type.push_back("Psychic");
    skills.push_back("Confusion");
    skills.push_back("Psybeam");

    cout << "Default Constructor (Mewtwo) \n";

}

/**
 * @brief construct a new mewtwo:: mewtwo object
 * 
 * @param hp
 * @param att
 * @param def
 * @param t
 * @param s
 */
Mewtwo::Mewtwo(string name, int hp, int att, int def, vector <string> t, vector<string> s)
: Pokemon(name, hp, att, def, t) {
type = t;
skills = s;

cout << "Overloaded Constructor (Mewtwo) \n";
}
/**
 * @brief says whatever mewtwo normally says
 * 
 */
void Mewtwo::speak() {
    cout << "Mewtwo! Mewtwo!\n";
}

/**
 * @brief calls print stats from pokemon and adds skills
 * 
 */
void Mewtwo::printStats() {
    Pokemon::printStats();
    cout << "Skills: ";
    for (int i = 0; i < skills.size(); i++) {
        cout << skills[i] << "\t";
    }
    cout << endl;
}