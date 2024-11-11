#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int *hand;
    int handSize;
    int capacity;
    bool hasAce;

public:
    Player(int capacity = 10);
    ~Player();
    void addCard(int card);
    int handValue() const;
    void displayHand() const;
    bool checkBust() const;
    bool checkBlackjack() const;
};

#endif // PLAYER_H
