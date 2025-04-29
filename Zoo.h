#ifndef ZOO_H
#define ZOO_H

#include <vector>
#include "Customer.h"
#include "Employee.h"
#include "Exhibit.h"

struct Zoo {
    public:
        void addCustomer(Customer newCustomer);
        void rmCustomer(Customer customer);
        void addEmployee(Employee employee);
        void rmEmployee(Employee employee);
        void addExhibit(Exhibit exhibit);
        double calcProfit();

    private:
        LinkedList<Customer> customers;
        LinkedList<Employee> employee;
        std::vector<Exhibit> exhibits;
};

#endif