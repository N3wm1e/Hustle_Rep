#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QWidget>
#include <administrator.h>
#include <addcustomerform.h>
#include <editcustomerform.h>
namespace Ui {
class AdminMenu;
}

class AdminMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AdminMenu(QWidget *parent = nullptr);
    void setAccount(Administrator*);
    void setDefaultWindow();
    ~AdminMenu();
signals:
    void TransitToAuthorization();
private slots:
    void on_logOutButton_clicked();

    void on_addCustomerButton_clicked();

    void on_editCustomerButton_clicked();

    void on_showAllAccountsBtn_clicked();

    void on_showAllTicketsBtn_clicked();

    void on_deleteTicketBtn_clicked();

    void on_deleteAllTicketsBtn_clicked();

private:
    Ui::AdminMenu *ui;
    Administrator* currentAdmin;
    AddCustomerForm* addCustomerForm;
    EditCustomerForm* editCustomerForm;
};

#endif // ADMINMENU_H
