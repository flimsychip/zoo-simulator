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
enum ZooMenu { LEAVE_ZOO, LIST_EXS, ENTER, SORT };
enum ExhibitMenu { LEAVE_EX, INFO_EX, LIST_ANIMALS, INTERACT };
enum AnimalMenu { LEAVE_ANIMAL, INFO_ANIMAL, FEED, AGGRO };

void welcomeMsg();
int zooMenu();
int exhibitMenu(string name);
int animalMenu(string name);
void writeTestOutputToFile(const string& filename);

int main() { 
    // THIS WILL BE REPLACED WITH READING IN FROM JSON
    Zoo* testZoo = new Zoo;
    // Exhibit* testExhibit = new Exhibit(100.00, "party city (the whole gang is here)", nullptr, nullptr);
    Exhibit* testExhibit = new Exhibit;
    testExhibit->setName("party");
    Animal* testAni1 = new Animal;
    testAni1->setName("hammy");
    // Animal* testAni1 = new Animal(Hamster, "hammy");
    // Animal* testAni2 = new Animal(Chimpanzee, "cody");
    // Animal* testAni3 = new Animal(Otter, "oscar");
    // Animal* testAni4 = new Animal(Wolf, "william");
    // Animal* testAni5 = new Animal(Bear, "barry");
    // Animal* testAni6 = new Animal(Lion, "larry");
    // Animal* testAni7 = new Animal(Toucan, "thomas");
    // Animal* testAni8 = new Animal(Gorilla, "gary");
    testExhibit->addAnimal(*testAni1);
    // testExhibit->addAnimal(*testAni2);
    // testExhibit->addAnimal(*testAni3);
    // testExhibit->addAnimal(*testAni4);
    // testExhibit->addAnimal(*testAni5);
    // testExhibit->addAnimal(*testAni6);
    // testExhibit->addAnimal(*testAni7);
    // testExhibit->addAnimal(*testAni8);
    testZoo->addExhibit(*testExhibit);
    
    int choice;
    int exChoice;
    int animalChoice;
    string exName;
    string animalName;

    Node<Exhibit>* tempExPtr = nullptr;
    Node<Animal>* tempAnimalPtr = nullptr;

    // WE WILL CLEAN THIS UP AND PUT EVERYTHING IN FUNCTIONS :sob::skull:
    do {
        choice = zooMenu();
        switch(choice) {
            case LIST_EXS:
                cout << "List of exhibits:" << endl;
                tempExPtr = testZoo->getExhibits()->getHead();
                while(tempExPtr != nullptr) {
                    cout << "- " << tempExPtr->getData().getName() << endl;
                    tempExPtr = tempExPtr->getNext();
                }
                break;
            case ENTER:
                cout << "Enter name of exhibit: ";
                cin.ignore(10000, '\n');
                getline(cin, exName);
                // cout << "tempExPtr is " << tempExPtr << " at 77 (before ex search/asmt)" << endl;
                tempExPtr = testZoo->getExhibits()->search(exName);
                // cout << "tempExPtr is " << tempExPtr << " at 79 (after ex search/asmt)" << endl;
                if(tempExPtr == nullptr) {
                    cout << "Exhibit does not exist!" << endl;
                } else {
                    do {
                        exChoice = exhibitMenu(tempExPtr->getData().getName());
                        // cout << "tempExPtr is " << tempExPtr << " at 85 (after passing into exMenu)" << endl;
                        // SWITCH HERE
                        switch(exChoice) {
                            case INFO_EX:
                                tempExPtr->getData().print(); // REPLACE WITH OVERLOADED COUT FOR CONSISTENCY
                                break;
                            case LIST_ANIMALS:
                                cout << "List of animals:" << endl;
                                // cout << "tempExPtr is " << tempExPtr << " at 98 (before monster tempAnimalPtr asmt)" << endl;
                                // cout << "tempAnimalPtr is " << tempAnimalPtr << " at 99 (before monster tempAnimalPtr asmt)" << endl;
                                tempAnimalPtr = tempExPtr->getData().getAnimals()->getHead();
                                // cout << "tempExPtr is " << tempExPtr << " at 101 (after monster tempAnimalPtr asmt)" << endl;
                                // cout << "tempAnimalPtr is " << tempAnimalPtr << " at 102 (after monster tempAnimalPtr asmt)" << endl;
                                while(tempAnimalPtr != nullptr) {
                                    Animal a = tempAnimalPtr->getData();
                                    cout << "- " << a.getName() << " the " << a.getSpecies() << endl;
                                    tempAnimalPtr = tempAnimalPtr->getNext();
                                }
                                break;
                            case INTERACT:
                                cout << "Enter name of animal: ";
                                cin >> animalName;
                                // cout << "tempExPtr is " << tempExPtr << " at 125 (before monster search)" << endl;
                                // cout << "tempAnimalPtr is " << tempAnimalPtr << " at 126 (before monster search)" << endl;
                                tempAnimalPtr = tempExPtr->getData().getAnimals()->search(animalName);
                                // cout << "tempExPtr is " << tempExPtr << " at 128 (after monster chain)" << endl;
                                // cout << "tempAnimalPtr is " << tempAnimalPtr << " at 129 (after monster chain)" << endl;
                                if(tempAnimalPtr == nullptr) {
                                    cout << "There is no animal named that!" << endl;
                                } else {
                                    do {
                                        animalChoice = animalMenu(tempAnimalPtr->getData().getName());
                                        // SWITCH HERE
                                        switch(animalChoice) {
                                            case INFO_ANIMAL:
                                                cout << tempAnimalPtr->getData();
                                                break;
                                            case FEED:
                                                tempAnimalPtr->getData().eat();
                                                break;
                                            case AGGRO:
                                                tempAnimalPtr->getData().makeSound();
                                                break;
                                        } 
                                    } while(animalChoice != LEAVE_ANIMAL);
                                }
                                break;
                        }
                    } while(exChoice != LEAVE_EX);
                }
                break;
            case SORT:
                // IMPLEMENT
                cout << "sort not yet implemented" << endl;
                break;
        }
    } while(choice != LEAVE_ZOO);

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

int zooMenu() {
    int choice;
    do {
        cout << "\n--------------------------------------------" << endl;
        cout << "Zoo Menu:" << endl;
        cout << "(" << LEAVE_ZOO << ") Leave zoo" << endl;
        cout << "(" << LIST_EXS << ") List exhibits" << endl;
        cout << "(" << ENTER << ") Enter an exhibit" << endl;
        cout << "(" << SORT << ") Sort exhibits" << endl;
        cout << "Enter an option: ";
        
        cin >> choice;
        if(choice < LEAVE_ZOO || choice > SORT) {
           cout << "Error! Input must be a number between " << LEAVE_ZOO << " and " << SORT << "." << endl;
        }
     } while(choice < LEAVE_ZOO || choice > SORT);
    return choice;
}

int exhibitMenu(string name) {
    int choice;
    do {
        cout << "\n--------------------------------------------" << endl;
        cout << "Exhibit Menu: "  << name << endl;
        cout << "(" << LEAVE_EX << ") Leave exhibit" << endl;
        cout << "(" << INFO_EX << ") View info plaque" << endl;
        cout << "(" << LIST_ANIMALS << ") List animals in exhibit" << endl;
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
        cout << "\n--------------------------------------------" << endl;
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