//
// Created by feder on 9/9/2022.
//

#include "../headers/Ace.h"

Ace::Ace(int level) : Card(level) {}

void Ace::levelup() {
    Card::levelup();
    Card::levelup();
}
