//
// Created by feder on 5/17/2022.
//
#pragma once
#include <iostream>

class Card{
    int level;
public:
    explicit Card(int level);

    int getLevel() const;

    friend std::ostream &operator<<(std::ostream &os, const Card &card);

    virtual void levelup();

    virtual ~Card();
};


