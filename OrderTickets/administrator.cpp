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
    for(auto&i:_event.getEventTickets()) deleteTicket(i);
    return true;
}

bool Administrator::watchAllBoughtTickets()
{
    return true;
}

bool Administrator::deleteTicket(Ticket & _ticket)
{
    auto iterEvent = Event::searchEventByName(_ticket.getEventName());
    auto iterCustomer = Customer::getCustomerByName(_ticket.getBuyerName());
    if(iterCustomer!=Customer::getCustomers().end()) iterCustomer->removeTicket(&_ticket);
    if(iterEvent!=Event::getEvents().end())iterEvent->removeTicket(&_ticket);
    return true;
}

bool Administrator::deleteAllTickets()
{
    for(auto&event:Event::getEvents())
        for(auto&ticket:event.getEventTickets())
            deleteTicket(ticket);
    return true;
}

bool Administrator::editEvent(Event * _event,const QString &eventName, const QDateTime &eventTime, int amount, int price)
{
    _event->setEventName(eventName);
    _event->setEventTime(eventTime);
    _event->setEventTickets(_event->generateTickets(amount,price));
    return true;
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
