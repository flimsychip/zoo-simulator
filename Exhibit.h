#ifndef EXHIBIT_H
#define EXHIBIT_H

#include "Animal.h"
#include "Employee.h"
#include "LinkedList.h"

struct Exhibit {
    public:
        void addAnimal(const Animal& animal);
        Animal rmAnimal();
        void addCaretaker(const Employee& caretaker);
        Employee rmCaretaker();

    private:
        LinkedList<Animal>* animals;
        LinkedList<Employee>* employee;
};

#endif