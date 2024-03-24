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

