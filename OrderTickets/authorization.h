#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QDialog>
#include <QTextStream>
#include <QFile>
#include <QList>
#include <customer.h>
#include <administrator.h>
#include <stylehandler.h>

namespace Ui {
class Authorization;
}

class Authorization : public QDialog
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    void readAllAccounts();
    ~Authorization();

    void setStyles();

signals:
    void TransitToCustomerMenuSignal(Customer*);
    void TransitToAdminMenuSignal(Administrator*);

private slots:
    void Login();

private:
    Ui::Authorization *ui;
};

#endif // AUTHORIZATION_H
