#include "headers/Card.h"
#include "headers/Game.h"

int main() {
    Game& joc = Game::get_game();
    try{
        joc.start();
    }
    catch(std::runtime_error& e){
        std::cerr << "Runtime error: " << e.what();
        return 1;
    }
    return 0;
}
