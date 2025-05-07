#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"

enum Ticket {
    GENERAL,
    SENIOR,
    KIDS,
    YEARLY
};

struct Customer : public Person {
    private:
        int ticketNum;
        Ticket ticketType;
    public:
        Customer();
        Customer(std::string name, int age = -1, int ticketNum = -1, Ticket ticketType = GENERAL);

        virtual void print() const;
        
        // GETTERS
        int getTicketNum() const;
        Ticket getTicketType() const;

        // SETTERS
        void setTicketNum(int num);
        void setTicketType(Ticket type);
};

#endif