#include "Stage.h"
#include <iostream>

// Constructor
Stage::Stage(int level, const std::string& areaName) 
    : level(level), areaName(areaName) {
    initializeMonsters();  // Initialize monsters when stage is created
}

// Initialize monsters based on the level and area
void Stage::initializeMonsters() {
    if (areaName == "Training Grounds") {
        if (level == 0) {
            monsters.emplace_back("dummy", 30, 5);  // Dummy monster with health 30 and attack 5
            monsters.emplace_back("dummy", 30, 5);
        }
    }
}

// Start the stage
void Stage::startStage(Player player) {
    cout << "===============================================" << endl;
    player.displayHealth();
    cout << level << " " << areaName << endl;
    cout << "Monsters in this stage:" << endl;

    for (int i = 0; i < monsters.size(); ++i) {
        const auto& monster = monsters[i];
        cout << (i + 1) << ". " << monster.getName() 
             << " (Health: " << monster.getHealth() 
             << ", Attack: " << monster.getAttack() << ")" << endl;
    }
}

// Add a monster to the stage
void Stage::addMonster(const Monster& monster) {
    monsters.push_back(monster);
}
