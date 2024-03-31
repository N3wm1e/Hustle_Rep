#ifndef ADDCUSTOMERFORM_H
#define ADDCUSTOMERFORM_H

#include <QDialog>
#include <QMessageBox>
#include <customer.h>
#include <administrator.h>

namespace Ui {
class AddCustomerForm;
}

class AddCustomerForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomerForm(QWidget *parent = nullptr);
    void setAccount(Administrator*);
    ~AddCustomerForm();

private slots:
    void on_addCustomerButton_clicked();

private:
    Ui::AddCustomerForm *ui;
    Administrator* currentAdmin;
};

#endif // ADDCUSTOMERFORM_H
