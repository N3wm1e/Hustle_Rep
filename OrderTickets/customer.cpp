#include "customer.h"

int Customer::getMoney() const
{
    return money;
}

void Customer::setMoney(int _money)
{
    money = _money;
}

QList<Ticket> Customer::getBoughtTickets() const
{
    return boughtTickets;
}

void Customer::setBoughtTickets(const QList<Ticket> &_boughtTickets)
{
    boughtTickets = _boughtTickets;
}

Customer::Customer(const QString& _login, const QString& _pass, int _money, const QList<Ticket>& _boughtTickets) : User(_login, _pass), money(_money), boughtTickets(_boughtTickets) {}

bool Customer::operator == (const Customer& _anotherCustomer)const
{
    return getLogin()==_anotherCustomer.getLogin();
}

bool Customer::operator != (const Customer& _anotherCustomer)const
{
    return getLogin()!=_anotherCustomer.getLogin();
}
