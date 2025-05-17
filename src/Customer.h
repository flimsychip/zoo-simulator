#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "../deps/nlohmann/json.hpp"

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

        // MACRO to convert/actuate object to/from json
        NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE(Customer, Person, ticketNum, ticketType)
};

std::ostream& operator<<(std::ostream& os, const Customer& toPrint);

bool operator==(const Customer& lhs, const Customer& rhs);
bool operator!=(const Customer& lhs, const Customer& rhs);
bool operator<(const Customer& lhs, const Customer& rhs);
bool operator>(const Customer& lhs, const Customer& rhs);
bool operator<=(const Customer& lhs, const Customer& rhs);
bool operator>=(const Customer& lhs, const Customer& rhs);
#endif