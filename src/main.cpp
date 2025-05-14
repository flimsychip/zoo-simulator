#include "Animal.h" 
#include "Customer.h" 
#include "Zoo.h" 
#include <iostream> 
#include <iomanip> // make output pretty 
#include <fstream>
#include <iterator>

using namespace std; 

enum ZooInfo { QUIT, EXHIBITS, CUSTOMERS, EMPLOYEES, END_INFO };
enum ZooMenu { LEAVE_ZOO, LIST_EXS, ENTER, SORT };
enum ExhibitMenu { LEAVE_EX, LIST_ANIMALS, INTERACT };
enum AnimalMenu { LEAVE_ANIMAL, INFO, FEED, AGGRO };

void welcomeMsg();
int zooMenu();
int exhibitMenu();
int animalMenu();
void writeTestOutputToFile(const string& filename);

int main() { 
    Zoo* testZoo = new Zoo;
    Exhibit* testExhibit = new Exhibit;
    Animal* testAnimal = new Animal;
    testAnimal->setName("hammy");
    testExhibit->setName("hamsters");
    testZoo->addExhibit(*testExhibit);
    
    int choice;
    int exChoice;
    int animalChoice;
    string temp;

    Node<Exhibit>* tempEx;

    do {
        choice = zooMenu();
        switch(choice) {
            case LIST_EXS:
                cout << "List of exhibits:" << endl;
                tempEx = testZoo->getExhibits()->getHead();
                while(tempEx != nullptr) {
                    cout << "- " << tempEx->getData().getName() << endl;
                    tempEx = tempEx->getNext();
                }
                break;
            case ENTER:
                cout << "Enter name of exhibit: ";
                cin >> temp;
                // FIXME: validate exhibit exists with search func
                do {
                    exChoice = exhibitMenu();
                    switch(exChoice) {
                        case LIST_ANIMALS:
                            // stuff
                            break;
                        case INTERACT:
                            do {
                                animalChoice = animalMenu();
                                switch(animalChoice) {
                                    case INFO:
                                        // stuff
                                        break;
                                    case FEED:
                                        // stuff
                                        break;
                                    case AGGRO:
                                        // stuff
                                        break;
                                } 
                            } while(animalChoice != LEAVE_ANIMAL);
                            break;
                    }
                } while(exChoice != LEAVE_EX);
                break;
            case SORT:
                // stuff
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

int exhibitMenu() {
    int choice;
    do {
        cout << "\n--------------------------------------------" << endl;
        cout << "Exhibit Menu:" << endl;
        cout << "(" << LEAVE_EX << ") Leave exhibit" << endl;
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

int animalMenu() {
    int choice;
    do {
        cout << "\n--------------------------------------------" << endl;
        cout << "Animal Menu:" << endl;
        cout << "(" << LEAVE_ANIMAL << ") Let animal rest" << endl;
        cout << "(" << INFO << ") View info plaque" << endl;
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