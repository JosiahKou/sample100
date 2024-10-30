#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "Player.h"
#include "Stage.h"

using namespace std;

struct areaName {
    string name;
    bool went = false;
};

void displayTextSlowly(const string&, int, int);

void stageSetter(vector<areaName>&);
string stageSelection(vector<areaName>&);
void battleSystem(Stage&, Player&);
void attackChoice(Stage&, Player&);
void itemChoice(Stage&, Player&);
void AttackMonster(int, Stage&, Player&);

//game state
void intro();

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<areaName> areaNames;
    stageSetter(areaNames);

    intro();
}

void intro() {
    string message;
    
    message = "Welcome to the Path of Pain.";
    displayTextSlowly(message, 10, 200);
    message = "I doubt you will make it far.";
    displayTextSlowly(message, 10, 200);
    message = "Let's test out your skill.";
    displayTextSlowly(message, 10, 1000);
    cout << endl;

    Player player;

    Stage introStage(0, "Training Grounds");  // Create a basic stage with level 1
    battleSystem(introStage, player);
}

void displayTextSlowly(const std::string& text, int delayMilliseconds, int endDelayMilliseconds) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMilliseconds));
    }
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(endDelayMilliseconds));
}

void stageSetter(vector<areaName>& areaNames)
{
    areaNames.push_back({"Forest", false});
    areaNames.push_back({"Plains", false});
    areaNames.push_back({"Castle", false});
    areaNames.push_back({"Mansion", false});
    areaNames.push_back({"Lakeside", false});
}

string stageSelection(vector<areaName>& areaNames)
{
    int i = rand() % areaNames.size();

    while (areaNames[i].went == true)
    {
        i++;
    }

    areaNames[i].went = true;
    return areaNames[i].name;
}

void battleSystem(Stage& stage, Player& player)
{
    int moveChoice;
    bool valid = false;
    stage.startStage(player);
    cout << "Choose an action:" << endl;
    cout << "1. Attack" << endl
        << "2. Items"  << endl;
    cin >> moveChoice;

    while (!valid) {
        if (moveChoice == 1)
        {
            valid = true;
            attackChoice(stage, player);
            return;
        }
        else if (moveChoice == 2)
        {
            valid = true;
            itemChoice(stage, player);
            return;
        }
        else
        {
            cout << "Not a valid option." << endl;
        }
    }
}

void attackChoice(Stage& stage, Player& player)
{
    int moveChoice;
    player.displayMoves();
    bool valid = false;
    cin >> moveChoice;
    if (moveChoice == player.getNumMoves()+1) {
        battleSystem(stage, player);
    }
    if (moveChoice < 1 || moveChoice > player.getNumMoves()) {
        cout << "Invalid move choice. Try again." << endl;
        battleSystem(stage, player); // Return to the main battle system if invalid
        return;
    }
}

void itemChoice(Stage& stage, Player& player)
{
    int moveChoice;
    if (player.getNumItems() == 0)
    {
        cout << "You have no items" << endl;
        battleSystem(stage,player);
        return;
    }
    player.displayItems();
    bool valid = false;
    cin >> moveChoice;
    if (moveChoice == 1)
    {
        AttackMonster(moveChoice, stage, player);
        return;
    }
    else if (moveChoice == 2)
    {
        AttackMonster(moveChoice, stage, player);
        return;
    }
    else if (moveChoice == 3)
    {
        battleSystem(stage,player);
        return;
    }
}

void AttackMonster(int moveChoice, Stage& stage, Player& player)
{
    
}
