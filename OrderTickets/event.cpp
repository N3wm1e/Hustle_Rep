#include "event.h"
#include <QList>

QDateTime Event::getEventTime() const
{
    return eventTime;
}

void Event::setEventTime(const QDateTime &_eventTime)
{
    eventTime = _eventTime;
}

QList<Event>::Iterator Event::searchEventByName(const QString & _name)
{
    return std::find_if(Event::getEvents().begin(), Event::getEvents().end(), [&](Event _event){
        return _event.getEventName() == _name;
    });
}

QList<Ticket>::Iterator Event::searchTicketById(int _id)
{
    return std::find_if(this->getEventTickets().begin(), this->getEventTickets().end(), [&](Ticket _ticket){
        return _ticket.getId()==_id;
    });
}

Event::Event(const QString& _eventName) : eventName(_eventName){}

QString Event::getEventName() const
{
    return eventName;
}

bool Event::setEventName(const QString &_eventName)
{
    return !_eventName.isEmpty()?(eventName=_eventName, true):false;
}

QList<Ticket>& Event::getEventTickets()
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

void Event::removeTicket(Ticket * _ticket)
{
    auto ticketIter = std::find_if(getEventTickets().begin(), getEventTickets().end(), [&](const Ticket& _labmdaTicket) {
        return _labmdaTicket.getId() == _ticket->getId();
    });

    if (ticketIter != getEventTickets().end())
        getEventTickets().erase(ticketIter);
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
