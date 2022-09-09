//
// Created by feder on 5/17/2022.
//
#include "../headers/Player.h"
#include "../headers/Ace.h"

#include <utility>

std::string Player::getName(){
    return this->name;
}

Player::Player(std::string name, int levelPoints, std::vector<Card*> cards, int coins, int hp) : name(std::move(
        name)), level_points(levelPoints), cards(std::move(cards)), coins(coins), hp(hp) {}

Player::Player(const Player& other) : level_points{other.level_points}, cards{other.cards}, coins{other.coins}, hp{other.hp} {}

Player& Player::operator=(const Player& other){
    level_points = other.level_points;
    cards = other.cards;
    coins = other.coins;
    hp = other.hp;
    return *this;
}

void swap(Player& first, Player& second){
    using std::swap;
    swap(first.level_points, second.level_points);
    swap(first.cards, second.cards);
    swap(first.coins, second.coins);
    swap(first.hp, second.hp);
}

Player::~Player() = default;

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "level_points: " << player.level_points << " cards: ";

    for (const auto &card: player.cards)
        os << card << " ";

    os << " coins: " << player.coins
       << " hp: " << player.hp;
    return os;
}

void Player::setup(){
    while(this->level_points) {
        int i = 0;
        std::cout << "Pachet:\n";
        for(auto card : this->cards){
            i++;
            std::cout <<i << ". " << card->getLevel() <<'\n';
        }
        std::cout << "Introdu un numar intre 1 si 5 pentru a adauga un punct in cartea respectiva\n";
        int ord;
        bool ok = false;

        do
        {
            ok = false;
            if(std::cin >> ord){
                if(ord < 1 || ord > 5){
                    std::cout << "Numarul nu este in intervalul cerut.\n Try again \n";
                }
                else if(this->cards[ord - 1]->getLevel() == 2) {
                    std::cout << "Alege o carte cu mai putine puncte\n Try again\n";
                }
                else ok = true;
            }
            else{
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Error. Try again.\n";
            }
        }
        while(!ok);
        this->cards[ord - 1]->levelup();
        if(dynamic_cast<Ace *> (cards[ord - 1])){
            std::cout << "Felicitari! Ai gasit AS-ul.\n";
        }
        this->level_points--;
    }
}
void Player::printdeck() const{
    int i = 0;
    for(auto card : cards){
        i++;
        std::cout<<"Cartea " << i << ": " << card->getLevel() << '\n';
    }
}
void Player::damage(int points){
    this->hp -= points;
}

void Player::heal(int points){
    this->hp += points;
}

int Player::showcard(int turn) const{
    return this->cards[turn]->getLevel();
}

int Player::getHP() const {
    return hp;
}



