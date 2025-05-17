/*
    TO DO: 
    - !!! filei for loading in objects !!!!!
    - fileo -- honestly we can just write everything we write in the console to a file :sob: make sure we include user inputs
    - bug line 65: can't modify data after pushing back (not totally necessary, if not fixed just make sure we load in objects in the right order)
    - clean up unused functionality in all files (only one shows up in output, hit that first -- food inventory)
        - adjust uml
        - friend stuff
*/

#include "Animal.h" 
#include "Customer.h" 
#include "Zoo.h" 
#include "unitTesting.h"
#include <iostream> 
#include <iomanip> // make output pretty 
#include <fstream>
#include <iterator>

using namespace std; 

enum ZooInfo { QUIT, EXHIBITS, CUSTOMERS, EMPLOYEES, END_INFO };
enum ZooMenu { LEAVE_ZOO, LIST_EXS, SORT_EXS, ENTER, TEST};
enum ExhibitMenu { LEAVE_EX, INFO_EX, LIST_EMPS, LIST_ANIMALS, SORT_ANIMALS, INTERACT };
enum AnimalMenu { LEAVE_ANIMAL, INFO_ANIMAL, FEED, AGGRO };

int zooMenu();
int exhibitMenu(string name);
int animalMenu(string name);
void exhibitInteract(Node<Exhibit>* ptr);
void animalInteract(Node<Animal>* ptr);
void writeTestOutputToFile(const string& filename);

int main() { 
    // will be replaced by reading in from json
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

    // cleaned up and put in funcs :yippee::bloom::steamhappy:
    int choice;
    string exName;
    Node<Exhibit>* tempExPtr = nullptr;

    do {
        choice = zooMenu();
        cout << endl;
        switch(choice) {
            case LIST_EXS:
                cout << "List of exhibits:" << endl;
                tempExPtr = testZoo->getExhibits()->getHead();
                while(tempExPtr != nullptr) {
                    cout << "- " << tempExPtr->getData().getName() << endl;
                    tempExPtr = tempExPtr->getNext();
                }
                break;
            case SORT_EXS:
                cout << "sorting by alphabetical order..." << endl;
                testZoo->getExhibits()->mergeSort();
                cout << "sorted!" << endl;
                break;
            case ENTER:
                cout << "Enter name of exhibit: ";
                cin.ignore(10000, '\n');
                getline(cin, exName);
                tempExPtr = testZoo->getExhibits()->search(exName);
                exhibitInteract(tempExPtr);
                break;
            case TEST:
                cout << "Running unit tests..." << endl;
                promptUnitTest();
                break;
        }
    } while(choice != LEAVE_ZOO);

    cout << "Thanks for visiting the zoo!" << endl;

    // make sure to add deletes
    delete testZoo;
}

int zooMenu() {
    int choice;
    do {
        cout << "\n--------------------------------------------\n" << endl;
        cout << endl;
        cout << "Zoo Menu:" << endl;
        cout << endl;
        cout << "(" << LEAVE_ZOO << ") Leave zoo" << endl;
        cout << "(" << LIST_EXS << ") List exhibits" << endl;
        cout << "(" << SORT_EXS << ") Sort exhibits" << endl;
        cout << "(" << ENTER << ") Enter an exhibit" << endl;
        cout << "\nEnter an option: ";
        
        cin >> choice;
        if(choice < LEAVE_ZOO || choice > ENTER) {
           cout << "Error! Input must be a number between " << LEAVE_ZOO << " and " << ENTER << "." << endl;
        }
    } while(choice < LEAVE_ZOO || choice > ENTER);

    return choice;
}

int exhibitMenu(string name) {
    int choice;
    do {
        cout << "\n--------------------------------------------\n" << endl;
        cout << endl;
        cout << "Exhibit Menu: "  << name << endl;
        cout << endl;
        cout << "(" << LEAVE_EX << ") Leave exhibit" << endl;
        cout << "(" << INFO_EX << ") View info plaque" << endl;
        cout << "(" << LIST_EMPS << ") List employees in exhibit" << endl;
        cout << "(" << LIST_ANIMALS << ") List animals in exhibit" << endl;
        cout << "(" << SORT_ANIMALS << ") Sort animals in exhibit" << endl;
        cout << "(" << INTERACT << ") Interact with animal" << endl;
        cout << "Enter an option: ";
        
        cin >> choice;
        if(choice < LEAVE_EX || choice > INTERACT) {
           cout << "Error! Input must be a number between " << LEAVE_EX << " and " << INTERACT << "." << endl;
        }
     } while(choice < LEAVE_EX || choice > INTERACT);
    return choice;
}

