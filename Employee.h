#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <ctime>

enum Jobs {
    None,
    Caretaker,
    Director,
    Security,
    Janitor
};

struct Employee : public Person {
    public:
        void clockIn();
        void clockOut();
        double calcHoursWorked();

        // Getters
        Jobs getJob() const;
        double getWage() const;
        time_t getStart() const;

        // Setters
        void setJob(Jobs job);
        void setWage(double wage);
        void setStart(time_t startTime);
    
    private:
        Jobs job;
        double hourlyWage;
        time_t startTime;
};

#endif