//
// Created by feder on 5/17/2022.
//

#pragma once
#include <iostream>
#include <vector>
#include "card.h"
#include <climits>

class player{
    std::string name;
    int level_points;
    std::vector<card*> cards;
    int coins;
    int hp;

public:

    std::string getName();

    player(std::string name, int levelPoints, std::vector<card*> cards, int coins, int hp);

    player(const player& other);

    player& operator=(const player& other);

    friend std::ostream &operator<<(std::ostream &os, const player &player);

    ~player();
    friend void swap(player& first, player& second);
    void setup();
    void printdeck() const;
    void damage(int points);
    void heal(int points);
    int showcard(int turn) const;
    int getHP() const;

};
