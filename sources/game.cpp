//
// Created by feder on 5/18/2022.
//
#include "../headers/game.h"
game::game(int round, bool turn) : round(round), turn(turn) {}

std::ostream &operator<<(std::ostream &os, const game &game) {
    os << "round: " << game.round << " turn: " << game.turn;
    return os;
}
std::vector<card> game::starting_deck(){
    std::vector<card> deck;
    card c0{0};
    for(int i = 1; i <= 5; i++)
    {
        deck.push_back(c0);
    }
    return deck;
}

void game::start() {
    std::cout << "Tutorial:\n"
                 "      Fiecare jucator incepe cu 7 puncte de nivel si 5 carti de nivel 0. Trebuie sa distribuiti punctele de nivel intre\n cele 5 carti. O carte poate avea minim nivel 1 si maxim nivel 2 la inceputul jocului.\n\n\n";
    system("pause");
    system("CLS");
    player P1{7, starting_deck(), 0, 10}, P2{P1};

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
    std::cout << "Tutorial:\n"
                 "Acum ca set-up ul e gata, incep rundele. In fiecare runda playerii se vor duela cu cartile pe care le au. Fiecare carte se va lupta cu cartea oponentului de pe aceeasi pozitie. Castiga cartea cu nivel mai mare. In caz de egalitate, primul player care isi apasa tasta asignata castiga.(LSHIFT pentru P1, RSHIFT pentru P2)\n ";
    while(P1.getHP() > 0 && P2.getHP() > 0){
        this->round++;
        this->turn = 1;
        int scorP1 = 0, scorP2 = 0;
        std::cout << "RUNDA " << round << '\n';
        system("pause");
        std::cout << "HP P1: " << P1.getHP() << '\n';
        std::cout << "HP P2: " << P2.getHP() << '\n';
        system("pause");
        while(turn <= 5){

            std::cout << "Cartea " << turn << '\n';
            Sleep(1000);
            std::cout << "3\n";
            Sleep(1000);
            std::cout << "2\n";
            Sleep(1000);
            std::cout << "1\n";
            Sleep(1000);
            std::cout << "PLAYER 1    |" << P1.showcard(turn - 1) << "|        ||        |"  <<P2.showcard(turn - 1) << "|    PLAYER 2\n";
            if(P1.showcard(turn - 1) == P2.showcard(turn - 1)){
                std::cout << "EGAL\n";
                bool ok = false;
                do {
                    if((GetKeyState(VK_RSHIFT) & 0x8000) && (GetKeyState(VK_LSHIFT) & 0x8000))
                    {
                        ok = false;
                        std::cout << "EGAL SE REPETA\n";
                    }
                    else{
                        if (GetKeyState(VK_LSHIFT) & 0x8000) {
                            std::cout << "P1 a fost primul!\n";
                            scorP1++;
                            ok = true;
                        }
                        if (GetKeyState(VK_RSHIFT) & 0x8000) {
                            std::cout << "P2 a fost primul!\n";
                            scorP2++;
                            ok = true;
                        }}
                }
                while(!ok);
                system("pause");
            }
            else {
                bool ok = true;
                if (!((GetKeyState(VK_RSHIFT) & 0x8000) && (GetKeyState(VK_LSHIFT) & 0x8000))) {
                if (GetKeyState(VK_LSHIFT) & 0x8000) {
                    std::cout << "P1 pierde \n";
                    scorP2++;
                    ok = 0;
                }
                if (GetKeyState(VK_RSHIFT) & 0x8000) {
                    std::cout << "P2 pierde\n";
                    scorP1++;
                    ok = 0;
                }
                }
                if(ok) {
                    if (P1.showcard(turn - 1) > P2.showcard(turn - 1)) {
                        scorP1++;
                    } else { scorP2++; }
                }
            }
            std::cout << "SCOR\n" << "P1 ->" << scorP1 << "                 " << scorP2 <<"<-P2\n";
            system("pause");
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