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

    Customer* getCurrentCustomer();
    void setCurrentCustomer(Customer*);

    void setStyles();

signals:
    void TransitToCustomerMenuSignal();

private slots:
    void Login();

private:
    Ui::Authorization *ui;
    Customer* currentCustomer;
};

#endif // AUTHORIZATION_H
