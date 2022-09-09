//
// Created by feder on 5/17/2022.
//

#pragma once
#include <iostream>
#include <vector>
#include "Card.h"

class Shop{
    std::vector<Card> cards;
public:
    explicit Shop(const std::vector<Card> &cards);

    friend std::ostream &operator<<(std::ostream &os, const Shop &shop);
};

