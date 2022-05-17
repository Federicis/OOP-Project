#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

class card{
    int level;
public:
    card(int level) : level(level) {}

    int getLevel() const {
        return level;
    }

    friend std::ostream &operator<<(std::ostream &os, const card &card) {
        os << "level: " << card.level;
        return os;
    }

    void levelup(){
        level++;
    }
};

class player{

    int level_points;
    std::vector<card> cards;
    int coins;
    int hp;
public:
    player(int levelPoints, const std::vector<card> &cards, int coins, int hp) : level_points(levelPoints),
                                                                                 cards(cards), coins(coins), hp(hp) {}

    player(const player& other) : level_points{other.level_points}, cards{other.cards}, coins{other.coins}, hp{other.hp} {}

    player& operator=(const player& other){
        level_points = other.level_points;
        cards = other.cards;
        coins = other.coins;
        hp = other.hp;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const player &player) {
        os << "level_points: " << player.level_points << " cards: ";
        for(auto card : player.cards){
            os << card << " ";
        }
        os << " coins: " << player.coins
           << " hp: " << player.hp;
        return os;
    }

    virtual ~player() {

    }
    void setup(){
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
                if (ord < 1 || ord > 5) {
                    std::cout << "Numarul nu se regaseste in intervalul cerut\n Try Again\n";
                    ok = false;
                }
                else if(this->cards[ord - 1].getLevel() == 2) {
                    std::cout << "Alege o carte cu mai putine puncte\n Try again\n";
                    ok = 0;
                }
            }
            while(!ok);
            this->cards[ord - 1].levelup();
            this->level_points--;
        }
    }
    void printdeck(){
        int i = 0;
        for(auto card : cards){
            i++;
            std::cout<<"Cartea " << i << ": " << card.getLevel() << '\n';
        }
    }
};

class shop{
    std::vector<card> cards;
public:
    shop(const std::vector<card> &cards) : cards(cards) {}

    friend std::ostream &operator<<(std::ostream &os, const shop &shop) {
        os << "cards: ";
        for( auto card : shop.cards){
            os << card << " ";
        }
        return os;
    }
};

class game{
    int round;
    bool turn;
public:
    game(int round, bool turn) : round(round), turn(turn) {}

    friend std::ostream &operator<<(std::ostream &os, const game &game) {
        os << "round: " << game.round << " turn: " << game.turn;
        return os;
    }
};

std::vector<card> starting_deck(){
    std::vector<card> deck;
    card c0{0};
    for(int i = 1; i <= 5; i++)
    {
        deck.push_back(c0);
    }
    return deck;
}

void start(){
    std::cout << "Tutorial:\n"
                 "      Fiecare jucator incepe cu 7 puncte de nivel si 5 carti de nivel 0. Trebuie sa distribuiti punctele de nivel intre\n cele 5 carti. O carte poate avea minim nivel 1 si maxim nivel 2 la inceputul jocului.\n\n\n" ;
    system("pause");
    system("CLS");
    player P1{7, starting_deck(), 0, 10}, P2{P1};
    game joc{0, 0};
    std::cout << "Primul jucator isi alege cartile, al doilea jucator nu se mai uita la ecran:\n";
    system("pause");
    P1.setup();
    system("CLS");
    std::cout << "Pachetul tau este:\n";
    P1.printdeck();
    system("pause");
    system("CLS");
    std::cout << "Al doilea jucator isi alege cartile, primul jucator nu se mai uita la ecran:\n";
    system("pause");
    P2.setup();
    std::cout << "Pachetul tau este:\n";
    P2.printdeck();
    system("pause");
    system("CLS");
    std::cout << "Urmeaza Runda 1:\n";
    system("pause");
    std::cout << P1 << '\n' << P2;
}

int main() {
    start();

    return 0;
}
