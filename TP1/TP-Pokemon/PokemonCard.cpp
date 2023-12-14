#include "PokemonCard.h"

PokemonCard::PokemonCard(string cardName, string pokemonType, string familyName, int evolutionLevel, int maxHP, int energyCost1, string description1, int damageDealt1, int energyCost2, string description2, int damageDealt2) {
    this->CardName = cardName;
    this->pokemonType = pokemonType;
    this->familyName = familyName;
    this->evolutionLevel = evolutionLevel;
    this->maxHP = maxHP;
    this->hp = maxHP;
    this->currentEnergy = 0;
    this->attacks.push_back(make_tuple(energyCost1, description1, damageDealt1));
    this->attacks.push_back(make_tuple(energyCost2, description2, damageDealt2));
}

void PokemonCard::displayInfo() const {
    cout << "Pokemon Card - ";
    cout << "Name: " << this->CardName << ", ";
    cout << "Type: " << this->pokemonType << ", ";
    cout << "Evolution Level: " << this->evolutionLevel;
    cout << " of the family \"" << this->familyName << ", ";
    cout << "HP: " << this->hp << "\"" << endl;
    cout << "Card's current energy storage: " << this->currentEnergy << endl;
    cout << "Attacks:" << endl;
    for (int i = 0; i < this->attacks.size(); i++) {
        cout << "Attack #" << i << ": " << endl;
        cout << "Attack cost: " << get<0>(this->attacks[i]) << endl;
        cout << "Attack description: " << get<1>(this->attacks[i]) << endl;
        cout << "Attack damage: " << get<2>(this->attacks[i]) << endl;
    }
}

string PokemonCard::getCardType() const {
    return "Pokemon";
}

void PokemonCard::heal() {
    this->hp = this->maxHP;
}

void PokemonCard::attachEnergy() {
    this->currentEnergy++;
}

void PokemonCard::attack(int indexAttack, PokemonCard* target) {
    if (indexAttack < 0 || indexAttack >= this->attacks.size()) {
        cout << "Invalid index" << endl;
        return;
    }
    if (this->currentEnergy < get<0>(this->attacks[indexAttack])) {
        cout << "Not enough energy" << endl;
        return;
    }
    this->currentEnergy -= get<0>(this->attacks[indexAttack]);
    target->hp -= get<2>(this->attacks[indexAttack]);
}