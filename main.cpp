#include "Animal.h"
#include "Customer.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Testing..." << endl;

    Animal* animal = new Animal();
    cout << animal->getSpecies() << endl;
    delete animal;
    animal = nullptr;

    Customer* customer = new Customer("Shakira");
    cout << customer->getName() << endl;
    delete customer;
    customer = nullptr;

    cout << "Testing Completed" << endl;
    return 0;
}