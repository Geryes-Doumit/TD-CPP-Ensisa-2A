#include <iostream>
using namespace std;

#ifndef CARD_H
#define CARD_H

class Card {
    public:
        string CardName;
        
    public:
        virtual void displayInfo() const = 0;
        virtual string getCardType() const = 0;
};

#endif