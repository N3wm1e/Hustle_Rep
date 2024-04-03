#include "event.h"

QDateTime Event::getEventTime() const
{
    return eventTime;
}

void Event::setEventTime(const QDateTime &_eventTime)
{
    eventTime = _eventTime;
}

Event::Event(const QString& _eventName) : eventName(_eventName){}

QString Event::getEventName() const
{
    return eventName;
}

void Event::setEventName(const QString &_eventName)
{
    eventName = _eventName;
}

QList<Ticket>& Event::getEventTickets()
{
    return eventTickets;
}

void Event::setEventTickets(const QList<Ticket>& _eventTickets)
{
    eventTickets = _eventTickets;
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

QList<Event>& Event::getEvents()
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

QList<Ticket>Event::generateTickets(const int amountOfTickets, const int ticketPrice){
    QList<Ticket>ticketList;
    for(int i = 1; i <= amountOfTickets; i ++){
        ticketList.push_back(Ticket(Event::getEventName(),Event::generateUniqueId()+i,ticketPrice));
    }
    return ticketList;
}
int Event::generateUniqueId() {
    qint64 currentTime = QDateTime::currentMSecsSinceEpoch();
    int uniqueId = static_cast<int>(currentTime) + QRandomGenerator::global()->generate();
    return uniqueId;
}
bool Event::isEventInList(const QList<Event>&eventsList, const QString& eventName){
    for(const Event &event : eventsList){
        if(event.getEventName() == eventName){
            return true;
        }
    }
    return false;
}
