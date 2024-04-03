#include "customer.h"

int Customer::getMoney() const
{
    return money;
}

void Customer::setMoney(int _money)
{
    money = _money;
}

QList<Ticket*>& Customer::getBoughtTickets()
{
    return boughtTickets;
}

void Customer::setBoughtTickets(QList<Ticket*> _boughtTickets)
{
    boughtTickets = _boughtTickets;
}

Customer::Customer(const QString& _login, const QString& _pass, int _money, QList<Ticket*> _boughtTickets) : User(_login, _pass), money(_money), boughtTickets(_boughtTickets) {}

bool Customer::operator == (const Customer& _anotherCustomer)const
{
    return getLogin()==_anotherCustomer.getLogin();
}

bool Customer::operator != (const Customer& _anotherCustomer)const
{
    return getLogin()!=_anotherCustomer.getLogin();
}

QList<Customer> Customer::customers;
QList<Customer>& Customer::getCustomers()
{
    return customers;
}

void Customer::removeTicket(Ticket*ticket){
    ticket->setBought(false);
    ticket->setBuyerName("");
    this->setMoney(this->getMoney() + ticket->getTicketPrice());
    QList<Ticket*>::Iterator ticketIterator = this->findTicket(ticket->getId());
    if(isTicketFound(ticketIterator)) boughtTickets.erase(ticketIterator);
}
QList<Ticket*>::Iterator Customer::findTicket(const int &ticketId){
    return std::find_if(boughtTickets.begin(),boughtTickets.end(), [ticketId](Ticket* ticket){return ticket->getId() == ticketId;});
}
bool Customer::isTicketFound(QList<Ticket*>::Iterator ticketIterator){
    return ticketIterator != boughtTickets.end();
}
