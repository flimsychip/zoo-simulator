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
// Operator overloads
bool operator==(const Customer& lhs, const Customer& rhs) {
    return  lhs.getTicketType() == rhs.getTicketType()
         && lhs.getTicketNum()  == rhs.getTicketNum()
         && lhs.getName()            == rhs.getName()
         && lhs.getAge()             == rhs.getAge();
}



bool operator!=(const Customer& lhs, const Customer& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Customer& lhs, const Customer& rhs) {
    // 1) ticketType
    if (lhs.getTicketType() != rhs.getTicketType())
        return lhs.getTicketType() < rhs.getTicketType();
    // 2) ticketNum
    if (lhs.getTicketNum() != rhs.getTicketNum())
        return lhs.getTicketNum() < rhs.getTicketNum();
    // 3) name
    if (lhs.getName() != rhs.getName())
        return lhs.getName() < rhs.getName();
    // 4) age
    return lhs.getAge() < rhs.getAge();
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