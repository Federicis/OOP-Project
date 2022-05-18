#include "headers/card.h"
#include "headers/game.h"

int main() {
    game& joc = game::get_game();
    joc.start();
    return 0;
}
