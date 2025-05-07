#include "Animal.h"
#include <iostream>

using namespace std;

Animal::Animal() {
    this->setSpecies(None);
}

Animal::Animal(Species species) {
    this->setSpecies(species);
}

void Animal::makeSound() const{
    cout << "makeSound() not implemented" << endl;
}

void Animal::eat() const {
    cout << "eat() not implemented" << endl;
}

Species Animal::getSpecies() const {
    return this->species;
}

string Animal::getName() const {
    return this->name;
}

void Animal::setSpecies(Species toSpecies) {
    this->species = toSpecies;
}

void Animal::setName(string toName) {
    this->name = toName;
}