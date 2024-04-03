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
    bool editCustomer(Customer*, const QString&, const QString&, int);
    bool addCustomer(const QString&, const QString&, int);
    bool deleteEventTickets(Event&);
    QStringList watchAllBoughtTickets();
    bool deleteTicket(Ticket&);
    bool deleteAllTickets();
    bool editEvent(Event *,const QString&, const QDateTime&, int, int);
    bool removeEvent(Event&, int);
    bool addEvent(const QString&, const QDateTime&, int, int);
    QStringList watchAllEvents();
    static QList<Administrator>& getAdmins();
};

#endif // ADMINISTRATOR_H
