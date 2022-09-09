//
// Created by feder on 5/17/2022.
//

#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include <climits>

class Player{
    std::string name;
    int level_points;
    std::vector<Card*> cards;
    int coins;
    int hp;

public:

    std::string getName();

    Player(std::string name, int levelPoints, std::vector<Card*> cards, int coins, int hp);

    Player(const Player& other);

    Player& operator=(const Player& other);

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    ~Player();
    friend void swap(Player& first, Player& second);
    void setup();
    void printdeck() const;
    void damage(int points);
    void heal(int points);
    int showcard(int turn) const;
    int getHP() const;

};
