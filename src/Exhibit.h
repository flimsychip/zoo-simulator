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

        Exhibit &operator=(const Exhibit &rhs);     // Assignment operator

        void addAnimal(const Animal& animal);
        bool rmAnimal(const Animal& animal);
        void addCaretaker(const Employee& caretaker);
        bool rmCaretaker(const Employee& caretaker);

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

#endif