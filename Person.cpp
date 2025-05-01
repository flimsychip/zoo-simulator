#include "Person.h"
#include <iostream>

using namespace std;

string Person::getName() const {
    return this->name;
}

int Person::getAge() const {
    return this->age;
}

void Person::setName(string newName) {
    this->name = newName;
}

void Person::setAge(int newAge) {
    this->age = newAge;
}