#include "Zoo.h"
#include <iostream>

using namespace std;

Zoo::Zoo() {
    this->customers = new LinkedList<Customer>;
    this->employees = new LinkedList<Employee>;
}

Zoo::Zoo(vector<Exhibit> exhibits) {
    this->customers = new LinkedList<Customer>;
    this->employees = new LinkedList<Employee>;
    this->exhibits = exhibits;
}

Zoo::~Zoo() {
    delete this->customers;
    delete this->employees;
}

void Zoo::addCustomer(const Customer& addCustomer) {
    this->customers->push_back(addCustomer);
}

void Zoo::rmCustomer(const Customer& rmCustomer) {
    this->customers->remove(rmCustomer);
}

void Zoo::addEmployee(const Employee& addEmployee) {
    this->employees->push_back(addEmployee);
}

void Zoo::rmEmployee(const Employee& rmEmployee) {
    this->employees->remove(rmEmployee);
}

void Zoo::addExhibit(const Exhibit& addExhibit) {
    this->exhibits.push_back(addExhibit);
}

double Zoo::calcExpenses() {
    cout << "Zoo::calcExpenses() not yet implemented" << endl;
}

double Zoo::calcRevenue() {
    cout << "Zoo::calcRevenue() not yet implemented" << endl;
}

double Zoo::calcProfit() {
    return this->calcRevenue() - this->calcExpenses();
}