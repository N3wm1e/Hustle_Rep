#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "user.h"
#include "customer.h"
#include "ticket.h"

class Administrator : public User
{
public:
    Administrator(const QString&, const QString&);
    bool editCustomer(const Customer&);
    bool addCustomer();
    bool deleteEventTickets(Event&);
    bool watchAllBoughtTickets();
    bool deleteTicket(Ticket&);
    bool deleteAllTickets();
    bool editEvent(Event&);
    bool removeEvent(Event&);
    bool addEvent();
    bool watchAllEvents();
};

#endif // ADMINISTRATOR_H
