#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>

#include "Attack.h"

using namespace std;

class Player {
public:
    // Constructors
    Player(); // Default constructor
    Player(const string& classType); // Parameterized constructor

    // Destructor
    ~Player();

    // Copy constructor
    Player(const Player& other);

    // Copy assignment operator
    Player& operator=(const Player& other);

    // Display player info
    void displayHealth() const;
    void displayMoves() const;
    void displayItems() const;
    int getNumItems();
    int getNumMoves();

private:
    string classType;
    int gold;
    int maxHealth;
    int currentHealth;
    vector<Attack> moves;
    vector<string> items;

    // Function to set stats based on class type
    void setClassStats();
};

#endif // PLAYER_H
