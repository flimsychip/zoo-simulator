#include <iostream>
#include <fstream>
#include "src/Animal.h"
#include "deps/nlohmann/json.hpp"   // This library isn't very fast, but is easiest to work with

// Compile and run command
// g++ json.cpp ./src/Animal.cpp -o ./build/json_example && ./build/json_example

using namespace std;
using json = nlohmann::json;

template <typename T>
void writeJson(string filePath, const T& object);

template <typename T>
void readJson(string filePath, T& object);

int main() {

    cout << "-- JSON Test --" << endl;

    string filePath = "./data/data1.json";
    Animal object = Animal(None, "Bip");

    writeJson(filePath, object);

    readJson(filePath, object);

    cout << object << endl;

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

    // Verification step
    // conversion: json -> object
    Animal a2 = j.template get<T>();

}

template <typename T>
void readJson(string filePath, T& object) {
    json j;

    ifstream ifs(filePath);

    cout << "Parsing input..." << endl;
    if (ifs.good())
        j = json::parse(ifs);
    ifs.close();

    // Animal a3 = j2.template get<Animal>();
    object = j.template get<T>();
}