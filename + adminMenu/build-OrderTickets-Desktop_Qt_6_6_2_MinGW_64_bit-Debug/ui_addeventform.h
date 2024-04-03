/********************************************************************************
** Form generated from reading UI file 'addeventform.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEVENTFORM_H
#define UI_ADDEVENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddEventForm
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *eventNameLabel;
    QLabel *eventTimeLabel;
    QLineEdit *eventNameEdit;
    QDateTimeEdit *eventTimeEdit;
    QLabel *eventTicketPriceLabel;
    QLineEdit *eventTicketPriceEdit;
    QLabel *eventTicketAmountLabel;
    QLineEdit *eventTicketAmountEdit;
    QPushButton *addEventBtn;

    void setupUi(QDialog *AddEventForm)
    {
        if (AddEventForm->objectName().isEmpty())
            AddEventForm->setObjectName("AddEventForm");
        AddEventForm->resize(300, 250);
        AddEventForm->setMinimumSize(QSize(300, 250));
        formLayoutWidget = new QWidget(AddEventForm);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 281, 201));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        eventNameLabel = new QLabel(formLayoutWidget);
        eventNameLabel->setObjectName("eventNameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, eventNameLabel);

        eventTimeLabel = new QLabel(formLayoutWidget);
        eventTimeLabel->setObjectName("eventTimeLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, eventTimeLabel);

        eventNameEdit = new QLineEdit(formLayoutWidget);
        eventNameEdit->setObjectName("eventNameEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, eventNameEdit);

        eventTimeEdit = new QDateTimeEdit(formLayoutWidget);
        eventTimeEdit->setObjectName("eventTimeEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, eventTimeEdit);

        eventTicketPriceLabel = new QLabel(formLayoutWidget);
        eventTicketPriceLabel->setObjectName("eventTicketPriceLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, eventTicketPriceLabel);

        eventTicketPriceEdit = new QLineEdit(formLayoutWidget);
        eventTicketPriceEdit->setObjectName("eventTicketPriceEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, eventTicketPriceEdit);

        eventTicketAmountLabel = new QLabel(formLayoutWidget);
        eventTicketAmountLabel->setObjectName("eventTicketAmountLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, eventTicketAmountLabel);

        eventTicketAmountEdit = new QLineEdit(formLayoutWidget);
        eventTicketAmountEdit->setObjectName("eventTicketAmountEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, eventTicketAmountEdit);

        addEventBtn = new QPushButton(AddEventForm);
        addEventBtn->setObjectName("addEventBtn");
        addEventBtn->setGeometry(QRect(190, 220, 101, 24));

        retranslateUi(AddEventForm);

        QMetaObject::connectSlotsByName(AddEventForm);
    } // setupUi

    void retranslateUi(QDialog *AddEventForm)
    {
        AddEventForm->setWindowTitle(QCoreApplication::translate("AddEventForm", "Dialog", nullptr));
        eventNameLabel->setText(QCoreApplication::translate("AddEventForm", "Event Name:", nullptr));
        eventTimeLabel->setText(QCoreApplication::translate("AddEventForm", "Event Time:", nullptr));
        eventTicketPriceLabel->setText(QCoreApplication::translate("AddEventForm", "Ticket Price:", nullptr));
        eventTicketAmountLabel->setText(QCoreApplication::translate("AddEventForm", "Ticket Amount:", nullptr));
        addEventBtn->setText(QCoreApplication::translate("AddEventForm", "Add Event", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEventForm: public Ui_AddEventForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEVENTFORM_H
