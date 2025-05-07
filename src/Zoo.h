#ifndef ZOO_H
#define ZOO_H

#include <vector>
#include "Customer.h"
#include "Employee.h"
#include "Exhibit.h"

#include <iostream>

struct Zoo {
    public:
        Zoo();
        // FIX ME: this breaks for some reason
        // Zoo(std::vector<Exhibit> exhibits);

        // FIX ME: missing a copy constructor - Rule of Three
        //Zoo& operator=(const Zoo& otherZoo);

        ~Zoo();

        void addCustomer(const Customer& addCustomer);
        bool rmCustomer(const Customer& rmCustomer);
        void addEmployee(const Employee& addEmployee);
        bool rmEmployee(const Employee& rmEmployee);

        void addExhibit(const Exhibit& addExhibit);

        void sortCustomers();

        LinkedList<Customer>* getCustomers() const;
        LinkedList<Employee>* getEmployees() const;

        double calcExpenses();
        double calcRevenue();
        double calcProfit();

    private:
        LinkedList<Customer>* customers;
        LinkedList<Employee>* employees;
        std::vector<Exhibit> exhibits;
};

#endif