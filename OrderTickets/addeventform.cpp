#include "addeventform.h"
#include "ui_addeventform.h"

AddEventForm::AddEventForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddEventForm)
{
    ui->setupUi(this);
    this->setWindowTitle("Online Cash Register");
    this->setWindowIcon(QIcon("://img/Icon.png"));
    setStyles();
}

AddEventForm::~AddEventForm()
{
    delete ui;
}

void AddEventForm::on_addEventBtn_clicked()
{
    if(checkFields()){
        currentAdmin->addEvent(ui->eventNameEdit->text(), ui->eventTimeEdit->dateTime(), ui->eventTicketAmountEdit->text().toInt(), ui->eventTicketPriceEdit->text().toInt());
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

void AddEventForm::setStyles()
{
    ui->addEventBtn->setStyleSheet(StyleHandler::getStyleForButton());
    ui->eventNameEdit->setStyleSheet(StyleHandler::getStyleForInput());
    ui->eventNameLabel->setStyleSheet(StyleHandler::getStyleForText());
    ui->eventTicketAmountEdit->setStyleSheet(StyleHandler::getStyleForInput());
    ui->eventTicketAmountLabel->setStyleSheet(StyleHandler::getStyleForText());
    ui->eventTicketPriceEdit->setStyleSheet(StyleHandler::getStyleForInput());
    ui->eventTicketPriceLabel->setStyleSheet(StyleHandler::getStyleForText());
    ui->eventTimeEdit->setStyleSheet(StyleHandler::getStyleForDate());
    ui->eventTimeLabel->setStyleSheet(StyleHandler::getStyleForText());
}

void AddEventForm::setAdmin(Administrator * _admin)
{
    currentAdmin=_admin;
}
bool AddEventForm::isFieldsFilled(){
    return ui->eventNameEdit->text().isEmpty() || ui->eventTicketAmountEdit->text().isEmpty() || ui->eventTicketPriceEdit->text().isEmpty();
}
