#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QList>
#include <ticket.h>
#include <qdatetime.h>

class Event
{
    QString eventName;
    bool isFinished;
    QList<Ticket> eventTickets;
    QDateTime eventTime;
    static QList<Event> events;

public:
    Event(const QString&);
    QString getEventName() const;
    bool setEventName(const QString&);
    QList<Ticket>& getEventTickets();
    bool setEventTickets(const QList<Ticket>&);
    bool getFinished() const;
    bool setFinished(bool);
    static QList<Event>& getEvents();
    bool operator == (const Event&)const;
    bool operator != (const Event&)const;
    QDateTime getEventTime() const;
    void setEventTime(const QDateTime &_eventTime);
};

#endif // EVENT_H
