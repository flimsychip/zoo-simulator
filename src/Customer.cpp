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