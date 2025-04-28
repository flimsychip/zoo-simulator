#include "Person.h"

string Person::getName() {
    return this->name;
}

int Person::getAge() {
    return this->age;
}

void Person::setName(string newName) {
    this->name = newName;
}

void Person::setAge(int newAge) {
    this->age = newAge;
}