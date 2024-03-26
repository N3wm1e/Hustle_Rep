#ifndef USER_H
#define USER_H
#include <QString>
#include <event.h>
#include <eventdescriptionwindow.h>
#include <customer.h>
class User
{
    QString login;
    QString password;
public:
    User(const QString&, const QString&);
    bool searchByDate();
    bool searchByName();
    bool openEvent(const Event&,const Customer*);
    bool Authorization();
    QString getLogin() const;
    QString getPassword() const;
};

#endif // USER_H
