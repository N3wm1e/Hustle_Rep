#include "administrator.h"

Administrator::Administrator(const QString& _login, const QString& _pass) : User(_login, _pass){}

bool Administrator::editCustomer(Customer * _customer, const QString& _login, const QString& _pass, int _money)
{
    _customer->setLogin(_login);
    _customer->setPassword(_pass);
    _customer->setMoney(_money);
    return true;
}

bool Administrator::addCustomer(const QString& _login, const QString& _pass, int _money)
{
    Customer::getCustomers().push_back(Customer(_login, _pass, _money));
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
