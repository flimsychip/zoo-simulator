#include "Customer.h"

Customer::Customer() {
    // FIXME: should call Person constructor?
    this->name = "";
    this->age = -1;
    this->ticketNum = -1;
    this->ticketType = GENERAL;
}

Customer::Customer(std::string name, int age, int ticketNum, Ticket ticketType) {
    // FIXME: should call Person constructor?
    this->name = name;
    this->age = age;
    this->ticketNum = ticketNum;
    this->ticketType = ticketType;
}

int Customer::getTicketNum() const {
    return this->ticketNum;
}

Ticket Customer::getTicketType() const {
    return this->ticketType;
}

void Customer::setTicketNum(int num) {
    this->ticketNum = num;
}

void Customer::setTicketType(Ticket type) {
    this->ticketType = type;
}