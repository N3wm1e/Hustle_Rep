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

void AdminMenu::setDefaultWindow()
{
    ui->accountsList->clear();
    ui->ticketList->clear();
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
    for(auto&i:Event::getEvents()){
        for(const auto&j:i.getEventTickets()){
            ui->ticketList->addItem(j.getEventName() + " | " + QString::number(j.getId()) + " | " + j.getBuyerName() + " | " + QString::number(j.getTicketPrice()));
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


void AdminMenu::on_showAllBoughtTicketsBtn_clicked()
{   ui->ticketsListForAdmin->clear();
    QString ticketRow;
    for(auto&event:Event::getEvents())
    {
        for (auto& tic :event.getEventTickets() ) {
            if(tic.getBought()==true)
            {
                ticketRow = tic.getEventName() + " | "
                            + QString::number(tic.getId()) + " | "
                            + QString::number(tic.getTicketPrice());
                ui->ticketsListForAdmin->addItem(ticketRow);
            }
        }
    }
}


void AdminMenu::on_showAllEventsBtn_clicked()
{
    ui->eventListForAdmin->clear();
    for (const auto&i:Event::getEvents()) {
        ui->eventListForAdmin->addItem(i.getEventName());
    }
}


void AdminMenu::on_RemoveAllTicketsOnEvent_clicked()
{    if(!ui->ticketsListForAdmin->selectedItems().size()){
        QMessageBox::warning(this, "Online Cash Register", "You should choose a ticket to delete!");
        return;
    }
    QString chosenEvent = ui->eventListForAdmin->selectedItems().first()->text();
    for (auto& event : Event::getEvents()) {
        if(chosenEvent==event.getEventName())
        {
            for(auto &ticket:event.getEventTickets()){
                currentAdmin->deleteTicket(ticket);

            }
            return;
        }
    }
}

