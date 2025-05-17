#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() {
    this->name = "N/A";
    this->age = -1;
}

Person::Person(const string& newName, const int newAge) {
    this->name = newName;
    this->age = newAge;
}

// GETTERS
string Person::getName() const { return this->name; }
int Person::getAge() const { return this->age; }

// SETTERS
void Person::setName(string newName) { this->name = newName; }
void Person::setAge(int newAge) { this->age = newAge; }
