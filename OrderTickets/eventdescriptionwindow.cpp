#include "eventdescriptionwindow.h"
#include "ui_eventdescriptionwindow.h"
#include "event.h"
#include"customer.h"
EventDescriptionWindow::EventDescriptionWindow(QWidget *parent)
    : QDialog(parent)
    ,event(nullptr)
    ,customer(nullptr)
    , ui(new Ui::EventDescriptionWindow)

{
    ui->setupUi(this);
    this->setWindowTitle("Online Cash Register");
    this->setWindowIcon(QIcon("://img/Icon.png"));
    setStyles();
}

void EventDescriptionWindow::setCustomer(Customer*_customer)
{
    customer=_customer;
}

void EventDescriptionWindow::setEvent(Event* _event)
{
    event=_event;
}

void EventDescriptionWindow::displayInfo()
{
    ui->labelForEventName->setText(event->getEventName());
    ui->labelForTicketsCount->setText(QString::number(freeTicketsCount(event)));
    QTime time = event->getEventTime().time();
    QDate date = event->getEventTime().date();
    ui->labelForTime->setText(QString::number(time.hour()) + ":" + QString::number(time.minute()) + " " + QString::number(date.day()) + "." + QString::number(date.month()) + "." + QString::number(date.year()));
    if(event->getFinished()) ui->labelForStatus->setText("Finished");
    else ui->labelForStatus->setText("Active");
}

void EventDescriptionWindow::displayTicketPrice(Event*_event)
{
    if(_event->getEventTickets().size()>0)
    {
        Ticket ticket=_event->getEventTickets()[0];
        ui->labelForTicketPrice->setText(QString::number(ticket.getTicketPrice()));
    }
}

void EventDescriptionWindow::setStyles()
{
    ui->BuyTicketButton->setStyleSheet(StyleHandler::getStyleForButton());
    ui->TicketPrice->setStyleSheet(StyleHandler::getStyleForText());
    ui->labelForTicketPrice->setStyleSheet(StyleHandler::getStyleForText());
    ui->labelForTicketsCount->setStyleSheet(StyleHandler::getStyleForText());
    ui->Tickets->setStyleSheet(StyleHandler::getStyleForText());
    ui->labelForStatus->setStyleSheet(StyleHandler::getStyleForText());
    ui->isFinishedStatus->setStyleSheet(StyleHandler::getStyleForText());
    ui->labelForTime->setStyleSheet(StyleHandler::getStyleForText());
    ui->EventTime->setStyleSheet(StyleHandler::getStyleForText());
    ui->labelForEventName->setStyleSheet(StyleHandler::getStyleForText());
    ui->EventName->setStyleSheet(StyleHandler::getStyleForText());
}
int EventDescriptionWindow::freeTicketsCount(Event* _event)
{
    int freeTicketsCounter=0;
    for (Ticket& ticket : _event->getEventTickets()) {
        if(!ticket.getBought()) freeTicketsCounter++;
    }
    return freeTicketsCounter;
}

EventDescriptionWindow::~EventDescriptionWindow()
{
    delete ui;
}


void EventDescriptionWindow::on_BuyTicketButton_clicked()
{
    int customerMoney=customer->getMoney();

    if(!event->getEventTickets().size()){
        QMessageBox::warning(this, "Online Cash Register", "There's no events");
        return;
    }
    if(!freeTicketsCount(event)){
        QMessageBox::warning(this, "Online Cash Register", "All tickets sold");
        return;
    }
    if(customerMoney < event->getEventTickets()[0].getTicketPrice()){
        QMessageBox::warning(this, "Online Cash Register", "You don't have enough money");
        return;
    }
    for (Ticket& tic : event->getEventTickets()) {
        if(!tic.getBought())
        {
            customer->getBoughtTickets().push_back(&tic);
            tic.setBought(true);
            tic.setBuyerName(customer->getLogin());
            customer->setMoney(customerMoney-tic.getTicketPrice());
            ui->labelForTicketsCount->setText(QString::number(freeTicketsCount(event)));
            break;
        }
    }
}

