#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <ctime>
#include "../deps/nlohmann/json.hpp"

enum Jobs {
    Chopping_Block,
    Caretaker,
    Director,
    Security,
    Janitor
};

struct Employee : public Person {
    public:
        Employee();
        Employee(
            std::string name, 
            int age = -1, 
            Jobs job = Chopping_Block, 
            double wage = -1,
            time_t start = -1
        );

        void clockIn(time_t startTime);
        time_t clockOut(time_t endTime);    // returns time worked

        void print() const override; // override print from Person.h

        // Getters
        Jobs getJob() const;
        std::string getJobStr() const;
        double getWage() const;
        time_t getStart() const;

        // Setters
        void setJob(Jobs job);
        void setWage(double wage);

        // MACRO to convert/actuate object to/from json
        NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE(Employee, Person, job, hourlyWage, startTime)

    private:
        Jobs job;
        double hourlyWage;
        time_t startTime;
};

std::ostream& operator<<(std::ostream& os, const Employee& toPrint);

bool operator==(const Employee& lhs, const Employee& rhs);
bool operator!=(const Employee& lhs, const Employee& rhs);
bool operator<(const Employee& lhs, const Employee& rhs);
bool operator>(const Employee& lhs, const Employee& rhs);
bool operator<=(const Employee& lhs, const Employee& rhs);
bool operator>=(const Employee& lhs, const Employee& rhs);

#endif