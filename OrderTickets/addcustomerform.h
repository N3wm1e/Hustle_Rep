#ifndef ADDCUSTOMERFORM_H
#define ADDCUSTOMERFORM_H

#include <QDialog>
#include <QMessageBox>
#include <customer.h>
#include <administrator.h>
#include <QIntValidator>

namespace Ui {
class AddCustomerForm;
}

class AddCustomerForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomerForm(QWidget *parent = nullptr);
    void setAccount(Administrator*);
    void setDefaultWindow();
    ~AddCustomerForm();

private slots:
    void on_addCustomerButton_clicked();

private:
    Ui::AddCustomerForm *ui;
    Administrator* currentAdmin;
    QIntValidator* validator;
};

#endif // ADDCUSTOMERFORM_H
