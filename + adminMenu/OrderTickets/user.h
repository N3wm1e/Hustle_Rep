#ifndef USER_H
#define USER_H
#include <QString>
#include <event.h>
#include <eventdescriptionwindow.h>

class Customer;
class User
{
    QString login;
    QString password;
public:
    User(const QString&, const QString&);
    QStringList searchByDate(const QDate&);
    QString searchByName(const QString&);
    QStringList showAllEvents();
    bool openEvent(Event*, Customer*);
    bool Authorization();
    QString getLogin() const;
    QString getPassword() const;
    void setLogin(const QString&);
    void setPassword(const QString&);

private:
    EventDescriptionWindow*descWind;
};

#endif // USER_H
