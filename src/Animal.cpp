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
// Operator overloads
bool operator==(const Animal& lhs, const Animal& rhs) {
    return (lhs.species == rhs.species && lhs.name == rhs.name);
}

bool operator!=(const Animal& lhs, const Animal& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Animal& lhs, const Animal& rhs) {
    if (lhs.species != rhs.species) {
        return lhs.species < rhs.species;
    }
    return lhs.name < rhs.name;
}

bool operator>(const Animal& lhs, const Animal& rhs) {
    return rhs < lhs;
}

bool operator<=(const Animal& lhs, const Animal& rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Animal& lhs, const Animal& rhs) {
    return !(lhs < rhs);
}