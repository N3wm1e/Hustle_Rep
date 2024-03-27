#include "user.h"

User::User(const QString& _login, const QString& _pass): login(_login), password(_pass){}

QStringList User::searchByDate(const QDate& _date)
{
    QStringList stringList;
    for(const auto&i:Event::getEvents()){
        if(i.getEventTime().date().year()==_date.year() && i.getEventTime().date().month()==_date.month() && i.getEventTime().date().day()==_date.day()){
            stringList.push_back(i.getEventName());
        }
    }
    return stringList;
}

QString User::searchByName(const QString& _name)
{
    for(const auto&i:Event::getEvents()){
        if(_name == i.getEventName()) return i.getEventName();
    }
    return "";
}

QStringList User::showAllEvents()
{
    QStringList stringList;
    for (const auto&i:Event::getEvents()) {
        stringList.push_back(i.getEventName());
    }
    return stringList;
}

bool User::openEvent(Event *_event,Customer*_customer)
{
    EventDescriptionWindow*descWind=new EventDescriptionWindow();
    descWind->setEvent(_event);
    descWind->setCustomer(_customer);
    descWind->displayInfo();
    descWind->displayTicketPrice(_event);
    descWind->setModal(true);
    descWind->exec();
    return true;
}


bool User::Authorization()
{
    return true;
}

QString User::getLogin() const
{
    return login;
}

QString User::getPassword() const
{
    return password;
}
