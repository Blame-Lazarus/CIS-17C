#include "CardDeck.h"
#include <cstdlib>
#include <ctime>

CardDeck::CardDeck(int size) {
    deckSize = size;
    deck = new int[deckSize];
    for (int i = 0; i < deckSize; ++i) {
        deck[i] = (i % 13) + 1; // Cards 1 to 13
    }
    shuffleDeck();
}

CardDeck::~CardDeck() {
    delete[] deck;
}

int CardDeck::drawCard() {
    int card = deck[--deckSize];
    if (card > 10) card = 10; // Face cards
    if (card == 1) card = 11; // Ace as 11 initially
    return card;
}

void CardDeck::shuffleDeck() {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = deckSize - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}
