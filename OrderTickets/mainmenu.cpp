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
    ui->lineEdit->setStyleSheet(StyleHandler::getStyleForSearch());
    ui->searchButton->setStyleSheet(StyleHandler::getStyleForSearchButton());
    ui->justButton->setStyleSheet(StyleHandler::getStyleForButton());
}

void MainMenu::setAccount(Customer *_customer)
{
    currentCustomer=_customer;
    QList<Ticket> boughtTickets = currentCustomer->getBoughtTickets();
    Ticket testTicket1("test 1",10,1);
    Ticket testTicket2("test 2",20,2);
    Ticket testTicket3("test 3",30,3);

    boughtTickets.push_back(testTicket1);
    boughtTickets.push_back(testTicket2);
    boughtTickets.push_back(testTicket3);


    currentCustomer->setBoughtTickets(boughtTickets);
    for(const auto &ticket : currentCustomer->getBoughtTickets()){
        QListWidgetItem *item = new QListWidgetItem();
        QString ticketRow = testTicket1.getEventName() + " | "
        + QString::number(ticket.getId()) + " | "
        + QString::number(ticket.getTicketPrice());
            item->setData(Qt::DisplayRole, ticketRow);
        ui->listWidget->addItem(ticketRow);
    }
}

MainMenu::~MainMenu()
{
    currentCustomer=nullptr;
    delete ui;
}


void MainMenu::on_searchButton_clicked()
{
    qDebug() << "Click";
}


void MainMenu::on_justButton_clicked()
{
    emit TransitToAuthorization();
}


void MainMenu::on_pushButton_clicked()
{
    if(ui->listWidget->currentItem()){
        QListWidgetItem *item = ui->listWidget->currentItem();
        QStringList ticketRow = item->text().split(" | ");
        QList<Ticket>::Iterator ticketIterator = currentCustomer->findTicket(ticketRow[1].toInt());
        if(currentCustomer->isTicketFound(ticketIterator)){
            currentCustomer->removeTicket(&(*ticketIterator));
            delete ui->listWidget->takeItem(ui->listWidget->row(item));
        }
    }
}

