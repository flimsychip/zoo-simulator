#ifndef EXHIBIT_H
#define EXHIBIT_H

#include "Animal.h"
#include "Employee.h"
#include "LinkedList.h"
#include "../deps/nlohmann/json.hpp"

struct Exhibit {
    public:
        Exhibit();
        Exhibit(
            double dailyCost, 
            std::string name = "N/A", 
            LinkedList<Animal>* animals = nullptr,
            LinkedList<Employee>* employees = nullptr
        );
        Exhibit(const Exhibit& copyExhibit);       // Copy Constructor

        ~Exhibit();
        void clear();

        Exhibit &operator=(const Exhibit &rhs);     // Assignment operator

        void addAnimal(const Animal& animal);
        bool rmAnimal(const Animal& animal);
        void addEmployee(const Employee& employee);
        bool rmEmployee(const Employee& employee);

        // GETTERS
        double getDailyCost() const;
        std::string getName() const;

        // SETTERS
        void setDailyCost(double newCost);
        void setName(std::string newName);

        LinkedList<Animal>* getAnimals() const;
        LinkedList<Employee>* getEmployees() const;

        void sort();
        void print();

        // MACRO to convert/actuate object to/from json
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Exhibit, dailyCost, name, animals, employees)

    private:
        double dailyCost;
        std::string name;
        LinkedList<Animal>* animals;
        LinkedList<Employee>* employees;
};

std::ostream& operator<<(std::ostream& os, const Exhibit& toPrint);

#endif