#include "Employee.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

Employee::Employee() {
    this->job = Unemployed;
    this->hourlyWage = -1;
    this->startTime = 0;
}

Employee::Employee(string name, int age, Jobs job, double wage) : Person(name, age) {
    this->job = job;
    this->hourlyWage = wage;
}

void Employee::clockIn(time_t startTime) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    cout << getName() << " clocked in at ";
    cout << setfill('0') << setw(2) << ltm->tm_hour << ":" << setfill('0') << setw(2) << ltm->tm_min << endl;
}
// returns time worked
time_t Employee::clockOut(time_t endTime) {
    if (startTime == 0) {
        cout << getName() << " cannot clock out because they haven't clocked in yet." << endl;
        return 0;
    }
    time_t timeWorked = endTime - startTime;
    startTime = 0; // Reset clock-in time after clocking out
    double hoursWorked = static_cast<double>(timeWorked) / 3600.0;
    cout << getName() << " clocked out. Time worked: " << fixed << setprecision(2) << hoursWorked << " hours." << endl;
    return timeWorked;
}

void Employee::print() const {
    cout << "Name: " << name
         << ", Age: " << age
         << ", Job: " << job
         << ", Wage: " << hourlyWage
         << ", startTime: " << startTime << endl;
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