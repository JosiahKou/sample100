#include "Monster.h"

// Constructor
Monster::Monster(const std::string& name, int health, int attack) 
    : name(name), health(health), attack(attack) {}

// Getter for monster name
std::string Monster::getName() const {
    return name;
}

// Getter for monster health
int Monster::getHealth() const {
    return health;
}

// Getter for monster attack
int Monster::getAttack() const {
    return attack;
}
