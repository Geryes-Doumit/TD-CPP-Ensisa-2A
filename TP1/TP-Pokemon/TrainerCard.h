#include <iostream>
#include <tuple>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"
using namespace std;

#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

class TrainerCard : public Card {
    public:
        string trainerEffect;
        
    public:
        TrainerCard(string trainerName, string trainerEffect);
        void healAllPokemon(vector<Card*> bench, vector<PokemonCard*> action);
        virtual void displayInfo() const;
        virtual string getCardType() const;
};

#endif