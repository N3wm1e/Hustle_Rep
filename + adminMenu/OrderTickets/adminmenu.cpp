#include "adminmenu.h"
#include "ui_adminmenu.h"

AdminMenu::AdminMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminMenu)
    , addCustomerForm(nullptr)
    , editCustomerForm(nullptr)
    , addEventForm(nullptr)
    , editEventForm(nullptr)
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


void AdminMenu::on_addEventBtn_clicked()
{
    if(!addEventForm){
        addEventForm = new AddEventForm;
    }
    addEventForm->exec();
}


void AdminMenu::on_editEventBtn_clicked()
{
    if(!ui->eventsList->currentItem()){
        QMessageBox::warning(this, "Online Cash Register", "Choose an event first!");
    }
    else{
        if(!editEventForm){
            editEventForm = new EditEventForm;
        }
        for(Event &event:Event::getEvents()){
            if(event.getEventName()==ui->eventsList->currentItem()->text()){
                editEventForm->setEventForEdit(&event);
                editEventForm->setAdmin(currentAdmin);
                editEventForm->fillFields();
                editEventForm->exec();
                break;
            }
        }
    }
}


void AdminMenu::on_deleteEventBtn_clicked()
{
    QList<Event>eventList = Event::getEvents();
    if(ui->eventsList->currentItem()){
        QString eventName= ui->eventsList->currentItem()->text();
        auto eventIt = std::find_if(eventList.begin(), eventList.end(), [eventName](const Event& other){
            return eventName == other.getEventName();
        });
        if(eventIt != eventList.end()){
            int index = std::distance(eventList.begin(), eventIt);
            Event::getEvents().removeAt(index);
            ui->eventsList->takeItem(ui->eventsList->row(ui->eventsList->currentItem()));
        }
        else{
            QMessageBox::critical(this,"Online Cash Register","Cannot find event!");
        }
    }
    else{
        QMessageBox::warning(this,"Online Cash Register","Choose event from list!");
    }
}

