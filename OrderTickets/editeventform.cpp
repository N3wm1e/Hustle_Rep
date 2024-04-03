#include "editeventform.h"
#include "ui_editeventform.h"
EditEventForm::EditEventForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditEventForm)
    , chosenEvent(nullptr)
    , currentAdmin(nullptr)
{
    ui->setupUi(this);
    this->setWindowTitle("Online Cash Register");
    this->setWindowIcon(QIcon("://img/Icon.png"));
    setStyles();
}

EditEventForm::~EditEventForm()
{
    delete ui;
}
void EditEventForm::on_editEvent_ConfirmBtn_clicked()
{
    if(checkFields()){
        currentAdmin->deleteEventTickets(*chosenEvent);
        currentAdmin->editEvent(chosenEvent,ui->editEvent_NameEdit->text(),ui->editEvent_TimeEdit->dateTime(),ui->editEvent_TicketAmountEdit->text().toInt(),ui->editEvent_TicketPriceEdit->text().toInt());
        QMessageBox::information(this,"Online Cash Register","Event "+chosenEvent->getEventName()+" edited successfully!");
        this->close();
    }
}
bool EditEventForm::checkFields(){
    if(isFieldsFilled()){
        QMessageBox::warning(this,"Online Cash Register","Fill all the Fields!");
        return false;
    }
    else if(!ui->editEvent_TicketAmountEdit->text().toInt()){
        QMessageBox::warning(this,"Online Cash Register","Ticket Amount should be a number");
        return false;
    }
    else if(!ui->editEvent_TicketPriceEdit->text().toInt()){
        QMessageBox::warning(this,"Online Cash Register","Ticket Price should be a number");
        return false;
    }
    return true;
}
void EditEventForm::fillFields(){
    ui->editEvent_NameEdit->setText(chosenEvent->getEventName());
    ui->editEvent_TimeEdit->setDateTime(chosenEvent->getEventTime());
    ui->editEvent_TicketAmountEdit->setText(QString::number(chosenEvent->getEventTickets().size()));
    if(chosenEvent->getEventTickets().empty()){
        ui->editEvent_TicketPriceEdit->setText(0);
    }
    else{
        ui->editEvent_TicketPriceEdit->setText(QString::number(chosenEvent->getEventTickets().begin()->getTicketPrice()));
    }
}
bool EditEventForm::isFieldsFilled(){
    return ui->editEvent_TicketAmountEdit->text().isEmpty()||ui->editEvent_TicketPriceEdit->text().isEmpty()||ui->editEvent_NameEdit->text().isEmpty();
}

void EditEventForm::setEventForEdit(Event *_chosenEvent){
    chosenEvent = _chosenEvent;
}

bool EditEventForm::setAdmin(Administrator*_currentAdmin){
    currentAdmin = _currentAdmin;
    return true;
}

void EditEventForm::setStyles()
{
    ui->editEvent_ConfirmBtn->setStyleSheet(StyleHandler::getStyleForButton());
    ui->editEvent_NameEdit->setStyleSheet(StyleHandler::getStyleForInput());
    ui->editEvent_NameLabel->setStyleSheet(StyleHandler::getStyleForText());
    ui->editEvent_TicketAmountLabel->setStyleSheet(StyleHandler::getStyleForText());
    ui->editEvent_TicketAmountEdit->setStyleSheet(StyleHandler::getStyleForInput());
    ui->editEvent_TicketPriceLabel->setStyleSheet(StyleHandler::getStyleForText());
    ui->editEvent_TicketPriceEdit->setStyleSheet(StyleHandler::getStyleForInput());
    ui->editEvent_TimeLabel->setStyleSheet(StyleHandler::getStyleForText());
    ui->editEvent_TimeEdit->setStyleSheet(StyleHandler::getStyleForInput());
}
