#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster {
public:
    Monster(const std::string& name, int health, int attack);
    
    std::string getName() const;
    int getHealth() const;
    int getAttack() const;

private:
    std::string name;  // Name of the monster
    int health;        // Health of the monster
    int attack;        // Attack points of the monster
};

#endif // MONSTER_H
