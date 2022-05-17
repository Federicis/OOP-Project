//
// Created by feder on 5/17/2022.
//
#pragma once
#include <iostream>

class card{
    int level;
public:
    explicit card(int level);

    int getLevel() const;

    friend std::ostream &operator<<(std::ostream &os, const card &card);

    void levelup();

    virtual ~card();
};


