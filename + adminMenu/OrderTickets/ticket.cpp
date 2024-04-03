#include "ticket.h"

int Ticket::getId() const
{
    return id;
}

bool Ticket::setId(int _id)
{
    return _id<0?false:(id=_id, true);
}

bool Ticket::getBought() const
{
    return isBought;
}

bool Ticket::setBought(bool _isBought)
{
    isBought = _isBought;
    return true;
}

QString Ticket::getEventName() const
{
    return eventName;
}

bool Ticket::setEventName(const QString &_eventName)
{
    eventName = _eventName;
    return true;
}

QString Ticket::getBuyerName() const
{
    return buyerName;
}

bool Ticket::setBuyerName(const QString &_buyerName)
{
    buyerName = _buyerName;
    return true;
}

Ticket::Ticket(const QString& _eventName) : eventName(_eventName){}
Ticket::Ticket(const QString&_eventName, const int&_id, const int&_ticketPrice) :
    id(_id),
    ticketPrice(_ticketPrice),
    eventName(_eventName){}

bool Ticket::setTicketPrice(int _price)
{
    return _price<0?false:(ticketPrice=_price,true);
}

int Ticket::getTicketPrice() const
{
    return ticketPrice;
}

bool Ticket::operator == (const Ticket& _anotherTicket)const
{
    return (id == _anotherTicket.getId() && ticketPrice == _anotherTicket.getTicketPrice() && isBought == _anotherTicket.getBought());
}

bool Ticket::operator != (const Ticket& _anotherTicket)const
{
    return (id != _anotherTicket.getId() && ticketPrice != _anotherTicket.getTicketPrice() && isBought != _anotherTicket.getBought());
}
