//
// Created by feder on 9/9/2022.
//

#include "../headers/Ace.h"

Ace::Ace(int level) : card(level) {}

void Ace::levelup() {
    card::levelup();
    card::levelup();
}
