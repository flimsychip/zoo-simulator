#ifndef EXHIBIT_H
#define EXHIBIT_H

#include "Animal.h"
#include "Employee.h"
#include "LinkedList.h"

struct Exhibit {
    public:
        void addAnimal(Animal animal);
        Animal rmAnimal();
        void addCaretaker(Employee caretaker);
        Employee rmCaretaker();

    private:
        LinkedList<Animal> animals;
        LinkedList<Employee> employee;
};

#endif