#include "eventdescriptionwindow.h"
#include "ui_eventdescriptionwindow.h"
#include "event.h"
EventDescriptionWindow::EventDescriptionWindow(Event _event, QWidget *parent)
    : QDialog(parent)
    ,event(_event)
    , ui(new Ui::EventDescriptionWindow)

{
    ui->setupUi(this);
    ui->labelForEventName->setText(event.getEventName());
    ui->labelForTicketsCount->setText(QString::number(event.getEventTickets().size()));
    if(event.getFinished()) ui->labelForStatus->setText("Finished");
    else ui->labelForStatus->setText("Active display");
}
EventDescriptionWindow::~EventDescriptionWindow()
{
    delete ui;
}




