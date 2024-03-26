#include "user.h"
#include"eventdescriptionwindow.h"
User::User(const QString& _login, const QString& _pass): login(_login), password(_pass){}

bool User::searchByDate()
{
    return true;
}

bool User::searchByName()
{
    return true;
}

bool User::openEvent(const Event &_event)
{
 EventDescriptionWindow*descWind=new EventDescriptionWindow();
    descWind->setEvent(_event);
    descWind->displayInfo();
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
