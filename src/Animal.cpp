#include "Animal.h"
#include <iostream>

using namespace std;
using json = nlohmann::json;

Animal::Animal() {
    this->setSpecies(None);
}

Animal::Animal(Species species) {
    this->setSpecies(species);
}

Animal::Animal(Species species, string name) {
    this->setSpecies(species);
    this->setName(name);
}

void Animal::makeSound() const{
    switch(this->getSpecies()) {
        case Chimpanzee:
            cout << "oo oo aa aa" << endl;
            break;
        case Otter:
            cout << "squeal" << endl;
            break;
        case Wolf:
            cout << "awooo" << endl;
            break;
        case Bear:
            cout << "growl" << endl;
            break;
        case Lion:
            cout << "snarl" << endl;
            break;
        case Toucan:
            cout << "squawk" << endl;
            break;
        case Hamster:
            cout << "squeak" << endl;
            break;
        case Gorilla:
            cout << "aa aa oo oo" << endl;
            break;
        default:
            cout << "..." << endl;
            break;
    }
}

void Animal::eat() const {
    cout << "food inventory not yet implemented" << endl;
    switch(this->getSpecies()) {
        case Chimpanzee:
            cout << "yum berries" << endl;
            break;
        case Otter:
            cout << "yum fish" << endl;
            break;
        case Wolf:
            cout << "yum rabbits" << endl;
            break;
        case Bear:
            cout << "yum salmon" << endl;
            break;
        case Lion:
            cout << "yum deer" << endl;
            break;
        case Toucan:
            cout << "yum nuts" << endl;
            break;
        case Hamster:
            cout << "yum pellets" << endl;
            break;
        case Gorilla:
            cout << "yum bananas" << endl;
            break;
        default:
            cout << "yum void" << endl;
            break; 
    }
}

Species Animal::getSpecies() const {
    return this->species;
}

string Animal::getSpeciesStr() const {
    switch(this->getSpecies()) {
        case Chimpanzee:
            return "chimpanzee";
        case Otter:
            return "otter";
        case Wolf:
            return "wolf";
        case Bear:
            return "bear";
        case Lion:
            return "lion";
        case Toucan:
            return "toucan";
        case Hamster:
            return "hamster";
        case Gorilla:
            return "gorilla";
        default:
            return "none";
    }
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

void Animal::print() {
    cout << "Species: " << this->getSpeciesStr() << endl;
    cout << "Name: " << this->getName() << endl;
}

std::ostream& operator<<(std::ostream& os, const Animal& toPrint) {
    os << "Species: " << toPrint.getSpeciesStr() << "\n";
    os << "Name: " << toPrint.getName();

    return os;
}

// Operator overloads
bool operator==(const Animal& lhs, const Animal& rhs) {
    return (lhs.getSpecies() == rhs.getSpecies() && lhs.getName() == rhs.getName());
}

bool operator!=(const Animal& lhs, const Animal& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Animal& lhs, const Animal& rhs) {
    if (lhs.getSpecies() != rhs.getSpecies()) {
        return lhs.getSpecies() < rhs.getSpecies();
    }
    return lhs.getName() < rhs.getName();
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