#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
    private:
        string name;
        int age;
    public:
        string getName();
        int getAge();
        void setName(string newName);
        void setAge(int newAge);
}

#endif