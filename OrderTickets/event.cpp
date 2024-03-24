#include "event.h"

Event::Event(const QString& _eventName) : eventName(_eventName){}

QString Event::getEventName() const
{
    return eventName;
}

bool Event::setEventName(const QString &_eventName)
{
    return !_eventName.isEmpty()?(eventName=_eventName, true):false;
}

QList<Ticket> Event::getEventTickets() const
{
    return eventTickets;
}

bool Event::setEventTickets(const QList<Ticket>& _eventTickets)
{
    return !_eventTickets.isEmpty()?(eventTickets=_eventTickets,true):false;
}

bool Event::getFinished() const
{
    return isFinished;
}

bool Event::setFinished(bool _isFinished)
{
    isFinished=_isFinished;
    return true;
}

QList<Event> Event::events;

QList<Event> Event::getEvents()
{
    return events;
}

bool Event::operator == (const Event& _anotherEvent)const
{
    return eventName==_anotherEvent.getEventName();
}

bool Event::operator != (const Event& _anotherEvent)const
{
    return eventName!=_anotherEvent.getEventName();
}
