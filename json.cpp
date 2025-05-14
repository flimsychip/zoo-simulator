#include <iostream>
#include <fstream>
#include "src/Exhibit.h"
#include "deps/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

int main() {
    cout << "JSON Test" << endl;

    ifstream ifs("data/data.json");
    json jin = json::parse(ifs);
    
    cout << jin << endl;

    return 0;
}