#include "Animal.h" 
#include "Customer.h" 
#include "Zoo.h" 
#include <iostream> 
#include <iomanip> // make output pretty 
#include <fstream>

using namespace std; 

enum ZooInfo {QUIT, EXHIBITS, CUSTOMERS, EMPLOYEES, END_INFO};

void welcomeMsg();

int main() {     
    cout << "Testing..." << endl;

    welcomeMsg();

    Zoo* zoo = new Zoo();
    // Exhibit* testCage = new Exhibit;

    // Animal* animal1 = new Animal();     
    // cout << animal1->getSpecies() << endl;
    // Animal* animal2 = new Animal(Chimpanzee);   
    // Animal* animal3 = new Animal(Hamster);      
         
    // testCage->addAnimal(*animal1);
    // testCage->addAnimal(*animal2);
    // testCage->addAnimal(*animal3);

    // testCage->sort();
    // testCage->getEmployees()->print();

    //zoo->addExhibit(*testCage);

    Customer* customer = new Customer("Shakira");     
    cout << customer->getName() << endl;   
    Customer* customer2 = new Customer("Joe"); 
    Customer* customer3 = new Customer("Shmoe");   
    
         
    cout << zoo->calcExpenses() << endl;     // Is this be pushing back deep copies?     
    zoo->addCustomer(*customer);   
    zoo->addCustomer(*customer2);   
    zoo->addCustomer(*customer3); 
    
    zoo->sortCustomers();
    zoo->getCustomers()->print();

    delete zoo;     
    // delete animal1;     
    // delete animal2;
    // delete animal3;
    // delete customer;     
    

    cout << "Testing Completed" << endl;     
    return 0; 
}

void welcomeMsg() {
    cout << "Welcome to Zoo Simulator!" << endl;

    cout << "." << endl;
    cout << "." << endl;
    cout << "." << endl;

    cout << "Enter '1' to start the day\n" << endl;
    cout << "Or, select any of the following to view more information about the zoo:" << endl;
    cout << EXHIBITS <<") View Exhibit list" << endl;
    cout << CUSTOMERS <<") View Customer info" << endl;
    cout << EMPLOYEES <<") View Employee info" << endl; 

}
