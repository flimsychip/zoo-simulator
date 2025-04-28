#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"

struct Customer : public Person {
    private:
        int ticketNum;
        Ticket ticketType;
    public:
        int getTicketNum() const;
        Ticket getTicketType() const;
        void setTicketNum(int num);
        void setTicketType(Ticket type);
}

enum Ticket { GENERAL, SENIOR, KIDS, YEARLY }

#endif