#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "user.h"
#include "customer.h"
#include "ticket.h"

#include <QList>

class Administrator : public User
{
    static QList<Administrator> admins;
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
    static QList<Administrator>& getAdmins();
};

#endif // ADMINISTRATOR_H
