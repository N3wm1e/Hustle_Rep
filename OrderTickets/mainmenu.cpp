#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    QFontDatabase::addApplicationFont(":/img/ProstoOne-Regular.ttf");
    ui->lineEdit->setStyleSheet(StyleHandler::getStyleForSearch());
    ui->searchButton->setStyleSheet(StyleHandler::getStyleForSearchButton());
    ui->justButton->setStyleSheet(StyleHandler::getStyleForJustButton());
}

MainMenu::~MainMenu()
{
    delete ui;
}


void MainMenu::on_searchButton_clicked()
{
    qDebug() << "Your input: " << ui->lineEdit->text();
}

