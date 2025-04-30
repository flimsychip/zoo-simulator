#include "Exhibit.h"

Exhibit::Exhibit() {
    this->animals = new LinkedList<Animal>();
    this->employees = new LinkedList<Employee>();
}
Exhibit::~Exhibit() {
    delete this->animals;
    delete this->employees;
}

void Exhibit::addAnimal(const Animal& animal) {
    this->animals->push_back(animal);
}
Animal Exhibit::rmAnimal(const Animal &animal){
    this->animals->remove(animal);
}
void Exhibit::addCaretaker(const Employee& caretaker) {
    this->employees->push_back(caretaker);
}
Employee Exhibit::rmCaretaker(const Employee& caretaker) {
    this->employees->remove(caretaker);
}