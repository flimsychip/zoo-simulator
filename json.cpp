#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include "src/Animal.h"
#include "src/Person.h"
#include "src/Customer.h"
#include "src/Employee.h"
#include "src/LinkedList.h"
#include "src/Node.h"
#include "deps/nlohmann/json.hpp"   // This library isn't very fast, but is easiest to work with

// Compile and Run
// g++ json.cpp ./src/Employee.cpp ./src/Customer.cpp ./src/Person.cpp ./src/Animal.cpp -o ./build/json_example && ./build/json_example

using namespace std;
using json = nlohmann::json;

template <typename T>
void writeJson(string filePath, const T& object);
template <typename T>
void readJson(string filePath, T& object);

int main() {

    cout << "-- JSON Test --" << endl;

    string filePath = "./data/data1.json";

    Animal animal = Animal(Chimpanzee, "Jeremy");
    Customer customer = Customer("Jeremiah");
    Employee object = Employee("Jeremus");
    // LinkedList<Customer> object = LinkedList<Customer>(customer);
    // object.push_back(customer);
    // object.push_back(customer);

    json j = object;

    writeJson(filePath, object);

    readJson(filePath, object);

    cout << object << endl;

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
    object = j.template get<T>();
}