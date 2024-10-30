#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Attack {
    public:
    Attack(const string& name, int attack, int numHits);
    string GetName() const;

    private:
    string name;
    int attack;
    int numHits;
};

#endif 
