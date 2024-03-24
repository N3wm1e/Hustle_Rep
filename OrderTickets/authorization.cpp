#include "authorization.h"
#include "ui_authorization.h"

Authorization::Authorization(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Authorization)
    , currentCustomer(nullptr)
{
    ui->setupUi(this);
    this->setWindowTitle("Online Cash Register");
    this->setWindowIcon(QIcon("://img/Icon.png"));
    ui->passInput->setEchoMode(QLineEdit::Password); //Точки замість паролю
    readAllAccounts(); //Зчитати дані з текстового файлу у масиви адміна та покупця
    setStyles(); //Установка стилів
    connect(ui->loginButton, &QPushButton::clicked, this, &Authorization::Login);

}



void Authorization::readAllAccounts()
{
    const int indexLogin = 1;
    const int indexPass = 3;
    const int indexRole = 5;
    const int indexMoney = 7;
    QFile file("accounts.txt");
    if(!file.open(QIODevice::ReadOnly)){
        qWarning("[AUTHORIZATION]Cannot open file for reading");
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QList<QString> data = in.readLine().split(" ", Qt::SkipEmptyParts);
        if(data[indexRole].toInt()){
            Administrator::getAdmins().push_back(Administrator(data[indexLogin],data[indexPass]));
        }else{
            Customer::getCustomers().push_back(Customer(data[indexLogin],data[indexPass], data[indexMoney].toInt()));
        }
    }
    file.close();
}

Authorization::~Authorization()
{
    currentCustomer=nullptr;
    delete ui;
}

void Authorization::Login()
{
    if(ui->loginInput->text()=="" || ui->passInput->text()==""){
        ui->labelInfo->setText("You need to fill all the fields");
        return;
    }
    for(const auto&i:Administrator::getAdmins()){
        if(ui->loginInput->text() == i.getLogin() && ui->passInput->text() == i.getPassword()){
            qDebug() << "Переход на админ-меню";
            return;
        }
    }
    for(auto &i:Customer::getCustomers()){
        if(ui->loginInput->text() == i.getLogin() && ui->passInput->text() == i.getPassword()){
            currentCustomer=&i;
            emit TransitToCustomerMenuSignal();
            return;
        }
    }
    ui->labelInfo->setText("Incorrect login or password");
}

Customer* Authorization::getCurrentCustomer()
{
    return currentCustomer;
}

void Authorization::setCurrentCustomer(Customer *_currentCustomer)
{
    currentCustomer = _currentCustomer;
}

void Authorization::setStyles()
{
    ui->loginInput->setStyleSheet(StyleHandler::getStyleForInput());
    ui->passInput->setStyleSheet(StyleHandler::getStyleForInput());
    ui->loginLabel->setStyleSheet(StyleHandler::getStyleForText());
    ui->passLabel->setStyleSheet(StyleHandler::getStyleForText());
    ui->labelInfo->setStyleSheet(StyleHandler::getStyleForText());
    ui->loginButton->setStyleSheet(StyleHandler::getStyleForButton());
}

