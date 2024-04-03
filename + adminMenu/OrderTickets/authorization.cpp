#include "authorization.h"
#include "ui_authorization.h"

Authorization::Authorization(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Authorization)
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
    QFile file("accounts.txt");
    if(file.open(QIODevice::WriteOnly)){
        QTextStream out(&file);
        for(const auto&i:Administrator::getAdmins()){
            out << "LOGIN: " << i.getLogin() << " PASS: " << i.getPassword() << " ROLE: " << 1 << Qt::endl;
        }
        for(const auto&i:Customer::getCustomers()){
            out << "LOGIN: " << i.getLogin() << " PASS: " << i.getPassword() << " ROLE: " << 0 << " MONEY: " << i.getMoney() << Qt::endl;
        }
        file.close();
    }else{
        qWarning("[AUTHORIZATION]Cannot open file for writing");
    }
    delete ui;
}

void Authorization::Login()
{
    if(ui->loginInput->text()=="" || ui->passInput->text()==""){
        ui->labelInfo->setText("You need to fill all the fields");
        return;
    }
    for(auto&i:Administrator::getAdmins()){
        if(ui->loginInput->text() == i.getLogin() && ui->passInput->text() == i.getPassword()){
            emit TransitToAdminMenuSignal(&i);
            return;
        }
    }
    for(auto &i:Customer::getCustomers()){
        if(ui->loginInput->text() == i.getLogin() && ui->passInput->text() == i.getPassword()){
            emit TransitToCustomerMenuSignal(&i);
            return;
        }
    }
    ui->labelInfo->setText("Incorrect login or password");
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

