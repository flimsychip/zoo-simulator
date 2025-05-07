#ifndef EXHIBIT_H
#define EXHIBIT_H

#include "Animal.h"
#include "Employee.h"
#include "LinkedList.h"

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

        void addAnimal(const Animal& animal);
        bool rmAnimal(const Animal& animal);
        void addCaretaker(const Employee& caretaker);
        bool rmCaretaker(const Employee& caretaker);

        // OPERATORS
        Exhibit &operator=(const Exhibit &rhs);     // Assignment operator

        // GETTERS
        double getDailyCost() const;
        std::string getName() const;

        // SETTERS
        void setDailyCost(double newCost);
        void setName(std::string newName);

        LinkedList<Animal>* getAnimals();
        LinkedList<Employee>* getEmployees();

        //void sort();

    private:
        double dailyCost;
        std::string name;
        LinkedList<Animal>* animals;
        LinkedList<Employee>* employees;
};

bool operator==(const Exhibit& lhs, const Exhibit& rhs);
bool operator!=(const Exhibit& lhs, const Exhibit& rhs);
bool operator<(const Exhibit& lhs, const  Exhibit& rhs);
bool operator>(const Exhibit& lhs, const  Exhibit& rhs);
bool operator<=(const Exhibit& lhs, const Exhibit& rhs);
bool operator>=(const Exhibit& lhs, const Exhibit& rhs);

#endif