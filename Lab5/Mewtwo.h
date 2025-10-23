#ifndef MEWTWO_H
#define MEWTWO_H

#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

class Mewtwo : public Pokemon{
    public:
    //Contructors
    Mewtwo();
    Mewtwo(string name, int hp, int att, int def, vector <string> t, vector<string> s);
    //Mutator Functions
    void speak();
    void printStats();
    
    private:
    vector<string> skills;

};
#endif