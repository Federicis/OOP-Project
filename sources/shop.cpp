//
// Created by feder on 5/17/2022.
//
#include "../headers/shop.h"

    shop::shop(const std::vector<card> &cards) : cards(cards) {}

    std::ostream &operator<<(std::ostream &os, const shop &shop) {
        os << "cards: ";
        for( auto card : shop.cards){
            os << card << " ";
        }
        return os;
    }
