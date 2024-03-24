#include "administrator.h"

Administrator::Administrator(const QString& _login, const QString& _pass) : User(_login, _pass){}

bool Administrator::editCustomer(const Customer & _customer)
{
    return _customer!=Customer(QString(),QString(),int());
}

bool Administrator::addCustomer()
{
    return true;
}

bool Administrator::deleteEventTickets(Event & _event)
{
    return _event!=Event(QString());
}

bool Administrator::watchAllBoughtTickets()
{
    return true;
}

bool Administrator::deleteTicket(Ticket &)
{
    return true;
}

bool Administrator::deleteAllTickets()
{
    return true;
}

bool Administrator::editEvent(Event & _event)
{
    return _event!=Event(QString());
}

bool Administrator::removeEvent(Event &_event)
{
    return _event!=Event(QString());
}

bool Administrator::addEvent()
{
    return true;
}

bool Administrator::watchAllEvents()
{
    return true;
}

QList<Administrator> Administrator::admins;
QList<Administrator>& Administrator::getAdmins()
{
    return admins;
}
