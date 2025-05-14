#include "Exhibit.h"
#include "Animal.h"
#include "Employee.h"

using namespace std;

Exhibit::Exhibit() {
    this->dailyCost = -1;
    this->name = "N/A";
    this->animals = new LinkedList<Animal>();
    this->employees = new LinkedList<Employee>();
}

Exhibit::Exhibit(double cost, string name, 
                 LinkedList<Animal> *animals, 
                 LinkedList<Employee> *employees)
{
    this->dailyCost = cost;
    this->name = name;
    this->animals = animals;
    this->employees = employees;
}

Exhibit::Exhibit(const Exhibit &copyExhibit) {
    this->dailyCost = copyExhibit.dailyCost;
    this->name = copyExhibit.dailyCost;
    this->animals = copyExhibit.animals;
    this->employees = copyExhibit.employees;
}

Exhibit::~Exhibit() {
    this->clear();
}

Exhibit& Exhibit::operator=(const Exhibit &rhs) {
    if (this == &rhs) { return *this; }

    this->clear();

    this->animals = rhs.animals;
    this->employees = rhs.employees;

    return *this;
}

void Exhibit::clear() {
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

void Exhibit::sort() {
    this->animals->mergeSort();
    this->employees->mergeSort();
}

// GETTERS
double Exhibit::getDailyCost() const { return this->dailyCost; }
string Exhibit::getName() const { return this->name; }

// SETTERS
void Exhibit::setDailyCost(double newCost) { this->dailyCost = newCost; }
void Exhibit::setName(string newName) { this->name = newName; }

void Exhibit::print() {
    cout << "Exhibit Name: " << this->getName() << endl;
    cout << "Daily Cost: $" << this->getDailyCost() << endl;
    cout << "Animals in Exhibit: " << endl;
    
    this->animals->print();
    cout << "Employees in Exhibit: " << endl;
    this->employees->print();
}