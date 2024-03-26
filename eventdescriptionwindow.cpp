#include "eventdescriptionwindow.h"
#include "ui_eventdescriptionwindow.h"
#include "event.h"
#include"customer.h"
EventDescriptionWindow::EventDescriptionWindow(QWidget *parent)
    : QDialog(parent)
    ,event(Event(""))
    ,customer(nullptr)
    , ui(new Ui::EventDescriptionWindow)

{
    ui->setupUi(this);

}
void EventDescriptionWindow::setEvent(const Event&_event)
{
    event=_event;
}
int EventDescriptionWindow::freeTicketsCount(Event&)
{
    int freeTicketsCounter=0;
    for (Ticket& ticket : event.getEventTickets()) {
        if(ticket.getBought()) freeTicketsCounter++;
    }
    return freeTicketsCounter;
}
void EventDescriptionWindow::displayInfo()
{
    ui->labelForEventName->setText(event.getEventName());
    ui->labelForTicketsCount->setText(QString::number(freeTicketsCount(event)));
    if(event.getFinished()) ui->labelForStatus->setText("Finished");
    else ui->labelForStatus->setText("Active display");
}
EventDescriptionWindow::~EventDescriptionWindow()
{
    delete ui;
}
void EventDescriptionWindow::setCustomer(Customer*_customer)
{
    customer=_customer;
}

void EventDescriptionWindow::on_BuyTicketButton_clicked()
{
    int customerMoney=customer->getMoney();
    for (Ticket& tic : event.getEventTickets()) {
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

