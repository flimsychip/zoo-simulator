#include "Zoo.h"
#include <iostream>

using namespace std;

Zoo::Zoo() {
    this->customers = new LinkedList<Customer>;
    this->employees = new LinkedList<Employee>;
    this->exhibits = new LinkedList<Exhibit>;
}

Zoo::Zoo(const Zoo& copyZoo) {
    this->customers = new LinkedList<Customer>(*copyZoo.getCustomers());
    this->employees = new LinkedList<Employee>(*copyZoo.getEmployees());
    this->exhibits = new LinkedList<Exhibit>(*copyZoo.getExhibits());
}

Zoo::~Zoo() {
    this->clear();
}

void Zoo::clear() {
    delete this->customers;
    delete this->employees;
    delete this->exhibits;
}

Zoo& Zoo::operator=(const Zoo &rhs) {
    if (this == &rhs) { return *this; }

    this->clear();
    this->customers = new LinkedList<Customer>(*rhs.getCustomers());
    this->employees = new LinkedList<Employee>(*rhs.getEmployees());
    this->exhibits = new LinkedList<Exhibit>(*rhs.getExhibits());

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

LinkedList<Exhibit>* Zoo::getExhibits() const {
    return this->exhibits;
}

void Zoo::addExhibit(const Exhibit& addExhibit) {
    this->exhibits->push_back(addExhibit);
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