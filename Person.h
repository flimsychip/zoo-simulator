#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

struct Person {
    protected:
        std::string name;
        int age;
    public:
        std::string getName() const;
        int getAge() const;
        void setName(std::string newName);
        void setAge(int newAge);
};

#endif