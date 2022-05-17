//
// Created by feder on 5/18/2022.
//
#include <iostream>
#include "sleep.h"
#include "card.h"
#include "player.h"
#include <vector>
#pragma once

class game{
    int round;
    int turn;
public:
    game(int round, bool turn);

    friend std::ostream &operator<<(std::ostream &os, const game &game);

    std::vector<card> starting_deck();

    void start();
};

