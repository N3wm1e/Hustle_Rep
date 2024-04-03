#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QWidget>
#include <administrator.h>
#include <addcustomerform.h>
#include <editcustomerform.h>
#include <addeventform.h>
#include <editeventform.h>
namespace Ui {
class AdminMenu;
}

class AdminMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AdminMenu(QWidget *parent = nullptr);
    void setAccount(Administrator*);
    static Event* getSelectedEvent();
    ~AdminMenu();
signals:
    void TransitToAuthorization();
private slots:
    void on_logOutButton_clicked();

    void on_addCustomerButton_clicked();

    void on_editCustomerButton_clicked();

    void on_showAllAccountsBtn_clicked();

    void on_addEventBtn_clicked();

    void on_editEventBtn_clicked();

    void on_deleteEventBtn_clicked();

    void on_showAllEventsBtn_clicked();

private:
    Ui::AdminMenu *ui;
    Administrator* currentAdmin;
    AddCustomerForm* addCustomerForm;
    EditCustomerForm* editCustomerForm;
    AddEventForm* addEventForm;
    EditEventForm* editEventForm;

};

#endif // ADMINMENU_H
