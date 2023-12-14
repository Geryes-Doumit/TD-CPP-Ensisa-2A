#include <iostream>
#include <tuple>
#include <vector>
#include "Card.h"
using namespace std;

#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

class PokemonCard : public Card {
    public:
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        int currentEnergy;
        vector<tuple<int, string, int>> attacks;
        // attacks conatin : energyCost, description, damageDealt
        
    public:
        PokemonCard(string cardName, string pokemonType, 
                    string familyName, int evolutionLevel, int maxHP, 
                    int energyCost1, string description1, int damageDealt1,
                    int energyCost2, string description2, int damageDealt2);
        
        virtual void displayInfo() const;
        virtual string getCardType() const;

        void heal();
        void attachEnergy();
        void attack(int indexAttack, PokemonCard* target);
        void checkHP();
};

#endif