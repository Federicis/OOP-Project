//
// Created by feder on 5/17/2022.
//

#pragma once
#include <iostream>
#include <vector>
#include "card.h"

class player{

    int level_points;
    std::vector<card> cards;
    int coins;
    int hp;
public:
    player(int levelPoints, const std::vector<card> &cards, int coins, int hp);

    player(const player& other);

    player& operator=(const player& other);

    friend std::ostream &operator<<(std::ostream &os, const player &player);

    ~player();
    void setup();
    void printdeck() const;
    void damage(int points);
    void heal(int points);
    int showcard(int turn) const;
    int getHP() const;
};
