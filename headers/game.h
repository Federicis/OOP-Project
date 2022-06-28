//
// Created by feder on 5/18/2022.
//
#include <iostream>
#include "card.h"
#include "player.h"
#include <vector>
#include <thread>
#include <chrono>
#pragma once

class game{
    game() = default;
    static int round, turn;
public:
    game(const game&) = delete;
    game& operator=(const game&) = delete;
    static game& get_game();
    std::vector<card> starting_deck();

    void start();
};

