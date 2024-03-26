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
    QList<Ticket>testTickets1;
    QList<Ticket>testTickets2;
    Ticket tic1("tic1");
    tic1.setTicketPrice(100);
    Ticket tic2("tic2");
    tic2.setTicketPrice(150);
    testTickets1.push_back(tic1);
    testTickets2.push_back(tic2);
    Event ev1("TestFilm1"),ev2("TestFilm2");
    ev1.setEventTickets(testTickets1);
    ev2.setEventTickets(testTickets2);
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
    ui->eventList->clear();
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

   currentCustomer->openEvent(event,currentCustomer);
}

