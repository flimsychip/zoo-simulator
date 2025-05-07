#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer() {
    this->ticketNum = -1;
    this->ticketType = GENERAL;
}

Customer::Customer(std::string name, int age, int ticketNum, Ticket ticketType) : Person(name, age) {
    this->ticketNum = ticketNum;
    this->ticketType = ticketType;
}

void Customer::print() const {
    cout << "Name: " << name 
        << ", Age: " << age
        << ", Ticket Num: " << ticketNum 
        << ", Ticket: " << ticketType << endl;
}

// GETTERS
int Customer::getTicketNum() const { return this->ticketNum;}
Ticket Customer::getTicketType() const { return this->ticketType;}

// SETTERS
void Customer::setTicketNum(int num) { this->ticketNum = num;}
void Customer::setTicketType(Ticket type) { this->ticketType = type;}

// Assignment Operator
Customer& Customer::operator=(const Customer& other) {
    if (this != &other) { // Prevent self-assignment
        // Call the assignment operator of the base class (Person)
        Person::operator=(other);
        ticketNum = other.ticketNum;
        ticketType = other.ticketType;
    }
    return *this;
}

bool operator==(const Customer& lhs, const Customer& rhs) {
    return (static_cast<const Person&>(lhs) == static_cast<const Person&>(rhs) &&
            lhs.ticketNum == rhs.ticketNum && lhs.ticketType == rhs.ticketType);
}

bool operator!=(const Customer& lhs, const Customer& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Customer& lhs, const Customer& rhs) {
    if (static_cast<const Person&>(lhs) != static_cast<const Person&>(rhs)) {
        return static_cast<const Person&>(lhs) < static_cast<const Person&>(rhs);
    }
    if (lhs.ticketNum != rhs.ticketNum) {
        return lhs.ticketNum < rhs.ticketNum;
    }
    return lhs.ticketType < rhs.ticketType;
}

bool operator>(const Customer& lhs, const Customer& rhs) {
    return rhs < lhs;
}

bool operator<=(const Customer& lhs, const Customer& rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Customer& lhs, const Customer& rhs) {
    return !(lhs < rhs);
}