int animalMenu(string name) {
    int choice;
    do {
        cout << "\n--------------------------------------------\n" << endl;
        cout << endl;
        cout << "Animal Menu: " << name << endl;
        cout << "(" << LEAVE_ANIMAL << ") Let animal rest" << endl;
        cout << "(" << INFO_ANIMAL << ") View info plaque" << endl;
        cout << "(" << FEED << ") Feed" << endl;
        cout << "(" << AGGRO << ") Provoke" << endl;
        cout << "Enter an option: ";
        
        cin >> choice;
        if(choice < LEAVE_ANIMAL || choice > AGGRO) {
           cout << "Error! Input must be a number between " << LEAVE_ANIMAL << " and " << AGGRO << "." << endl;
        }
     } while(choice < LEAVE_ANIMAL || choice > AGGRO);
    return choice;
}

void exhibitInteract(Node<Exhibit>* ptr) {
    int choice;
    string animalName;
    Node<Animal>* tempAnimalPtr = nullptr;
    Node<Employee>* tempEmpPtr = nullptr;
    if(ptr == nullptr) {
        cout << "Exhibit does not exist!" << endl;
    } else {
        do {
            choice = exhibitMenu(ptr->getData().getName());
            cout << endl;
            switch(choice) {
                case INFO_EX:
                    cout << ptr->getData() << endl;
                    break;
                case LIST_EMPS:
                    cout << "List of employees:" << endl;
                    tempEmpPtr = ptr->getData().getEmployees()->getHead();
                    while(tempEmpPtr != nullptr) {
                        cout << "- " << *tempEmpPtr << endl;
                        tempEmpPtr = tempEmpPtr->getNext();
                    }
                    break;
                case LIST_ANIMALS:
                    cout << "List of animals:" << endl;
                    tempAnimalPtr = ptr->getData().getAnimals()->getHead();
                    while(tempAnimalPtr != nullptr) {
                        cout << "- " << tempAnimalPtr->getData().getName() << " the " << tempAnimalPtr->getData().getSpeciesStr() << endl;
                        tempAnimalPtr = tempAnimalPtr->getNext();
                    }
                    break;
                case SORT_ANIMALS:
                    cout << "sorting by alphabetical order..." << endl;
                    ptr->getData().getAnimals()->mergeSort();
                    cout << "sorted!" << endl;
                    break;
                case INTERACT:
                    cout << "Enter name of animal: ";
                    cin >> animalName;
                    tempAnimalPtr = ptr->getData().getAnimals()->search(animalName);
                    animalInteract(tempAnimalPtr);
                    break;
            }
        } while(choice != LEAVE_EX);
    }
}

void animalInteract(Node<Animal>* ptr) {
    int choice;
    if(ptr == nullptr) {
        cout << "There is no animal named that!" << endl;
    } else {
        do {
            choice = animalMenu(ptr->getData().getName());
            cout << endl;
            switch(choice) {
                case INFO_ANIMAL:
                    cout << ptr->getData() << endl;
                    break;
                case FEED:
                    ptr->getData().eat();
                    break;
                case AGGRO:
                    ptr->getData().makeSound();
                    break;
            } 
        } while(choice != LEAVE_ANIMAL);
    }
}

void writeTestOutputToFile(const string& filename) {
    ofstream outputFile("./data/" + filename);

    if (outputFile.is_open()) {
        outputFile << "Starting the test run..." << endl;

        Animal* animal = new Animal();
        outputFile << "Created Animal: " << animal->getSpecies() << endl;
        delete animal;
        animal = nullptr;

        Customer* customer = new Customer("Shakira");
        outputFile << "Created Customer: " << customer->getName() << endl;

        Zoo* zoo = new Zoo();
        outputFile << "Calculated Zoo Expenses: " << fixed << setprecision(2) << zoo->calcExpenses() << endl;
        zoo->addCustomer(*customer);
        outputFile << "Added customer '" << customer->getName() << "' to the zoo." << endl;
        delete zoo;
        zoo = nullptr;
        

        outputFile << "Testing Completed" << endl;
        outputFile.close();
        cout << "Results written to " << filename << endl;
    } else {
        cerr << "Unable to open " << filename << " for writing." << endl;
    }
}