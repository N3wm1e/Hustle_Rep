#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
    , currentCustomer(nullptr)
{
    ui->setupUi(this);

    StyleHandler::setFonts();
    this->setWindowTitle("Online Cash Register");
    this->setWindowIcon(QIcon("://img/Icon.png"));
}

void MainMenu::setAccount(Customer *_customer)
{
    currentCustomer=_customer;
}

void MainMenu::testAddEvents()
{
    QList<Ticket>testTickets1;
    QList<Ticket>testTickets2;
    Event ev1("TestFilm1"),ev2("TestFilm2");
    ev1.setEventTime(QDateTime(QDate(2024, 12, 1), QTime(11,50)));
    ev2.setEventTime(QDateTime(QDate(2025, 11, 1), QTime(18,15)));
    Ticket tic1("tic1",0,100);
    tic1.setEventName(ev1.getEventName());
    Ticket tic2("tic2",1,100);
    tic2.setEventName(ev1.getEventName());
    tic1.setBought(false);
    tic2.setBought(false);
    testTickets1.push_back(tic1);
    testTickets1.push_back(tic2);
    ev1.setEventTickets(testTickets1);

    Ticket tic3("tic3",2,220);
    tic3.setEventName(ev2.getEventName());
    Ticket tic4("tic4",3,220);
    tic4.setEventName(ev2.getEventName());
    tic3.setBought(false);
    tic4.setBought(false);
    testTickets2.push_back(tic3);
    testTickets2.push_back(tic4);
    ev2.setEventTickets(testTickets2);

    ev1.setFinished(0);
    ev2.setFinished(0);

    Event::getEvents().push_back(ev1);
    Event::getEvents().push_back(ev2);
}

void MainMenu::setDefaultMenu()
{
    searchByDate=false;
    ui->searchDate->hide();
    ui->searchInput->show();
    ui->searchInput->clear();
    ui->eventList->clear();
    ui->chooseSearch->setCurrentIndex(0);
    setStyles();
    ui->balanceLabel->setText("None");
    ui->ticketsList->clear();
    ui->searchDate->setDate(QDateTime::currentDateTime().date());
    ui->searchDate->setMinimumDate(QDateTime::currentDateTime().date());
}

MainMenu::~MainMenu()
{
    currentCustomer=nullptr;
    delete ui;
}


void MainMenu::on_searchButton_clicked()
{
    ui->eventList->clear();
    if(searchByDate){ //Выдаём ивенты по дате
        for(const auto &i: currentCustomer->searchByDate(ui->searchDate->date())){
            ui->eventList->addItem(i);
        }
    }
    else{
        if(ui->searchInput->text()==""){ //Выдаём все ивенты
            for(const auto &i:currentCustomer->showAllEvents()){
                ui->eventList->addItem(i);
            }
        }
        else{ //Выдаём ивент по названию
            QString eventName = currentCustomer->searchByName(ui->searchInput->text());
            if(eventName!="")
                ui->eventList->addItem(eventName);
        }
    }

}


void MainMenu::on_justButton_clicked()
{
    currentCustomer->Authorization();
    emit TransitToAuthorization();
}


void MainMenu::on_chooseSearch_currentIndexChanged(int index)
{
    ui->eventList->clear();
    if(index){
        ui->searchInput->hide();
        ui->searchDate->setFixedWidth(ui->searchInput->width());
        ui->searchDate->adjustSize();
        ui->horizontalLayout->insertWidget(1,ui->searchDate);
        ui->searchDate->show();
        searchByDate=true;
    }
    else{
        ui->searchDate->hide();
        ui->searchInput->show();
        searchByDate=false;
    }
}

void MainMenu::setStyles()
{
    ui->searchInput->setStyleSheet(StyleHandler::getStyleForSearch());
    ui->searchButton->setStyleSheet(StyleHandler::getStyleForSearchButton());
    ui->justButton->setStyleSheet(StyleHandler::getStyleForButton());
    ui->searchDate->setStyleSheet(StyleHandler::getStyleForDate());

    ui->updateBalanceBtn->setStyleSheet(StyleHandler::getStyleForButton());
    ui->searchButton->setStyleSheet(StyleHandler::getStyleForButton());
    ui->removeTicketButton->setStyleSheet(StyleHandler::getStyleForButton());
    ui->showAllEventsButton->setStyleSheet(StyleHandler::getStyleForButton());
    ui->showAllBoughtTickets->setStyleSheet(StyleHandler::getStyleForButton());
    ui->balanceLabel->setStyleSheet(StyleHandler::getStyleForText());

    ui->eventList->setStyleSheet(StyleHandler::getStyleForList());
    ui->ticketsList->setStyleSheet(StyleHandler::getStyleForList());
}

void MainMenu::on_updateBalanceBtn_clicked()
{
    ui->balanceLabel->setText(QString::number(currentCustomer->getMoney()));
}


void MainMenu::on_eventList_itemDoubleClicked(QListWidgetItem *item)
{
    Event* event=nullptr;
    for (auto&i:Event::getEvents()) {
        if(i.getEventName()==item->text())event=&i;
    }

    currentCustomer->openEvent(event,currentCustomer);
}


void MainMenu::on_showAllEventsButton_clicked()
{
    ui->eventList->clear();
    for(const auto &i:currentCustomer->showAllEvents()){
        ui->eventList->addItem(i);
    }
}


void MainMenu::on_removeTicketButton_clicked()
{
    if(!currentCustomer->getBoughtTickets().size()){
        QMessageBox::warning(this, "Online Cash Register", "There's no tickets");
        return;
    }
    if(!ui->ticketsList->currentItem()){
        QMessageBox::warning(this, "Online Cash Register", "You didn't choose any ticket");
        return;
    }
    //check();
    //qDebug() << "aldoasldoasold";
    QListWidgetItem *item = ui->ticketsList->currentItem();
    QStringList ticketRow = item->text().split(" | ");
    QList<Ticket*>::Iterator ticketIterator = currentCustomer->findTicket(ticketRow[1].toInt());
    if(currentCustomer->isTicketFound(ticketIterator)){
        currentCustomer->removeTicket(*ticketIterator);
        //qDebug() << ticketIterator->getEventName() << " " << ticketIterator->getBuyerName() << " " << ticketIterator->getBought();
        delete ui->ticketsList->takeItem(ui->ticketsList->row(item));
    }
     //check();
}


void MainMenu::on_showAllBoughtTickets_clicked()
{
    if(!currentCustomer){
        QMessageBox::warning(this, "Online Cash Register", "Current customer is null");
        return;
    }
    if(!currentCustomer->getBoughtTickets().size()){
        QMessageBox::warning(this, "Online Cash Register", "Nothing to see here");
        return;
    }
    ui->ticketsList->clear();
    for(const auto &ticket : currentCustomer->getBoughtTickets()){
        QListWidgetItem *item = new QListWidgetItem();
        QString ticketRow = ticket->getEventName() + " | "
                            + QString::number(ticket->getId()) + " | "
                            + QString::number(ticket->getTicketPrice());
        item->setData(Qt::DisplayRole, ticketRow);
        ui->ticketsList->addItem(ticketRow);
    }
}

