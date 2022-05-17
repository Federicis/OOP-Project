//
// Created by feder on 5/17/2022.
//

#include "../headers/card.h"

 card::card(int level) : level(level) {}

int card::getLevel() const {
    return level;
}

 std::ostream &operator<<(std::ostream &os, const card &card) {
    os << "level: " << card.level;
    return os;
}

void card::levelup(){
    level++;
}

 card::~card() {

}
