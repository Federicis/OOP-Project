//
// Created by feder on 5/17/2022.
//

#pragma once
#include <iostream>
#include <vector>
#include "card.h"

class shop{
    std::vector<card> cards;
public:
    explicit shop(const std::vector<card> &cards);

    friend std::ostream &operator<<(std::ostream &os, const shop &shop);
};

