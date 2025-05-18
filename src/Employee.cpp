#include "Employee.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

Employee::Employee() {
    this->job = Chopping_Block;
    this->hourlyWage = -1;
    this->startTime = 0;
}

// Initialization is calling the super constructor
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

std::ostream& operator<<(std::ostream& os, const Employee& toPrint) {
    os << toPrint.getName() << ") ";
    os << "job: " << toPrint.getJobStr() << ", ";
    os << "age: " << toPrint.getAge() << ", ";
    os << "hourly: $" << toPrint.getWage() << ", ";
    os << "start time: " << toPrint.getStart();
    return os;
}

// GETTERS
Jobs Employee::getJob() const { return this->job; }
string Employee::getJobStr() const { 
    switch(this->job) {
        case Chopping_Block:
            return "on the chopping block";
        case Caretaker:
            return "caretaker";
        case Director:
            return "director"; 
        case Security:
            return "security";
        case Janitor:
            return "janitor";
    }
    return "N/A";
}
double Employee::getWage() const { return this->hourlyWage; }
time_t Employee::getStart() const { return this->startTime; }

// SETTERS
void Employee::setJob(Jobs job) { this->job = job; }
void Employee::setWage(double wage) { this->hourlyWage = wage; }

bool operator==(const Employee& lhs, const Employee& rhs) {
    return  lhs.getJob()         == rhs.getJob()
         && lhs.getWage()        == rhs.getWage()
         && lhs.getName()        == rhs.getName()
         && lhs.getAge()         == rhs.getAge();
}

bool operator!=(const Employee& lhs, const Employee& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Employee& lhs, const Employee& rhs) {
    // 1) job
    if (lhs.getJob() != rhs.getJob())
        return lhs.getJob() < rhs.getJob();
    // 2) wage
    if (lhs.getWage() != rhs.getWage())
        return lhs.getWage() < rhs.getWage();
    // 3) name
    if (lhs.getName() != rhs.getName())
        return lhs.getName() < rhs.getName();
    // 4) age
    return lhs.getAge() < rhs.getAge();
}

bool operator>(const Employee& lhs, const Employee& rhs) {
    return rhs < lhs;
}

bool operator<=(const Employee& lhs, const Employee& rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Employee& lhs, const Employee& rhs) {
    return !(lhs < rhs);
}