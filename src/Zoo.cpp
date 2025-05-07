#include "Zoo.h"
#include <iostream>

using namespace std;

Zoo::Zoo() {
    this->customers = new LinkedList<Customer>;
    this->employees = new LinkedList<Employee>;
}

Zoo::Zoo(const Zoo& copyZoo) {
    this->customers = copyZoo.customers;
    this->employees = copyZoo.employees;
    this->exhibits = copyZoo.exhibits;
}

Zoo::~Zoo() {
    this->clear();
}

void Zoo::clear() {
    delete this->customers;
    delete this->employees;
}

Zoo& Zoo::operator=(const Zoo &rhs) {
    if (this == &rhs) { return *this; }

    this->customers = rhs.customers;
    this->employees = rhs.employees;
    this->exhibits = rhs.exhibits;

    return *this;
}

void Zoo::addCustomer(const Customer& addCustomer) {
    this->customers->push_back(addCustomer);
}

bool Zoo::rmCustomer(const Customer& rmCustomer) {   
    return this->customers->remove(rmCustomer);;
}

void Zoo::addEmployee(const Employee& addEmployee) {
    this->employees->push_back(addEmployee);
}

bool Zoo::rmEmployee(const Employee& rmEmployee) {
    return this->employees->remove(rmEmployee);;
}

LinkedList<Customer>* Zoo::getCustomers() const {
    return this->customers;
}

LinkedList<Employee>* Zoo::getEmployees() const {
    return this->employees;
}

void Zoo::addExhibit(const Exhibit& addExhibit) {
    this->exhibits.push_back(addExhibit);
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