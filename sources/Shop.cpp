//
// Created by feder on 5/17/2022.
//
#include "../headers/Shop.h"

Shop::Shop(const std::vector<Card> &cards) : cards(cards) {}

std::ostream &operator<<(std::ostream &os, const Shop &shop) {
    os << "cards: ";
    for( auto card : shop.cards){
        os << card << " ";
    }
    return os;
}
