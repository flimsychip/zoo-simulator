#ifndef ZOO_H
#define ZOO_H

#include <vector>
#include "Customer.h"
#include "Employee.h"
#include "Exhibit.h"

struct Zoo {
    public:
        Zoo();
        // FIX ME: this breaks for some reason
        // Zoo(vector<Exhibit> exhibits);

        // FIX ME: missing a copy constructor - Rule of Three

        ~Zoo();

        void addCustomer(const Customer& addCustomer);
        bool rmCustomer(const Customer& rmCustomer);
        void addEmployee(const Employee& addEmployee);
        bool rmEmployee(const Employee& rmEmployee);
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