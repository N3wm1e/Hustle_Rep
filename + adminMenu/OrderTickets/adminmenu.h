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
    ~AdminMenu();
signals:
    void TransitToAuthorization();
private slots:
    void on_logOutButton_clicked();

    void on_addCustomerButton_clicked();

    void on_editCustomerButton_clicked();

    void on_showAllAccountsBtn_clicked();

private:
    Ui::AdminMenu *ui;
    Administrator* currentAdmin;
    AddCustomerForm* addCustomerForm;
    EditCustomerForm* editCustomerForm;
};

#endif // ADMINMENU_H
