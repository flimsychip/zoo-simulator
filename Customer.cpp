#include "Customer.h"

int getTicketNum() const {
    return this->ticketNum;
}

Ticket getTicketType() const {
    return this->ticketType;
}

void setTicketNum(int num) {
    this->ticketNum = num;
}

void setTicketType(Ticket type) {
    this->ticketType = type;
}