#include <adminmenu.h>
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
    setStyles();
}

void AdminMenu::setAccount(Administrator * _admin)
{
    currentAdmin=_admin;
}

void AdminMenu::setDefaultWindow()
{
    ui->accountsList->clear();
    ui->ticketList->clear();
    ui->eventsList->clear();
    ui->showOnlyBoughtCheck->setChecked(false);
}

void AdminMenu::setStyles()
{
    ui->RemoveAllTicketsOnEvent->setStyleSheet(StyleHandler::getStyleForButton());
    ui->addCustomerButton->setStyleSheet(StyleHandler::getStyleForButton());
    ui->editCustomerButton->setStyleSheet(StyleHandler::getStyleForButton());
    ui->editEventBtn->setStyleSheet(StyleHandler::getStyleForButton());
    ui->addEventBtn->setStyleSheet(StyleHandler::getStyleForButton());
    ui->deleteEventBtn->setStyleSheet(StyleHandler::getStyleForButton());
    ui->deleteAllTicketsBtn->setStyleSheet(StyleHandler::getStyleForButton());
    ui->deleteTicketBtn->setStyleSheet(StyleHandler::getStyleForButton());
    ui->logOutButton->setStyleSheet(StyleHandler::getStyleForButton());
    ui->showAllTicketsBtn->setStyleSheet(StyleHandler::getStyleForButton());
    ui->showAllEventsBtn->setStyleSheet(StyleHandler::getStyleForButton());
    ui->showAllAccountsBtn->setStyleSheet(StyleHandler::getStyleForButton());
    ui->eventsList->setStyleSheet(StyleHandler::getStyleForList());
    ui->accountsList->setStyleSheet(StyleHandler::getStyleForList());
    ui->ticketList->setStyleSheet(StyleHandler::getStyleForList());
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
    addCustomerForm->setDefaultWindow();
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


void AdminMenu::on_showAllTicketsBtn_clicked()
{
    ui->ticketList->clear();
    //qDebug() << ui->showOnlyBoughtCheck->isChecked();
    if(ui->showOnlyBoughtCheck->isChecked()){
        for(auto&i:Event::getEvents()){
            for(const auto&j:i.getEventTickets()){
                if(j.getBought())ui->ticketList->addItem(j.getEventName() + " | " + QString::number(j.getId()) + " | " + j.getBuyerName() + " | " + QString::number(j.getTicketPrice()));
            }
        }
    }
    else{
        for(auto&i:Event::getEvents()){
            for(const auto&j:i.getEventTickets()){
                ui->ticketList->addItem(j.getEventName() + " | " + QString::number(j.getId()) + " | " + j.getBuyerName() + " | " + QString::number(j.getTicketPrice()));
            }
        }
    }
}


void AdminMenu::on_deleteTicketBtn_clicked()
{
    if(!ui->ticketList->selectedItems().size()){
        QMessageBox::warning(this, "Online Cash Register", "You should choose a ticket to delete!");
        return;
    }
    const int eventNameIndex = 0;
    const int eventIdIndex = 1;
    auto selectedItems = ui->ticketList->selectedItems();
    QStringList stringList = selectedItems.first()->text().split(" | ", Qt::SkipEmptyParts);
    auto eventIter = Event::searchEventByName(stringList[eventNameIndex]);
    currentAdmin->deleteTicket(*eventIter->searchTicketById(stringList[eventIdIndex].toInt()));
    QMessageBox::information(this, "Online Cash Register", "The ticket successfully deleted!");
    on_showAllTicketsBtn_clicked();
}


void AdminMenu::on_deleteAllTicketsBtn_clicked()
{
    currentAdmin->deleteAllTickets();
    QMessageBox::information(this, "Online Cash Register", "All tickets successfully deleted!");
    on_showAllTicketsBtn_clicked();
}

void AdminMenu::on_addEventBtn_clicked()
{
    if(!addEventForm){
        addEventForm = new AddEventForm;
    }
    addEventForm->exec();
    on_showAllEventsBtn_clicked();
    on_showAllTicketsBtn_clicked();
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
                on_showAllTicketsBtn_clicked();
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
        currentAdmin->deleteEventTickets(*eventIt);
        if(eventIt != eventList.end()){
            int index = std::distance(eventList.begin(), eventIt);
            Event::getEvents().removeAt(index);
            ui->eventsList->takeItem(ui->eventsList->row(ui->eventsList->currentItem()));
            QMessageBox::information(this, "Online Cash Register", "The event is successfully deleted!");
            on_showAllEventsBtn_clicked();
            on_showAllTicketsBtn_clicked();
        }
        else{
            QMessageBox::critical(this,"Online Cash Register","Cannot find event!");
        }
    }
    else{
        QMessageBox::warning(this,"Online Cash Register","Choose event from list!");
    }
}

void AdminMenu::on_showAllEventsBtn_clicked()
{
    ui->eventsList->clear();
    for(const auto&event:Event::getEvents()) ui->eventsList->addItem(event.getEventName());
}

void AdminMenu::on_RemoveAllTicketsOnEvent_clicked()
{    if(!ui->eventsList->selectedItems().size()){
        QMessageBox::warning(this, "Online Cash Register", "You should choose a event for deleting tickets!");
        return;
    }
    QString chosenEvent = ui->eventsList->selectedItems().first()->text();
    for (auto& event : Event::getEvents()) {
        if(chosenEvent==event.getEventName())
        {
            for(auto &ticket:event.getEventTickets()){
                currentAdmin->deleteTicket(ticket);
            }
            QMessageBox::information(this, "Online Cash Register", "Deleting of tickets is successful");
            on_showAllTicketsBtn_clicked();
            return;
        }
    }
}
