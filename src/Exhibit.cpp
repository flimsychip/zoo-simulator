#include "Exhibit.h"
#include "Animal.h"
#include "Employee.h"

Exhibit::Exhibit() {
    this->animals = new LinkedList<Animal>();
    this->employees = new LinkedList<Employee>();
}
Exhibit::~Exhibit() {
    delete this->animals;
    delete this->employees;
}

LinkedList<Animal>* Exhibit::getAnimals() {
    return this->animals;
}

LinkedList<Employee>* Exhibit::getEmployees() {
    return this->employees;
}

void Exhibit::addAnimal(const Animal& animal) {
    this->animals->push_back(animal);
}

bool Exhibit::rmAnimal(const Animal &animal){
    //Should return if remove was succesful
    return this->animals->remove(animal);
}
void Exhibit::addCaretaker(const Employee& caretaker) {
    this->employees->push_back(caretaker);
}
bool Exhibit::rmCaretaker(const Employee& caretaker) {
    // Should return if remove was succesful
    return this->employees->remove(caretaker);
}