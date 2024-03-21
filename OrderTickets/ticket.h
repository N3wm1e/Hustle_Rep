#ifndef TICKET_H
#define TICKET_H


class Ticket
{
    int id;
    int ticketPrice;
    bool isBought;
public:
    Ticket(int);
    bool operator == (const Ticket&)const;
    bool operator != (const Ticket&)const;
    int getId() const;
    bool setId(int);
    int getTicketPrice() const;
    bool setTicketPrice(int);
    bool getBought() const;
    bool setBought(bool);
};

#endif // TICKET_H
