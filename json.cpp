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
void writeJson(string filePath, const T& object);
template <typename T>
void readJson(string filePath, T& object);

int main() {

    cout << "-- JSON Test --" << endl;

    // Path to Write and Read from
    string filePath = "./data/zoo.json";

    Customer customer = Customer("Jeremiah");
    Animal animal = Animal(Chimpanzee, "Jeremy");
    Employee employee = Employee("Jeremus");

    LinkedList<Customer>* customers = new LinkedList<Customer>(customer);
    LinkedList<Animal>* anims = new LinkedList<Animal>(animal);
    LinkedList<Employee>* employs = new LinkedList<Employee>(employee);
    LinkedList<Exhibit>* test = nullptr;

    cout << "Making Exhibit" << endl;
    Exhibit exhibit = Exhibit(100, "JEROME", anims, employs);
    LinkedList<Exhibit>* exhibits = new LinkedList<Exhibit>(exhibit);
    exhibits->push_back(exhibit);

    cout << "Making zoo" << endl;
    Zoo zoo = Zoo();
    zoo.addCustomer(customer);
    zoo.addCustomer(customer);
    zoo.addEmployee(employee);
    zoo.addExhibit(exhibit);

    Zoo object = zoo;
    writeJson(filePath, object);

    Zoo newObject;
    readJson(filePath, newObject);

    json j = zoo;

    cout << "- Output JSON -" << "\n";
    cout << j.dump(2) << endl;
    cout << "- Parsed Object -" << "\n";
    cout << *newObject.getCustomers() << endl;
    cout << *newObject.getEmployees() << endl;
    cout << *newObject.getExhibits() << endl;
    // cout << object << endl;

    cout << "-- Test Over --" << endl;
    return 0;
}

template <typename T>
void writeJson(string filePath, const T& object) {
    cout << "Converting to json..." << endl;
    // conversion: object -> json
    json j = object;

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