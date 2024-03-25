#include "mainmenu.h"
#include "ui_mainmenu.h"
#include"event.h"
#include "eventdescriptionwindow.h"
MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
    , currentCustomer(nullptr)
{
    ui->setupUi(this);
    StyleHandler::setFonts();
    this->setWindowTitle("Online Cash Register");
    this->setWindowIcon(QIcon("://img/Icon.png"));
    ui->lineEdit->setStyleSheet(StyleHandler::getStyleForSearch());
    ui->searchButton->setStyleSheet(StyleHandler::getStyleForSearchButton());
    ui->justButton->setStyleSheet(StyleHandler::getStyleForButton());
    Event ev1("afff"),ev2("ffff");
    ev1.getEventTickets().push_back(Ticket("Ticket1"));
    ev1.getEventTickets().push_back(Ticket("Ticket2"));
    ev2.getEventTickets().push_back(Ticket("Ticket3"));
    ev2.getEventTickets().push_back(Ticket("Ticket4"));
    ev2.getEventTickets().push_back(Ticket("Ticket5"));
    Event::getEvents().push_back(ev1);
    Event::getEvents().push_back(ev2);

}

void MainMenu::setAccount(Customer *_customer)
{
    currentCustomer=_customer;
}

MainMenu::~MainMenu()
{
    currentCustomer=nullptr;
    delete ui;
}


void MainMenu::on_searchButton_clicked()
{
    qDebug() << "Click";
    for(const auto&i:Event::getEvents()){
        if(ui->lineEdit->text() == i.getEventName()) ui->eventList->addItem(i.getEventName());
    }
}


void MainMenu::on_justButton_clicked()
{
    emit TransitToAuthorization();
}


void MainMenu::on_showAllEventsButton_clicked()
{
    for (const auto&i:Event::getEvents()) {
        ui->eventList->addItem(i.getEventName());
    }
}


void MainMenu::on_eventList_itemDoubleClicked(QListWidgetItem *item)
{
    Event event("");
    for (const auto&i:Event::getEvents()) {
        if(i.getEventName()==item->text())event=i;
    }
    EventDescriptionWindow* descWind=new EventDescriptionWindow(event);
    descWind->setModal(true);
    descWind->exec();
}

