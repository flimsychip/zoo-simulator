#ifndef EXHIBIT_H
#define EXHIBIT_H

#include "Animal.h"
#include "Employee.h"
#include "LinkedList.h"

struct Exhibit {
    public:
        Exhibit();

        // FIXME: missing rule of three
        ~Exhibit();

        void addAnimal(const Animal& animal);
        Animal rmAnimal(const Animal& animal);
        void addCaretaker(const Employee& caretaker);
        Employee rmCaretaker(const Employee& caretaker);

    private:
        LinkedList<Animal>* animals;
        LinkedList<Employee>* employees;
};

#endif