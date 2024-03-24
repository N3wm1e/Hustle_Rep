#include "user.h"

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
    return _event!=Event(QString());
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
