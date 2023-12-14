#include "EnergyCard.h"

EnergyCard::EnergyCard(string energyType) {
    this->CardName = "Energy";
    this->energyType = energyType;
}

void EnergyCard::displayInfo() const {
    cout << "Energy Card - ";
    cout << "Type: " << this->energyType << endl;
}

string EnergyCard::getCardType() const {
    return "Energy";
}