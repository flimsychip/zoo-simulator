#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee() {
    // FIXME: should call Person constructor?
    this->name = "";
    this->age = -1;
    this->job = Unemployed;
    this->hourlyWage = -1;
    this->startTime = -1;
}

Employee::Employee(string name, int age, Jobs job, double wage, time_t startTime) {
    // FIXME: should call Person constructor?
    this->name = name;
    this->age = age;
    this->job = job;
    this->hourlyWage = wage;
    this->startTime = startTime;
}

void Employee::clockIn(time_t startTime) {
    cout << "Employee::clockIn() not yet implemented" << endl;
}
// returns time worked
time_t Employee::clockOut(time_t endTime) {
    cout << "Employee::clockOut() not yet implemented" << endl;
    return -1;
}

// Getters
Jobs Employee::getJob() const {
    return this->job;
}
double Employee::getWage() const {
    return this->hourlyWage;
}
time_t Employee::getStart() const {
    return this->startTime;
}

// Setters
void Employee::setJob(Jobs job) {
    this->job = job;
}
void Employee::setWage(double wage) {
    this->hourlyWage = wage;
}