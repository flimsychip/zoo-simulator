#include "Zoo.h"
#include <iostream>

using namespace std;

Zoo::Zoo() {
    this->customers = new LinkedList<Customer>;
    this->employees = new LinkedList<Employee>;
}

// Zoo::Zoo(vector<Exhibit> exhibits) {
//     this->customers = new LinkedList<Customer>;
//     this->employees = new LinkedList<Employee>;
//     this->exhibits = exhibits;
// }

Zoo::~Zoo() {
    delete this->customers;
    delete this->employees;
}

void Zoo::addCustomer(const Customer& addCustomer) {
    this->customers->push_back(addCustomer);
}

bool Zoo::rmCustomer(const Customer& rmCustomer) {   
    // FIXME: Should return if remove was succesful
    return this->customers->remove(rmCustomer);;
}

void Zoo::addEmployee(const Employee& addEmployee) {
    this->employees->push_back(addEmployee);
}

bool Zoo::rmEmployee(const Employee& rmEmployee) {
    // FIXME: Should return if remove was succesful
    return this->employees->remove(rmEmployee);;
}

LinkedList<Customer>* Zoo::getCustomers() const {
    return this->customers;
}

LinkedList<Employee>* Zoo::getEmployees() const {
    return this->employees;
}

void Zoo::addExhibit(const Exhibit& addExhibit) {
    // this->exhibits.push_back(addExhibit);
    cout << "Zoo::addExhibit not yet implemented" << endl;
}

void Zoo::sortCustomers() {
    (this->customers)->mergeSort();
}

double Zoo::calcExpenses() {
    cout << "Zoo::calcExpenses() not yet implemented" << endl;
    return -1;
}

double Zoo::calcRevenue() {
    cout << "Zoo::calcRevenue() not yet implemented" << endl;
    return -1;
}

double Zoo::calcProfit() {
    return this->calcRevenue() - this->calcExpenses();
    return -1;
}