#ifndef CARDDECK_H
#define CARDDECK_H

class CardDeck {
private:
    int *deck;
    int deckSize;

public:
    CardDeck(int size = 52);
    ~CardDeck();
    int drawCard();
    void shuffleDeck();
};

#endif // CARDDECK_H
