#include "headers/card.h"
#include "headers/game.h"

int main() {
    game& joc = game::get_game();
    try{
        joc.start();
    }
    catch(std::runtime_error& e){
        std::cerr << "Runtime error: " << e.what();
        return 1;
    }
    return 0;
}
