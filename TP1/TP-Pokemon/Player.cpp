#include "Player.h"

Player::Player(string playerName) {
    this->playerName = playerName;
}

void Player::addCardToBench(Card* card) {
    this->bench.push_back(card);
}

void Player::displayBench() const {
    cout << "Bench cards for Player " << this->playerName << ":" << endl;
    for (int i = 0; i < this->bench.size(); i++) {
        this->bench[i]->displayInfo();
    }
}

void Player::displayAction() const {
    cout << "Action cards for Player " << this->playerName << ":" << endl;
    for (int i = 0; i < this->action.size(); i++) {
        this->action[i]->displayInfo();
    }
}

void Player::activatePokemonCard(int index) {
    if (index < 0 || index >= this->bench.size()) {
        cout << "Invalid index" << endl;
        return;
    }
    if (this->bench[index]->getCardType() != "Pokemon") {
        cout << "Invalid card type" << endl;
        return;
    }
    PokemonCard* pokemon = dynamic_cast<PokemonCard*>(this->bench[index]);
    cout << this->playerName << " is activating a Pokémon Card: " << pokemon->CardName << endl;
    this->action.push_back(pokemon);
    this->bench.erase(this->bench.begin() + index);
}

void Player::attachEnergyCard(int indexPokemon, int indexEnergy) {
    if (indexPokemon < 0 || indexPokemon >= this->action.size()) {
        cout << "Invalid index" << endl;
        return;
    }
    if (indexEnergy < 0 || indexEnergy >= this->bench.size()) {
        cout << "Invalid index" << endl;
        return;
    }
    if (this->bench[indexEnergy]->getCardType() != "Energy") {
        cout << "Invalid card type" << endl;
        return;
    }
    // attach energy card to pokemon
    PokemonCard* pokemon = dynamic_cast<PokemonCard*>(this->action[indexPokemon]);
    EnergyCard* energy = dynamic_cast<EnergyCard*>(this->bench[indexEnergy]);
    cout << this->playerName << " is attaching an Energy Card of type " << energy->energyType << " to the Pokémon " << pokemon->CardName << endl;
    pokemon->attachEnergy();

    // remove energy card from bench
    this->bench.erase(this->bench.begin() + indexEnergy);
}

void Player::attack(int indexPokemon1, int indexAttack, Player& player, int indexPokemon2) {
    if (indexPokemon1 < 0 || indexPokemon1 >= this->action.size()) {
        cout << "Invalid index" << endl;
        return;
    }
    if (indexPokemon2 < 0 || indexPokemon2 >= player.action.size()) {
        cout << "Invalid index" << endl;
        return;
    }

    PokemonCard* pokemon1 = dynamic_cast<PokemonCard*>(this->action[indexPokemon1]);
    PokemonCard* pokemon2 = dynamic_cast<PokemonCard*>(player.action[indexPokemon2]);

    cout << this->playerName << " is attacking " << player.playerName << "'s " << pokemon2->CardName;
    cout << " with the Pokémon " << pokemon1->CardName;
    cout << " using " << get<1>(pokemon1->attacks[indexAttack]) << endl;

    pokemon1->attack(indexAttack, pokemon2);

    cout << "Reducing " << get<2>(pokemon1->attacks[indexAttack]) << " HP ";
    cout << "from "<< player.playerName << "'s " << pokemon2->CardName << endl;
    // check if pokemon is dead
    if (pokemon2->hp <= 0) {
        cout << "Pokemon " << pokemon2->CardName << " is dead !" << endl;
        player.action.erase(player.action.begin() + indexPokemon2);
    }
    else {
        cout << "Pokémon " << pokemon2->CardName << " has " << pokemon2->hp << " HP left" << endl;
    }
}

void Player::useTrainer(int indexTrainer) {
    if (indexTrainer < 0 || indexTrainer >= this->bench.size()) {
        cout << "Invalid index" << endl;
        return;
    }
    if (this->bench[indexTrainer]->getCardType() != "Trainer") {
        cout << "Invalid card type" << endl;
        return;
    }
    TrainerCard* trainer = dynamic_cast<TrainerCard*>(this->bench[indexTrainer]);

    cout << this->playerName << " is using a Trainer Card with the effect: \"";
    cout << trainer->trainerEffect << "\"" << endl;

    trainer->healAllPokemon(this->bench, this->action);
    this->bench.erase(this->bench.begin() + indexTrainer);
}