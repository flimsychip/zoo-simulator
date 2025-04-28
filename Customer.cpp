#include "Customer.h"

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