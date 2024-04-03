#include "addcustomerform.h"
#include "ui_addcustomerform.h"
#include "QIntValidator"

AddCustomerForm::AddCustomerForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCustomerForm)
{
    ui->setupUi(this);
    this->setWindowTitle("Online Cash Register");
    this->setWindowIcon(QIcon("://img/Icon.png"));
}

void AddCustomerForm::setAccount(Administrator * _admin)
{
    currentAdmin=_admin;
}

AddCustomerForm::~AddCustomerForm()
{
    delete ui;
}

void AddCustomerForm::on_addCustomerButton_clicked()
{
    if(ui->loginInput->text()=="" || ui->passInput->text()=="" || ui->moneyInput->text()==""){
        QMessageBox::warning(this, "Online Cash Register", "You should fill all these forms!");
        return;
    }
    for(const auto &i:Customer::getCustomers()){
        if(i.getLogin()==ui->loginInput->text()){
            QMessageBox::warning(this, "Online Cash Register", "Login is already taken");
            return;
        }
    }
    for(const auto &i:Administrator::getAdmins()){
        if(i.getLogin()==ui->loginInput->text()){
            QMessageBox::warning(this, "Online Cash Register", "Login is already taken");
            return;
        }
    }
    QIntValidator* validator = new QIntValidator(this);
    ui->moneyInput->setValidator(validator);
    if(ui->moneyInput->hasAcceptableInput()){
        currentAdmin->addCustomer(ui->loginInput->text(), ui->passInput->text(), ui->moneyInput->text().toInt());
        QMessageBox::information(this, "Online Cash Register", "Account " + ui->loginInput->text() + " added successfully");
    }else{
        QMessageBox::critical(this, "Online Cash Register", "You should input digits in 'money' field");
        return;
    }
    this->close();
}

