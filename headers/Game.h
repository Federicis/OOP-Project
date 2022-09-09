//
// Created by feder on 5/18/2022.
//
#pragma once
#include <iostream>
#include "Card.h"
#include "Player.h"
#include <vector>
#include <thread>
#include <chrono>
#include "rlutil.h"

class Game{
    Game() = default;
    static int round, turn;
    static void tutorial1();
    static void tutorial2(std::string P1, std::string P2);
    static void pick_cards(Player &P);
    static void play(Player &P1,Player &P2);
    static std::string pick_name(int nr);
    static void roundRewards(Player &P1, Player &P2);
public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    static Game& get_game();
    static std::vector<Card*> starting_deck();

    void start();
};

