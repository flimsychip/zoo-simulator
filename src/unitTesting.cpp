#include "Zoo.h" 
#include "unitTesting.h"

#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>

using namespace std; 

enum ZooInfo {QUIT, EXHIBITS, CUSTOMERS, EMPLOYEES, END_INFO};

//void welcomeMsg();
//void writeTestOutputToFile(const string& filename);

void testingPriv() {     
    cout << "Testing..." << endl;

    //welcomeMsg();

    Zoo* zoo = new Zoo();
    Exhibit* testCage = new Exhibit;

    Animal* animal1 = new Animal();     
    cout << animal1->getSpecies() << endl;
    Animal* animal2 = new Animal(Chimpanzee);   
    Animal* animal3 = new Animal(Hamster);      
         
    testCage->addAnimal(*animal1);
    testCage->addAnimal(*animal2);
    testCage->addAnimal(*animal3);

    testCage->sort();
    testCage->getEmployees()->print();
    testCage->getAnimals()->print();

    zoo->addExhibit(*testCage);

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
}

void testNodeTypes() {
    cout << "Testing Node for Employee/Animal/Customer/Exhibit..." << endl;
    Employee* imp1 = new Employee("joe shmoe", 18, Janitor, 7.50);
    imp1->print();

    Node<Employee>* testNode = new Node<Employee> ();
    cout << "Node data: " << *testNode << endl;
    cout << "Node next: " << testNode->getNext() << endl;
    cout << "Node prev: " << testNode->getPrev() << endl;

    Node<Animal>* testNode2 = new Node<Animal>;
    cout << "Node data: " << testNode2->getData() << endl;
    cout << "Node next: " << testNode2->getNext() << endl;
    cout << "Node prev: " << testNode2->getPrev() << endl;

    delete testNode;
}
void testLinkedListBasic() {
    cout << "Testing LinkedList..." << endl;
    LinkedList<Employee>* testList = new LinkedList<Employee>();
    Employee* emp1 = new Employee("morticia", 18, Janitor, 7.50);
    Employee* emp2 = new Employee("alejandro", 19, Caretaker, 8.50);
    Employee* emp3 = new Employee("ugly", 20, Security, 9.50);

    testList->push_back(*emp1);
    testList->push_back(*emp2);
    testList->push_back(*emp3);

    cout << "Linked List Size: " << testList->size() << endl;
    testList->print();

    delete testList;
}
void testNodeCompOperators () {

}

//int getTestMenuChoice ();
void promptUnitTest() {

}

void outputList ();

void movedFromMain() {
    /*    cout << "Testing..." << endl;

    // welcomeMsg();

    Zoo* zoo = new Zoo();
    Exhibit* testCage = new Exhibit;

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
    // Call the function to write output to a file
    writeTestOutputToFile("output.txt");
    
    cout << "Testing Completed" << endl;
    return 0;
*/
}