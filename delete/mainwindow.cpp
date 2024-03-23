#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    list.push_back(Test("Hello", 1));
    list.push_back(Test("World", 2));
    list.push_back(Test("H", 99));
    list.push_back(Test("O", 4));



    for(const auto& i: list){
        ui->listWidget->addItem(i.name);
    }



    // connect(ui->listWidget, &QListWidget::itemDoubleClicked, [&](QListWidgetItem* item){
    //     qDebug() << item->text();
    // });
    connect(ui->listWidget, &QListWidget::itemDoubleClicked, this, &MainWindow::slotik);

    //connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(slotik(QListWidgetItem*)));
}

Test &MainWindow::getElement(QString str)
{
    for(auto&i:list){
        if(i.name==str)return i;
    }
    throw std::out_of_range("Элемент с именем " + str.toStdString() + " не найден");
}

void MainWindow::slotik(QListWidgetItem* item){
    qDebug() << item->text();
    Dialog dia(getElement(item->text()));
    dia.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
