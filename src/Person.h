#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include "../deps/nlohmann/json.hpp"

// Abstract Class
struct Person {
    protected:
        std::string name;
        int age;

    public:
        Person();
        Person(const std::string& newName, int newAge = -1);
    
        virtual void print() const = 0;     // pure virtual function

        // GETTERS
        std::string getName() const;
        int getAge() const;

        // SETTERS
        void setName(std::string newName);
        void setAge(int newAge);

        // MACRO to convert/actuate object to/from json
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Person, name, age)
};

#endif