#ifndef STAGE_H
#define STAGE_H

#include <string>
#include <vector>
#include "Monster.h"
#include "Player.h"

using namespace std;

class Stage {
public:
    Stage(int level, const std::string& areaName);
    
    void startStage(Player);
    void addMonster(const Monster& monster);

private:
    int level;
    string areaName;
    vector<Monster> monsters;

    void initializeMonsters();  // Initialize monsters based on level and area
};

#endif // STAGE_H
