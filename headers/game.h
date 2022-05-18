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
    game() = default;
public:
    static int round, turn;
    game(const game&) = delete;
    game& operator=(const game&) = delete;
    static game& get_game();
    std::vector<card> starting_deck();

    void start();
};

