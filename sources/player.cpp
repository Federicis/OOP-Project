//
// Created by feder on 5/17/2022.
//
#include "../headers/player.h"

    player::player(int levelPoints, const std::vector<card> &cards, int coins, int hp) : level_points(levelPoints),
                                                                                 cards(cards), coins(coins), hp(hp) {}

    player::player(const player& other) : level_points{other.level_points}, cards{other.cards}, coins{other.coins}, hp{other.hp} {}

    player& player::operator=(const player& other){
        level_points = other.level_points;
        cards = other.cards;
        coins = other.coins;
        hp = other.hp;
        return *this;
    }

    void swap(player& first, player& second){
    using std::swap;
    swap(first.level_points, second.level_points);
    swap(first.cards, second.cards);
    swap(first.coins, second.coins);
    swap(first.hp, second.hp);
}

    player::~player() {}
     std::ostream &operator<<(std::ostream &os, const player &player) {
        os << "level_points: " << player.level_points << " cards: ";
        for(auto card : player.cards){
            os << card << " ";
        }
        os << " coins: " << player.coins
           << " hp: " << player.hp;
        return os;
    }

    void player::setup(){
        while(this->level_points) {
            int i = 0;
            std::cout << "Pachet:\n";
            for(auto card : this->cards){
                i++;
                std::cout <<i << ". " << card.getLevel() <<'\n';
            }
            std::cout << "Introdu un numar intre 1 si 5 pentru a adauga un punct in cartea respectiva\n";
            int ord;
            bool ok = false;

            do
            {
                ok = true;
                std::cin >> ord;
                while(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                    std::cout << "Error. Try again.\n";
                    std::cin >> ord;
                }
                if(ord < 1 || ord > 5){
                    ok = 0;
                    std::cout << "Numarul nu este in intervalul cerut.\n Try again \n";
                }
                if(ok)
                    if(this->cards[ord - 1].getLevel() == 2) {
                        std::cout << "Alege o carte cu mai putine puncte\n Try again\n";
                        ok = 0;
                    }
            }
            while(!ok);
            this->cards[ord - 1].levelup();
            this->level_points--;
        }
    }
    void player::printdeck() const{
        int i = 0;
        for(auto card : cards){
            i++;
            std::cout<<"Cartea " << i << ": " << card.getLevel() << '\n';
        }
    }
void player::damage(int points){
    this->hp -= points;
}

void player::heal(int points){
    this->hp += points;
}

int player::showcard(int turn) const{
    return this->cards[turn].getLevel();
}

int player::getHP() const {
    return hp;
}
