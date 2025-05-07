// #include "Animal.h" 
// #include "Customer.h" 
// #include "Zoo.h" 
// #include <iostream> 
// #include <iomanip> // make output pretty 
// #include <fstream>

// using namespace std; 

// enum ZooInfo {QUIT, EXHIBITS, CUSTOMERS, EMPLOYEES, END_INFO};

// void welcomeMsg();
// void writeTestOutputToFile(const string& filename);

// int main() {     
//     cout << "Testing..." << endl;

//     welcomeMsg();

//     Zoo* zoo = new Zoo();
//     // Exhibit* testCage = new Exhibit;

//     // Animal* animal1 = new Animal();     
//     // cout << animal1->getSpecies() << endl;
//     // Animal* animal2 = new Animal(Chimpanzee);   
//     // Animal* animal3 = new Animal(Hamster);      
         
//     // testCage->addAnimal(*animal1);
//     // testCage->addAnimal(*animal2);
//     // testCage->addAnimal(*animal3);

//     // testCage->sort();
//     // testCage->getEmployees()->print();

//     //zoo->addExhibit(*testCage);

//     Customer* customer = new Customer("Shakira");     
//     cout << customer->getName() << endl;   
//     Customer* customer2 = new Customer("Joe"); 
//     Customer* customer3 = new Customer("Shmoe");   
    
         
//     cout << zoo->calcExpenses() << endl;     // Is this be pushing back deep copies?     
//     zoo->addCustomer(*customer);   
//     zoo->addCustomer(*customer2);   
//     zoo->addCustomer(*customer3); 
    
//     zoo->sortCustomers();
//     zoo->getCustomers()->print();

//     delete zoo;
//     return 0;
// }

 