#include <iostream>
#include <tuple>
#include <vector>
#include "Card.h"
using namespace std;

#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

class EnergyCard : public Card {
    public:
        string energyType;
        
    public:
        EnergyCard(string energyType);
        virtual void displayInfo() const;
        virtual string getCardType() const;
};

#endif