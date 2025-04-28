#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
    private:
        string name;
        int age;
    public:
        string getName() const;
        int getAge() const;
        void setName(string newName);
        void setAge(int newAge);
}

#endif