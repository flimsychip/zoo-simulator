#include "Animal.h" 
#include "Customer.h" 
#include "Zoo.h" 
#include <iostream> 
#include <iomanip> // make output pretty 
#include <fstream>

using namespace std;  

int main() {     
    cout << "Testing..." << endl;

    Animal* animal = new Animal();     
    cout << animal->getSpecies() << endl;     
    delete animal;     
    animal = nullptr;      

    Customer* customer = new Customer("Shakira");     
    cout << customer->getName() << endl;     

    Zoo* zoo = new Zoo();     
    cout << zoo->calcExpenses() << endl;     // Is this  be pushing back deep copies?     
    zoo->addCustomer(*customer);     
    delete zoo;     
    zoo = nullptr;      

    cout << "Testing Completed" << endl;     
    return 0; 
}