#include "eventdescriptionwindow.h"
#include "ui_eventdescriptionwindow.h"
#include "event.h"
#include "customer.h"
EventDescriptionWindow::EventDescriptionWindow(QWidget *parent)
    : QDialog(parent)
    ,customer(nullptr)
    ,event(Event(""))
    , ui(new Ui::EventDescriptionWindow)

{
    ui->setupUi(this);

}
void EventDescriptionWindow::setEvent(const Event&_event)
{
    event=_event;
}
void EventDescriptionWindow::displayInfo()
{
    ui->labelForEventName->setText(event.getEventName());
    ui->labelForTicketsCount->setText(QString::number(event.getEventTickets().size()));
    if(event.getFinished()) ui->labelForStatus->setText("Finished");
    else ui->labelForStatus->setText("Active display");
}
EventDescriptionWindow::~EventDescriptionWindow()
{
    delete ui;
}
void EventDescriptionWindow::setCustomer(const Customer*_customer)
{
    customer=_customer;
}

void EventDescriptionWindow::on_BuyTicketButton_clicked()
{
    currentCustomer->
}

