#include "BlackjackGame.h"
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0)));
    BlackjackGame game(100.0); // Initial balance set to $100
    game.startGame();
    return 0;
}
