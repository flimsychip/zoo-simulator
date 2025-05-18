#include "Zoo.h" 
#include "unitTesting.h"

#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>

using namespace std; 

void testNodeTypes() {
    cout << "Testing Node for Employee/Animal/Customer/Exhibit..." << endl << endl;

    cout << "Accessing Employee data..." << endl;
    Node<Employee>* testNode = new Node<Employee> ();
    cout << left << setw(40) << "Node data: \n" << *testNode << endl << endl;
    
    cout << "Setting Employee data..." << endl;
    Employee* imp1 = new Employee("joe shmoe", 18, Janitor, 7.50);
    testNode->setData(*imp1);
    cout << left << setw(40) << "Node data: \n" << *testNode << endl << endl;

    cout << "Copying testNode to newNode..." << endl;
    Node<Employee>* newNode = testNode;
    cout << left << setw(40) << "Node data: \n" << *newNode << endl << endl;

    cout << "Deleting newNode..." << endl;
    delete newNode;

    cout << "\n-----------------------------" << endl;

    cout << "Accessing Animal data..." << endl;
    Node<Animal>* testNode2 = new Node<Animal>;
    cout << left << setw(40) << "Node data: \n" << *testNode2 << endl << endl;

    cout << "Setting Animal data..." << endl;
    Animal* animal1 = new Animal(Chimpanzee);
    testNode2->setData(*animal1);
    cout << left << setw(40) << "Node data: \n" << *testNode2 << endl << endl;

    cout << "\n-----------------------------" << endl;

    cout << "Getting Customer data..." << endl;
    Node<Customer>* testNode3 = new Node<Customer>;
    cout << left << setw(40) << "Node data: \n" << *testNode3 << endl << endl;

    cout << "Setting Customer data..." << endl;
    Customer* cust1 = new Customer("Shakira", 18, 510, SENIOR);
    testNode3->setData(*cust1);
    cout << left << setw(40) << "Node data: \n" << *testNode3 << endl << endl;

    delete testNode;
    delete testNode2;
    delete testNode3;
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
void testExhibits () {

}

void promptUnitTest() {
    int choice;
    do {
        choice = getTestMenuChoice();
        switch(choice) {
            case TEST_NODE_TYPES:
                testNodeTypes();
                break;
            case TEST_LINKED_LIST:
                testLinkedListBasic();
                break;
            case TEST_ZOO:
                movedFromMain();
                break;
        }
    } while(choice != EXIT);

    cout << "Exiting unit testing..." << endl;
}

int getTestMenuChoice() {
    int choice;
    do {
        cout << "--------------------------------------------\n" << endl;
        cout << "Unit Testing Menu" << endl;
        cout << "(" << EXIT << ") Exit Unit Testing and return to Zoo Menu" << endl;
        cout << "(" << TEST_NODE_TYPES << ") Test Node" << endl;
        cout << "(" << TEST_LINKED_LIST << ") Test Linked List" << endl;
        cout << "(" << TEST_ZOO << ") Test Zoo" << endl;
        cout << endl;
        cout << "Enter an option: ";
        
        cin >> choice;
        if(choice < TEST_NODE_TYPES || choice > EXIT) {
            cout << "Error! Input must be a number between " 
                 << TEST_NODE_TYPES  << " and " 
                 << EXIT  << "." 
                 << endl;
        }
    } while(choice < TEST_NODE_TYPES || choice > EXIT);
    
    return choice;
}

void movedFromMain() {
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
    // delete animal1;     
    // delete animal2;
    // delete animal3;
    // delete customer; 
    // delete customer2;
    // delete customer3;
    // delete testCage;

    // Call the function to write output to a file
    //writeTestOutputToFile("output.txt");
    
    cout << "Testing Completed" << endl;
}

void Main2() {
    Zoo* testZoo = new Zoo;
    Exhibit* testExhibit = new Exhibit(100, "party city", new LinkedList<Animal>, new LinkedList<Employee>);
    Animal* testAni1 = new Animal(Hamster, "hammy");
    Animal* testAni2 = new Animal(Chimpanzee, "cody");
    Animal* testAni3 = new Animal(Otter, "oscar");
    Animal* testAni4 = new Animal(Wolf, "william");
    Animal* testAni5 = new Animal(Bear, "barry");
    Animal* testAni6 = new Animal(Lion, "larry");
    Animal* testAni7 = new Animal(Toucan, "thomas");
    Animal* testAni8 = new Animal(Gorilla, "gary");
    testExhibit->addAnimal(*testAni1);
    testExhibit->addAnimal(*testAni2);
    testExhibit->addAnimal(*testAni3);
    testExhibit->addAnimal(*testAni4);
    testExhibit->addAnimal(*testAni5);
    testExhibit->addAnimal(*testAni6);
    testExhibit->addAnimal(*testAni7);
    testExhibit->addAnimal(*testAni8);
    Employee* testEmp = new Employee("milo", 22, Chopping_Block, 0);
    Employee* testEmp2 = new Employee("rosa", 23, Security, 100);
    Employee* testEmp3 = new Employee("elijah", 20, Janitor, 25);
    testExhibit->addEmployee(*testEmp);
    testExhibit->addEmployee(*testEmp2);
    testExhibit->addEmployee(*testEmp3);
    Node<Employee>* tempEmpLoopPtr = testExhibit->getEmployees()->getHead();
    while(tempEmpLoopPtr != nullptr) {      // monster chains for testing and clarity
        testExhibit->setDailyCost(testExhibit->getDailyCost() + tempEmpLoopPtr->getData().getWage());
        tempEmpLoopPtr = tempEmpLoopPtr->getNext();
    }
    testZoo->addExhibit(*testExhibit);

    // FIXME: data isn't being modified after pushing back
    Exhibit* testExhibit2 = new Exhibit(100, "the bad ones", new LinkedList<Animal>, new LinkedList<Employee>);
    testZoo->addExhibit(*testExhibit2);
    testExhibit2->setName("funhouse (not a jail)"); // [FROM ZOO MANAGER] TOP PRIORITY. COVER TRACKS!!!
}