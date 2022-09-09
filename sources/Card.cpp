//
// Created by feder on 5/17/2022.
//

#include "../headers/Card.h"

Card::Card(int level) : level(level) {}

int Card::getLevel() const {
    return level;
}

std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << "level: " << card.level;
    return os;
}

void Card::levelup(){
    level++;
}

Card::~Card() {

}
