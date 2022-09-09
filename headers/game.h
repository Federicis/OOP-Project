//
// Created by feder on 5/18/2022.
//
#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
#include <vector>
#include <thread>
#include <chrono>
#include "rlutil.h"

class game{
    game() = default;
    static int round, turn;
    static void tutorial1();
    static void tutorial2(std::string P1, std::string P2);
    static void pick_cards(player &P);
    static void play(player &P1,player &P2);
    static std::string pick_name(int nr);
    static void roundRewards(player &P1, player &P2);
public:
    game(const game&) = delete;
    game& operator=(const game&) = delete;
    static game& get_game();
    static std::vector<card*> starting_deck();

    void start();
};

