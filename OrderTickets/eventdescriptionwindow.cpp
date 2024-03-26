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
    for (Ticket& tic : event->getEventTickets()) {
        if(!tic.getBought())
        {
            customer->getBoughtTickets().push_back(tic);
            tic.setBought(true);
            customer->setMoney(customerMoney-tic.getTicketPrice());
            ui->labelForTicketsCount->setText(QString::number(freeTicketsCount(event)));
            break;
        }
    }
}

