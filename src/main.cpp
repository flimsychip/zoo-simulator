#include "Animal.h" 
#include "Customer.h" 
#include "Zoo.h" 
#include "unitTesting.h"

#include <iostream> 
#include <iomanip> 
#include <fstream>
#include <iterator>

using json = nlohmann::json;
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

void readJson(string filePath, Zoo& object);
void writeJson(const std::string& filePath, const Zoo& object);

int main() { 
    Zoo TheZoo = Zoo();

    string filePath = "./data/zoo.json";

    readJson(filePath, TheZoo);

    int choice;
    string exName;
    Node<Exhibit>* tempExPtr = nullptr;

    do {
        choice = zooMenu();
        cout << endl;
        switch(choice) {
            case LIST_EXS:
                cout << "List of exhibits:" << endl;
                tempExPtr = TheZoo.getExhibits()->getHead();
                while(tempExPtr != nullptr) {
                    cout << "- " << tempExPtr->getData().getName() << endl;
                    tempExPtr = tempExPtr->getNext();
                }
                break;
            case SORT_EXS:
                cout << "sorting by alphabetical order..." << endl;
                TheZoo.getExhibits()->mergeSort();
                cout << "sorted!" << endl;
                break;
            case ENTER:
                cout << "Enter name of exhibit: ";
                cin.ignore(10000, '\n');
                getline(cin, exName);
                tempExPtr = TheZoo.getExhibits()->search(exName);
                exhibitInteract(tempExPtr);
                break;
            case TEST:
                cout << "Running unit tests..." << endl;
                promptUnitTest();
                break;
        }
    } while(choice != LEAVE_ZOO);

    cout << "Thanks for visiting the Zoo!" << endl;
    
    writeJson(filePath, TheZoo);

    TheZoo.clear();
}

int zooMenu() {
    int choice;
    do {
        cout << "\n--------------------------------------------\n" << endl;
        cout << "Zoo Menu:" << endl;
        cout << "(" << LEAVE_ZOO << ") Leave zoo" << endl;
        cout << "(" << LIST_EXS << ") List exhibits" << endl;
        cout << "(" << SORT_EXS << ") Sort exhibits" << endl;
        cout << "(" << ENTER << ") Enter an exhibit" << endl;
        cout << "(" << TEST << ") *ADMIN ONLY* Run unit tests" << endl;
        cout << "\nEnter an option: ";
        
        cin >> choice;
        if(choice < LEAVE_ZOO || choice > TEST) {
           cout << "Error! Input must be a number between " << LEAVE_ZOO << " and " << ENTER << "." << endl;
        }
    } while(choice < LEAVE_ZOO || choice > TEST);

    return choice;
}

int exhibitMenu(string name) {
    int choice;
    do {
        cout << "\n--------------------------------------------\n" << endl;
        cout << "Exhibit Menu: "  << name << endl;
        cout << "(" << LEAVE_EX << ") Leave exhibit" << endl;
        cout << "(" << INFO_EX << ") View info plaque" << endl;
        cout << "(" << LIST_EMPS << ") List employees in exhibit" << endl;
        cout << "(" << LIST_ANIMALS << ") List animals in exhibit" << endl;
        cout << "(" << SORT_ANIMALS << ") Sort animals in exhibit" << endl;
        cout << "(" << INTERACT << ") Interact with animal" << endl;
        cout << endl;
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
        cout << "Animal Menu: " << name << endl;
        cout << "(" << LEAVE_ANIMAL << ") Let animal rest" << endl;
        cout << "(" << INFO_ANIMAL << ") View info plaque" << endl;
        cout << "(" << FEED << ") Feed" << endl;
        cout << "(" << AGGRO << ") Provoke" << endl;
        cout << endl;
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

void readJson(string filePath, Zoo& object) {
    json j;

    ifstream ifs(filePath);

    cout << "Parsing input..." << endl;
    if (ifs.good())
        j = json::parse(ifs);
    ifs.close();

    // conversion: json -> object
    object = j.template get<Zoo>();
}

void writeJson(const std::string& filePath, const Zoo& object) {
    json j = object;
    std::ofstream ofs(filePath);
    if (ofs.is_open()) {
        ofs << std::setw(4) << j;
        ofs.close();
    } else {
        std::cerr << "Error: Could not open file for writing: " << filePath << std::endl;
    }
}