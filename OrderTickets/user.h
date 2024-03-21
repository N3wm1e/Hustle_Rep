#ifndef USER_H
#define USER_H
#include <QString>
#include <event.h>

class User
{
    QString login;
    QString password;
public:
    User(const QString&, const QString&);
    bool searchByDate();
    bool searchByName();
    bool openEvent(const Event&);
    bool Authorization();
    QString getLogin() const;
    QString getPassword() const;
};

#endif // USER_H
