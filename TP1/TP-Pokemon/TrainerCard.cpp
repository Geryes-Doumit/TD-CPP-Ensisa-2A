#include "TrainerCard.h"

TrainerCard::TrainerCard(string trainerName, string trainerEffect) {
    this->CardName = trainerName;
    this->trainerEffect = trainerEffect;
}

void TrainerCard::displayInfo() const {
    cout << "Trainer Card - ";
    cout << "Name: " << this->CardName << ", ";
    cout << "Effect: " << this->trainerEffect << endl;
}

void TrainerCard::healAllPokemon(vector<Card*> bench, vector<PokemonCard*> action) {
    for (int i = 0; i < bench.size(); i++) {
        if (bench[i]->getCardType() == "Pokemon") {
            PokemonCard* pokemon = dynamic_cast<PokemonCard*>(bench[i]);
            pokemon->heal();
        }
    }
    for (int i = 0; i < action.size(); i++) {
        action[i]->heal();
    }
}

string TrainerCard::getCardType() const {
    return "Trainer";
}