#ifndef ZOO_H
#define ZOO_H

#include "Customer.h"
#include "Employee.h"
#include "Exhibit.h"

#include <iostream>

struct Zoo {
    public:
        Zoo();
        Zoo(const Zoo& copyZoo);    // Copy constructor

        ~Zoo();
        void clear();

        Zoo& operator=(const Zoo& rhs);     // Assignment operator

        void addCustomer(const Customer& addCustomer);
        void addEmployee(const Employee& addEmployee);
        void addExhibit(const Exhibit& addExhibit);
        bool rmCustomer(const Customer& rmCustomer);
        bool rmEmployee(const Employee& rmEmployee);

        void sortCustomers();

        LinkedList<Customer>* getCustomers() const;
        LinkedList<Employee>* getEmployees() const;
        LinkedList<Exhibit>* getExhibits() const;

        double calcExpenses();
        double calcRevenue();
        double calcProfit();

    private:
        LinkedList<Customer>* customers;
        LinkedList<Employee>* employees;
        LinkedList<Exhibit>* exhibits;
};

#endif