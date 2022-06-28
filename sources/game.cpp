//
// Created by feder on 5/18/2022.
//
#include "../headers/game.h"
#define waitkey rlutil::anykey("Press any key to continue...\n")
using namespace std::chrono_literals;

int game::round = 0;
int game::turn = 0;
game& game::get_game(){
    static game game;
    return game;
}

std::vector<card> game::starting_deck(){
    std::vector<card> deck(5, card{0});
    return deck;
}

void game::start() {
    std::cout << "Tutorial:\n"
                 "      Fiecare jucator incepe cu 7 puncte de nivel si 5 carti de nivel 0. Trebuie sa distribuiti punctele de nivel intre\n cele 5 carti. O carte poate avea minim nivel 1 si maxim nivel 2 la inceputul jocului.\n\n\n";
    waitkey;
    rlutil::cls();
    player P1{7, starting_deck(), 0, 10}, P2{P1};

    std::cout << "Primul jucator isi alege cartile, al doilea jucator nu se mai uita la ecran:\n";
    waitkey;
    P1.setup();
    rlutil::cls();
    std::cout << "Pachetul tau este:\n";
    P1.printdeck();
    waitkey;
    rlutil::cls();
    std::cout << "Al doilea jucator isi alege cartile, primul jucator nu se mai uita la ecran:\n";
    waitkey;
    P2.setup();
    std::cout << "Pachetul tau este:\n";
    P2.printdeck();
    waitkey;
    rlutil::cls();
    std::cout << "Tutorial:\n"
                 "Acum ca set-up ul e gata, incep rundele. In fiecare runda playerii se vor duela cu cartile pe care le au. Fiecare carte se va lupta cu cartea oponentului de pe aceeasi pozitie. Castiga cartea cu nivel mai mare. In caz de egalitate, primul player care isi apasa tasta asignata castiga.(Q pentru P1, P pentru P2)\n ";
    while(P1.getHP() > 0 && P2.getHP() > 0){
        this->round++;
        if(this->round > 1) return;
        this->turn = 1;
        int scorP1 = 0, scorP2 = 0;
        std::cout << "RUNDA " << round << '\n';
        waitkey;
        std::cout << "HP P1: " << P1.getHP() << '\n';
        std::cout << "HP P2: " << P2.getHP() << '\n';
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
            std::cout << "PLAYER 1    |" << P1.showcard(turn - 1) << "|        ||        |"  <<P2.showcard(turn - 1) << "|    PLAYER 2\n";
            if(P1.showcard(turn - 1) == P2.showcard(turn - 1)){
                std::cout << "EGAL\n";
                bool ok = false;
                do {
                    if (kbhit()) {
                        char k = getch(); // Get character
                        if(k == 'p'){
                            std::cout << "P2 a fost primul!\n";
                            scorP2++;
                            ok = 1;
                        }
                        else if(k == 'q'){
                            std::cout << "P1 a fost primul!\n";
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
                        std::cout << "P1 pierde \n";
                        scorP2++;
                        ok = 0;
                        k = ' ';
                    }
                    if (k == 'p') {
                        std::cout << "P2 pierde\n";
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
            std::cout << "SCOR\n" << "P1 ->" << scorP1 << "                 " << scorP2 <<"<-P2\n";
            waitkey;
            this->turn++;
        }
        if(scorP1 > scorP2){
            std::cout << "Congrats P1 ai castigat runda!\n"
                         "P1 si-a luat " << round << " damage.\n"
                                                     "P1 si-a luat " << round/2 << " heal^\n";
            P2.damage(round);
            P1.heal(round / 2);
        }
        else
        {
            std::cout << "Congrats P2 ai castigat runda!\n"
                         "P1 si-a luat " << round << " damage.\n"
                                                     "P2 si-a luat " << round/2 << " heal^\n";
            P1.damage(round);
            P2.heal(round / 2);
        }

    }
}