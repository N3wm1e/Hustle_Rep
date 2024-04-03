#include "addeventform.h"
#include "ui_addeventform.h"

AddEventForm::AddEventForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddEventForm)
{
    ui->setupUi(this);
    this->setWindowTitle("Online Cash Register");
    this->setWindowIcon(QIcon("://img/Icon.png"));
}

AddEventForm::~AddEventForm()
{
    delete ui;
}

void AddEventForm::on_addEventBtn_clicked()
{
    if(checkFields()){
        Event newEvent(ui->eventNameEdit->text());
        newEvent.setEventTime(ui->eventTimeEdit->dateTime());
        newEvent.setEventTickets(newEvent.generateTickets(ui->eventTicketAmountEdit->text().toInt(),ui->eventTicketPriceEdit->text().toInt()));
        newEvent.setFinished(ui->eventTimeEdit->dateTime() <= QDateTime::currentDateTime());
        Event::getEvents().push_back(newEvent);
        this->close();
    }
}
bool AddEventForm::checkFields(){
    if(isFieldsFilled()){
        QMessageBox::warning(this, "Online Cash Register", "Fields are not filled up!");
        return false;
    }
    else if(!ui->eventTicketAmountEdit->text().toInt()){
        QMessageBox::warning(this, "Online Cash Register", "Tickets Amount should be in digits!");
        return false;
    }
    else if(!ui->eventTicketPriceEdit->text().toInt()){
        QMessageBox::warning(this, "Online Cash Register", "Tickets Price should be in digits!");
        return false;
    }
    else if(Event::isEventInList(Event::getEvents(),ui->eventNameEdit->text())){
        QMessageBox::warning(this, "Online Cash Register", "Event with this name already exists!");
        return false;
    }
    return true;
}
bool AddEventForm::isFieldsFilled(){
    return ui->eventNameEdit->text().isEmpty() || ui->eventTicketAmountEdit->text().isEmpty() || ui->eventTicketPriceEdit->text().isEmpty();
}
