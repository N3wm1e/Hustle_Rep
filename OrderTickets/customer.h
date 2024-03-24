#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "user.h"
#include "ticket.h"
#include <QList>

class Customer : public User
{
    int money;
    QList<Ticket> boughtTickets;
    static QList<Customer> customers;
public:
    Customer(const QString&, const QString&, int, const QList<Ticket>&_boughtTickets=QList<Ticket>());
    int getMoney() const;
    void setMoney(int);
    QList<Ticket> getBoughtTickets() const;
    void setBoughtTickets(const QList<Ticket>&);
    bool operator == (const Customer&)const;
    bool operator != (const Customer&)const;
    static QList<Customer>& getCustomers();
};

#endif // CUSTOMER_H
