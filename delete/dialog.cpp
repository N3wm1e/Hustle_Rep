#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(Test& _elem,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label->setText(QString::number(_elem.id));
}

Dialog::~Dialog()
{
    delete ui;
}
