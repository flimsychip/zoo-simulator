#include "Animal.h" 
#include "Customer.h" 
#include "Zoo.h" 
#include <iostream> 
#include <iomanip> // make output pretty 
#include <fstream>

using namespace std;  

void writeTestOutputToFile(const string& filename) {
    ofstream outputFile(filename);

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
        delete customer;
        customer = nullptr;

        outputFile << "Testing Completed" << endl;
        outputFile.close();
        cout << "Results written to " << filename << endl;
    } else {
        cerr << "Unable to open " << filename << " for writing." << endl;
    }
}

int main() {     
    cout << "Testing..." << endl;

    // Call the function to write output to a file
    writeTestOutputToFile("output.txt");

    cout << "Testing Completed" << endl;
    return 0;
}