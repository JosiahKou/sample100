#include "Attack.h"

Attack::Attack(const string& name, int attack, int numHits)
    : name(name), attack(attack), numHits(numHits) {}
    
string Attack::GetName() const
{
    return name;
}