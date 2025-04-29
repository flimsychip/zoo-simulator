#ifndef ZOO_H
#define ZOO_H

#include <vector>
#include "Customer.h"
#include "Employee.h"
#include "Exhibit.h"

struct Zoo {
    public:
        Zoo();
        Zoo(vector<Exhibit> exhibits);
        // FIX ME: missing copy constructor
        ~Zoo();

        void addCustomer(const Customer& addCustomer);
        void rmCustomer(const Customer& rmCustomer);
        void addEmployee(const Employee& addEmployee);
        void rmEmployee(const Employee& rmEmployee);
        void addExhibit(const Exhibit& addExhibit);

        double calcExpenses();
        double calcRevenue();
        double calcProfit();

    private:
        LinkedList<Customer>* customers;
        LinkedList<Employee>* employees;
        std::vector<Exhibit> exhibits;
};

#endif