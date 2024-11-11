#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int capacity) : capacity(capacity), handSize(0), hasAce(false) {
    hand = new int[capacity];
}

Player::~Player() {
    delete[] hand;
}

void Player::addCard(int card) {
    if (handSize < capacity) {
        hand[handSize++] = card;
        if (card == 11) hasAce = true;
    }
}

int Player::handValue() const {
    int total = 0;
    int aceCount = 0;
    for (int i = 0; i < handSize; ++i) {
        total += hand[i];
        if (hand[i] == 11) aceCount++;
    }
    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }
    return total;
}

void Player::displayHand() const {
    cout << "Hand: ";
    for (int i = 0; i < handSize; ++i) {
        cout << hand[i] << " ";
    }
    cout << "Total: " << handValue() << endl;
}

bool Player::checkBust() const {
    return handValue() > 21;
}

bool Player::checkBlackjack() const {
    return handValue() == 21 && handSize == 2;
}
