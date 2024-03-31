#include "editcustomerform.h"
#include "ui_editcustomerform.h"

EditCustomerForm::EditCustomerForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditCustomerForm)
    , currentAdmin(nullptr)
    , chosenCustomer(nullptr)
{
    ui->setupUi(this);
    this->setWindowTitle("Online Cash Register");
    this->setWindowIcon(QIcon("://img/Icon.png"));
}

void EditCustomerForm::setAdministrator(Administrator * _admin)
{
    currentAdmin=_admin;
}

void EditCustomerForm::setCustomerForEdit(Customer * _customer)
{
    chosenCustomer=_customer;
}

void EditCustomerForm::fillFields()
{
    ui->loginInput->setText(chosenCustomer->getLogin());
    ui->passInput->setText(chosenCustomer->getPassword());
    ui->moneyInput->setText(QString::number(chosenCustomer->getMoney()));
}

EditCustomerForm::~EditCustomerForm()
{
    delete ui;
}

void EditCustomerForm::on_editCustomerButton_clicked()
{
    if(ui->loginInput->text()=="" || ui->passInput->text()=="" || ui->moneyInput->text()==""){
        QMessageBox::warning(this, "Online Cash Register", "You should fill all these forms!");
        return;
    }
    for(const auto &i:Customer::getCustomers()){
        if(i.getLogin()==chosenCustomer->getLogin())continue;
        if(i.getLogin()==ui->loginInput->text()){
            QMessageBox::warning(this, "Online Cash Register", "Login is already taken");
            return;
        }
    }
    for(const auto &i:Administrator::getAdmins()){
        if(i.getLogin()==chosenCustomer->getLogin())continue;
        if(i.getLogin()==ui->loginInput->text()){
            QMessageBox::warning(this, "Online Cash Register", "Login is already taken");
            return;
        }
    }
    QIntValidator* validator = new QIntValidator(this);
    ui->moneyInput->setValidator(validator);
    if(ui->moneyInput->hasAcceptableInput()){
        currentAdmin->editCustomer(chosenCustomer, ui->loginInput->text(), ui->passInput->text(), ui->moneyInput->text().toInt());
        QMessageBox::information(this, "Online Cash Register", "Account " + ui->loginInput->text() + " edited successfully");
    }else{
        QMessageBox::critical(this, "Online Cash Register", "You should input digits in 'money' field");
        return;
    }
    delete validator;
    this->close();
}

