#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include "src/LinkedList.h"
#include "src/Exhibit.h"
#include "src/Zoo.h"
#include "deps/nlohmann/json.hpp"   // This library isn't very fast, but is easiest to work with

// Compile and Run
// g++ json.cpp ./src/Zoo.cpp ./src/Employee.cpp ./src/Customer.cpp ./src/Person.cpp ./src/Animal.cpp ./src/Exhibit.cpp -o ./build/json_example && ./build/json_example

using namespace std;
using json = nlohmann::json;

template <typename T>
T makeObject();
template <typename T>
void writeJson(string filePath, const T& object);
template <typename T>
void readJson(string filePath, T& object);

int main()
{
    cout << "-- JSON Test --" << endl;

    // Path to Write and Read from
    string filePath = "./data/zoo.json";

    Zoo object = makeObject<Zoo>();

    writeJson(filePath, object);

    readJson(filePath, object);

    // --- Printing parsed object ---
    cout << "- Parsed Object -" << "\n";
    cout << *object.getCustomers() << endl;
    cout << *object.getEmployees() << endl;
    cout << *object.getExhibits() << endl;
    // cout << object << endl;

    cout << "-- Test Over --" << endl;
    return 0;
}

template <typename T>
T makeObject() {
    cout << "Making object" << endl;

    Exhibit testExhibit = Exhibit(100, "party city", new LinkedList<Animal>, new LinkedList<Employee>);

    Animal testAni1 = Animal(Hamster, "hammy");
    Animal testAni2 = Animal(Chimpanzee, "cody");
    Animal testAni3 = Animal(Otter, "oscar");
    Animal testAni4 = Animal(Wolf, "william");
    Animal testAni5 = Animal(Bear, "barry");
    Animal testAni6 = Animal(Lion, "larry");
    Animal testAni7 = Animal(Toucan, "thomas");
    Animal testAni8 = Animal(Gorilla, "gary");

    testExhibit.addAnimal(testAni1);
    testExhibit.addAnimal(testAni2);
    testExhibit.addAnimal(testAni3);
    testExhibit.addAnimal(testAni4);
    testExhibit.addAnimal(testAni5);
    testExhibit.addAnimal(testAni6);
    testExhibit.addAnimal(testAni7);
    testExhibit.addAnimal(testAni8);

    Employee testEmp = Employee("MILO", 22, Chopping_Block, 0);
    Employee testEmp2 = Employee("ROSA", 22, Security, 100);
    Employee testEmp3 = Employee("ELIJAH", 20, Janitor, 25);
    Employee testEmp4 = Employee("ALLIE", 19, Director, 1000);
    
    testExhibit.addEmployee(testEmp);
    testExhibit.addEmployee(testEmp2);
    testExhibit.addEmployee(testEmp3);
    testExhibit.addEmployee(testEmp4);

    Node<Employee>* tempEmpLoopPtr = testExhibit.getEmployees()->getHead();
    while(tempEmpLoopPtr != nullptr) {      // monster chains for testing and clarity
        testExhibit.setDailyCost(testExhibit.getDailyCost() + tempEmpLoopPtr->getData().getWage());
        tempEmpLoopPtr = tempEmpLoopPtr->getNext();
    }

    Customer customer = Customer("Jeremiah");
    Animal animal = Animal(Chimpanzee, "Jeremy");
    Employee employee = Employee("Jeremus");

    LinkedList<Animal> *anims = new LinkedList<Animal>(animal);
    LinkedList<Employee> *employs = new LinkedList<Employee>(employee);

    Exhibit exhib2 = Exhibit(100, "JEROME", anims, employs);

    Zoo zoo = Zoo();
    zoo.addCustomer(customer);
    zoo.addCustomer(customer);
    zoo.addEmployee(employee);
    
    zoo.addExhibit(testExhibit);
    zoo.addExhibit(exhib2);

    return zoo;
}

template <typename T>
void writeJson(string filePath, const T& object) {
    cout << "Converting to json..." << endl;
    // conversion: object -> json
    json j = object;
    // Prints entire json
    cout << j.dump(2) << endl;

    ofstream ofs(filePath);

    if (ofs.good())
        ofs << setw(4) << j;
    ofs.close();
}

template <typename T>
void readJson(string filePath, T& object) {
    json j;

    ifstream ifs(filePath);

    cout << "Parsing input..." << endl;
    if (ifs.good())
        j = json::parse(ifs);
    ifs.close();

    // conversion: json -> object
    object = j.template get<T>();   // This causes segfault with Zoo
}