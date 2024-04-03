#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QRandomGenerator64>
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
    void setEventName(const QString&);
    QList<Ticket>& getEventTickets();
    void setEventTickets(const QList<Ticket>&);
    bool getFinished() const;
    bool setFinished(bool);
    static QList<Event>& getEvents();
    bool operator == (const Event&)const;
    bool operator != (const Event&)const;
    QDateTime getEventTime() const;
    void setEventTime(const QDateTime &_eventTime);
    QList<Ticket> generateTickets(const int, const int);
    static int generateUniqueId();
    static bool isEventInList(const QList<Event>&, const QString&);

};

#endif // EVENT_H
