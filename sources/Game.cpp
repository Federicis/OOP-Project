//
// Created by feder on 5/18/2022.
//
#include "../headers/Game.h"
#include "../headers/Ace.h"

#define waitkey rlutil::anykey("Press any key to continue...\n")
using namespace std::chrono_literals;

int Game::round = 0;
int Game::turn = 0;

void Game::tutorial1(){
    std::cout << "Tutorial:\n"
                 "      Fiecare jucator incepe cu 4 puncte de nivel si 5 carti de nivel 0, dintre care una este un As ascuns(fiecare Level Up creste nivelul cartii cu 2 puncte). Trebuie sa distribuiti punctele de nivel intre\n cele 5 carti. O carte poate avea minim nivel 1 si maxim nivel 2 la inceputul jocului.\n\n\n";
    waitkey;
}

void Game::tutorial2(std::string P1, std::string P2){
        std::cout << "Tutorial:\n"
                     "Acum ca set-up ul e gata, incep rundele. In fiecare runda playerii se vor duela cu cartile pe care le au. Fiecare carte se va lupta cu cartea oponentului de pe aceeasi pozitie. Castiga cartea cu nivel mai mare. In caz de egalitate, primul Player care isi apasa tasta asignata castiga.(Q pentru " << P1 <<", P pentru " << P2 <<")\n ";
}

void Game::pick_cards(Player &P){
    waitkey;
    P.setup();
    rlutil::cls();
    std::cout << "Pachetul tau este:\n";
    P.printdeck();
    waitkey;
}

void Game::play(Player &P1, Player &P2){
    while(P1.getHP() > 0 && P2.getHP() > 0){
        round++;
        /// ----------- uncommment daca se foloseste date.txt -----------
        //        if(round > 1) return;
        turn = 1;
        int scorP1 = 0, scorP2 = 0;
        std::cout << "RUNDA " << round << '\n';
        waitkey;
        std::cout << "HP " << P1.getName() << ": " << P1.getHP() << '\n';
        std::cout << "HP " << P2.getName() << ": " << P2.getHP() << '\n';
        waitkey;
        while(turn <= 5){

            std::cout << "Cartea " << turn << '\n';
            std::this_thread::sleep_for(1000ms );
            std::cout << "3\n";
            std::this_thread::sleep_for(1000ms );
            std::cout << "2\n";
            std::this_thread::sleep_for(1000ms );
            std::cout << "1\n";
            std::this_thread::sleep_for(1000ms );
            std::cout << P1.getName() << "    |" << P1.showcard(turn - 1) << "|        ||        |"  <<P2.showcard(turn - 1) << "|    " << P2.getName() << '\n';
            if(P1.showcard(turn - 1) == P2.showcard(turn - 1)){
                std::cout << "EGAL\n";
                bool ok = false;
                do {
                    if (kbhit()) {
                        char k = getch(); // Get character
                        if(k == 'p'){
                            std::cout << P2.getName() << " a fost primul!\n";
                            scorP2++;
                            ok = 1;
                        }
                        else if(k == 'q'){
                            std::cout << P1.getName() <<" a fost primul!\n";
                            scorP1++;
                            ok = 1;
                        }
                        k = ' ';
                    }
                }
                while(!ok);
                waitkey;
            }
            else {
                bool ok = true;
                if (kbhit()) {
                    char k = getch();
                    if (k == 'q') {
                        std::cout << P1.getName() <<" pierde \n";
                        scorP2++;
                        ok = 0;
                        k = ' ';
                    }
                    if (k == 'p') {
                        std::cout << P2.getName() <<" pierde\n";
                        scorP1++;
                        ok = 0;
                        k = ' ';
                    }
                }
                if(ok) {
                    if (P1.showcard(turn - 1) > P2.showcard(turn - 1)) {
                        scorP1++;
                    } else { scorP2++; }
                }
            }
            std::cout << "SCOR\n" << P1.getName() <<" ->" << scorP1 << "                 " << scorP2 <<"<- " << P2.getName() << "\n";
            waitkey;
            turn++;
        }
        if(scorP1 > scorP2){
            roundRewards(P1, P2);
        }
        else
        {
            roundRewards(P2, P1);
        }
    }
}

Game& Game::get_game(){
    static Game game;
    return game;
}

std::vector<Card*> Game::starting_deck(){
    int random = rand() % 5 + 1;
    std::vector<Card*> deck{new Card(0), new Card(0), new Card(0), new Card(0), new Card(0)};
    deck[random - 1] = new Ace(0);
    return deck;
}

std::string Game::pick_name(int nr){
    std::string nume;
    std::cout << "Alege numele jucatorului " << nr <<": ";
    std::cin >> nume;
    return nume;
}

void Game::roundRewards(Player &P1, Player &P2) {
    std::cout << "Congrats " << P1.getName() <<", ai castigat runda!\n" <<
              P2.getName() <<" si-a luat " << round << " damage.\n" <<
              P1.getName() <<" si-a luat " << round/2 << " heal^\n";
    P2.damage(round);
    P1.heal(round / 2);
}

void Game::start() {
    tutorial1();
    rlutil::cls();
    Player P1{pick_name(1), 4, starting_deck(), 0, 10}, P2{pick_name(2), 4, starting_deck(), 0, 10};
    std::cout << P1.getName() << " isi alege cartile, " << P2.getName() << " nu se mai uita la ecran:\n";
    pick_cards(P1);
    rlutil::cls();
    std::cout << P2.getName() << " isi alege cartile," << P1.getName() <<" nu se mai uita la ecran:\n";
    pick_cards(P2);
    rlutil::cls();
    tutorial2(P1.getName(), P2.getName());
    play(P1, P2);
}

