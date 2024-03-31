#include "adminmenu.h"
#include "ui_adminmenu.h"

AdminMenu::AdminMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminMenu)
    , addCustomerForm(nullptr)
    , editCustomerForm(nullptr)
{
    ui->setupUi(this);
    this->setWindowTitle("Online Cash Register");
    this->setWindowIcon(QIcon("://img/Icon.png"));
}

void AdminMenu::setAccount(Administrator * _admin)
{
    currentAdmin=_admin;
}

AdminMenu::~AdminMenu()
{
    if(addCustomerForm){
        delete addCustomerForm;
        addCustomerForm=nullptr;
    }
    if(editCustomerForm){
        delete editCustomerForm;
        editCustomerForm=nullptr;
    }
    delete ui;
}

void AdminMenu::on_logOutButton_clicked()
{
    emit TransitToAuthorization();
}


void AdminMenu::on_addCustomerButton_clicked()
{
    if(!addCustomerForm)
        addCustomerForm = new AddCustomerForm;
    addCustomerForm->exec();
}


void AdminMenu::on_editCustomerButton_clicked()
{
    if(!ui->accountsList->selectedItems().size()){
        QMessageBox::critical(this, "Online Cash Register", "You should pick an account of list");
        return;
    }
    if(!editCustomerForm)
        editCustomerForm= new EditCustomerForm();
    for(auto&i:Customer::getCustomers()){
        if(i.getLogin()==ui->accountsList->selectedItems().first()->text()){
            editCustomerForm->setCustomerForEdit(&i);
        }
    }
    editCustomerForm->setAdministrator(currentAdmin);
    editCustomerForm->fillFields();
    editCustomerForm->exec();
}


void AdminMenu::on_showAllAccountsBtn_clicked()
{
    ui->accountsList->clear();
    for(const auto&i:Customer::getCustomers())
        ui->accountsList->addItem(i.getLogin());
}

