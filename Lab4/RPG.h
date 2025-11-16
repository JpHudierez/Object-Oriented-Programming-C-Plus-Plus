#pragma once
#include <string>
using namespace std;

class RPG {
    private:
        string name;
        
        int hits_taken;
    
        float luck;    

        float exp;

        int level;

    public: 
        RPG();
        RPG(string name, int hits_taken, float luck, float exp, int level);

        bool isAlive() const;
        void setHitsTaken(int new_hits);
        string getName() const;
        int getHitsTaken() const;
        float getLuck() const;
        float getExp() const;
        int getLevel() const;

        void setName(string name);
        void updateExpLevel();
        void attack (RPG*opponent);
        void printStats();

        ~RPG();
};
