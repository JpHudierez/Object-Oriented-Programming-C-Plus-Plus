#include <iostream>
#include "Pokemon.h"


/**
 * @brief contruct a new pokemon:: pokemon object
 * 
 */

Pokemon::Pokemon(){
    name = "unidentified";
    hp = 0;
    attack = 0;
    defense = 0;
    cout << "Default Constructor (Pokemon) \n";
}

/**
 * @brief contruct a new pokemon:: pokemon object
 * 
 * @param name
 * @param hp
 * @param att
 * @param def
 * @param types  
 */
Pokemon::Pokemon(string name , int hp, int att, int def, vector<string> type){
    this->name = name;
    this->hp = hp;
    attack  = att;
    defense = def;
    type = type;
    cout << "Overloaded Contructor (Pokemon)\n";
}

/**
 * @brief says whatever this pokmeon normally says
 * 
 */
void Pokemon::speak(){
    cout << "...\n";
}


void Pokemon::printStats(){
    printf("Name:%s\t HP: %d\t DEF: %d\t ATT: %d\n", name.c_str(), hp, defense, attack);
   cout << "Type: ";
    for(int i=0; i< type.size(); i++){
        cout << type [i] << "\t";
    }
    cout << endl;
}