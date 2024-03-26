#ifndef TICKET_H
#define TICKET_H

#include <QString>

class Ticket
{
    int id;
    int ticketPrice;
    bool isBought;
    QString eventName;
    QString buyerName;
public:
    Ticket(const QString&);
    bool operator == (const Ticket&)const;
    bool operator != (const Ticket&)const;
    int getId() const;
    bool setId(int);
    int getTicketPrice() const;
    bool setTicketPrice(int);
    bool getBought() const;
    bool setBought(bool);
    QString getEventName() const;
    bool setEventName(const QString &);
    QString getBuyerName() const;
    bool setBuyerName(const QString &);
};

#endif // TICKET_H
