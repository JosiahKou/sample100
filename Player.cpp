#include "Player.h"

// Default constructor
Player::Player() 
    : classType("Basic"), gold(0), maxHealth(100), currentHealth(100) {
    moves.emplace_back("punch", 10, 1);
    moves.emplace_back("kick", 5, 2);
}

// Parameterized constructor
Player::Player(const string& classType) 
    : classType(classType), gold(0), currentHealth(0) {
    setClassStats();
}

// Destructor
Player::~Player() {
    // No dynamic memory to free, but can include cleanup if needed
}

// Copy constructor
Player::Player(const Player& other)
    : classType(other.classType), gold(other.gold), maxHealth(other.maxHealth),
      currentHealth(other.currentHealth), moves(other.moves) {}

// Copy assignment operator
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        classType = other.classType;
        gold = other.gold;
        maxHealth = other.maxHealth;
        currentHealth = other.currentHealth;
        moves = other.moves;
    }
    return *this;
}

// Function to set stats based on class type
void Player::setClassStats() {
    if (classType == "Swordmaster") {
        maxHealth = 120; 
        currentHealth = maxHealth; 
        moves.emplace_back("punch", 10, 1);
    } else if (classType == "Tank") {
        maxHealth = 150; 
        currentHealth = maxHealth; 
        moves.emplace_back("punch", 10, 1);
    } else if (classType == "Archer") {
        maxHealth = 90; 
        currentHealth = maxHealth; 
        moves.emplace_back("punch", 10, 1);
    } else if (classType == "Assassin") {
        maxHealth = 80; 
        currentHealth = maxHealth; 
        moves.emplace_back("punch", 10, 1);
    } else if (classType == "Mage") {
        maxHealth = 70; 
        currentHealth = maxHealth; 
        moves.emplace_back("punch", 10, 1);
    } else {
        maxHealth = 100; 
        currentHealth = maxHealth; 
        moves.emplace_back("punch", 10, 1);
        moves.emplace_back("kick", 5, 2);
    }
}

// Display player health
void Player::displayHealth() const {
    cout << "Player Health: " << currentHealth << "/" << maxHealth << endl;
}

// Display player moves
void Player::displayMoves() const {
    cout << "Player Moves: " << endl;
    int i = 0;
    for (i = 0; i < moves.size(); ++i) {
        cout << i + 1 << ": " << moves[i].GetName() << endl;
    }
    cout << i + 1 << ": Back" << endl;
}

void Player::displayItems() const {
    cout << "Player Items: " << endl;
    int i = 0;
    for (i = 0; i < moves.size(); ++i) {
        cout << i + 1 << ": " << items[i] << endl;
    }
    cout << i + 1 << ": Back" << endl;
}

int Player::getNumItems() {
    return items.size();
}

int Player::getNumMoves() {
    return moves.size();
}