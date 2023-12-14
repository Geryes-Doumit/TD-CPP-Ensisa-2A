#include <iostream>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"
#include "TrainerCard.h"
#include "EnergyCard.h"

using namespace std;

class Player {
    public:
        string playerName;
        vector<Card*> bench;
        vector<PokemonCard*> action;

        Player(string playerName);
        void addCardToBench(Card* card);
        void displayBench() const;
        void displayAction() const;
        void activatePokemonCard(int index);
        void attachEnergyCard(int indexPokemon, int indexEnergy);
        void attack(int indexPokemon1, int indexAttack, Player& player, int indexPokemon2);
        void useTrainer(int indexTrainer);
};