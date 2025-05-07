#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <ctime>

enum Jobs {
    Unemployed,
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
            Jobs job = Unemployed, 
            double wage = -1
        );

        void clockIn(time_t startTime);
        time_t clockOut(time_t endTime);    // returns time worked

        virtual void print() const;

        // Getters
        Jobs getJob() const;
        double getWage() const;
        time_t getStart() const;

        // Setters
        void setJob(Jobs job);
        void setWage(double wage);
    
    private:
        Jobs job;
        double hourlyWage;
        time_t startTime;
};

#endif