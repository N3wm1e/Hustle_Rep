#ifndef EDITCUSTOMERFORM_H
#define EDITCUSTOMERFORM_H

#include <QDialog>
#include <administrator.h>
#include <QIntValidator>

namespace Ui {
class EditCustomerForm;
}

class EditCustomerForm : public QDialog
{
    Q_OBJECT

public:
    explicit EditCustomerForm(QWidget *parent = nullptr);
    void setAdministrator(Administrator*);
    void setCustomerForEdit(Customer*);
    void fillFields();
    ~EditCustomerForm();

private slots:
    void on_editCustomerButton_clicked();

private:
    Ui::EditCustomerForm *ui;
    Administrator* currentAdmin;
    Customer* chosenCustomer;
    QIntValidator* validator;
};

#endif // EDITCUSTOMERFORM_H
