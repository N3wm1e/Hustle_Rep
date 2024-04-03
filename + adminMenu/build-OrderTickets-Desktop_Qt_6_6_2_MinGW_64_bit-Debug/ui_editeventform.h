/********************************************************************************
** Form generated from reading UI file 'editeventform.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITEVENTFORM_H
#define UI_EDITEVENTFORM_H

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

class Ui_EditEventForm
{
public:
    QPushButton *editEvent_ConfirmBtn;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *editEvent_NameLabel;
    QLabel *editEvent_TimeLabel;
    QLineEdit *editEvent_NameEdit;
    QDateTimeEdit *editEvent_TimeEdit;
    QLabel *editEvent_TicketPriceLabel;
    QLineEdit *editEvent_TicketPriceEdit;
    QLabel *editEvent_TicketAmountLabel;
    QLineEdit *editEvent_TicketAmountEdit;

    void setupUi(QDialog *EditEventForm)
    {
        if (EditEventForm->objectName().isEmpty())
            EditEventForm->setObjectName("EditEventForm");
        EditEventForm->resize(400, 300);
        editEvent_ConfirmBtn = new QPushButton(EditEventForm);
        editEvent_ConfirmBtn->setObjectName("editEvent_ConfirmBtn");
        editEvent_ConfirmBtn->setGeometry(QRect(290, 260, 101, 24));
        formLayoutWidget = new QWidget(EditEventForm);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 381, 241));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        editEvent_NameLabel = new QLabel(formLayoutWidget);
        editEvent_NameLabel->setObjectName("editEvent_NameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, editEvent_NameLabel);

        editEvent_TimeLabel = new QLabel(formLayoutWidget);
        editEvent_TimeLabel->setObjectName("editEvent_TimeLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, editEvent_TimeLabel);

        editEvent_NameEdit = new QLineEdit(formLayoutWidget);
        editEvent_NameEdit->setObjectName("editEvent_NameEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, editEvent_NameEdit);

        editEvent_TimeEdit = new QDateTimeEdit(formLayoutWidget);
        editEvent_TimeEdit->setObjectName("editEvent_TimeEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, editEvent_TimeEdit);

        editEvent_TicketPriceLabel = new QLabel(formLayoutWidget);
        editEvent_TicketPriceLabel->setObjectName("editEvent_TicketPriceLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, editEvent_TicketPriceLabel);

        editEvent_TicketPriceEdit = new QLineEdit(formLayoutWidget);
        editEvent_TicketPriceEdit->setObjectName("editEvent_TicketPriceEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, editEvent_TicketPriceEdit);

        editEvent_TicketAmountLabel = new QLabel(formLayoutWidget);
        editEvent_TicketAmountLabel->setObjectName("editEvent_TicketAmountLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, editEvent_TicketAmountLabel);

        editEvent_TicketAmountEdit = new QLineEdit(formLayoutWidget);
        editEvent_TicketAmountEdit->setObjectName("editEvent_TicketAmountEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, editEvent_TicketAmountEdit);


        retranslateUi(EditEventForm);

        QMetaObject::connectSlotsByName(EditEventForm);
    } // setupUi

    void retranslateUi(QDialog *EditEventForm)
    {
        EditEventForm->setWindowTitle(QCoreApplication::translate("EditEventForm", "Dialog", nullptr));
        editEvent_ConfirmBtn->setText(QCoreApplication::translate("EditEventForm", "Edit event", nullptr));
        editEvent_NameLabel->setText(QCoreApplication::translate("EditEventForm", "Event Name:", nullptr));
        editEvent_TimeLabel->setText(QCoreApplication::translate("EditEventForm", "Event Time:", nullptr));
        editEvent_TicketPriceLabel->setText(QCoreApplication::translate("EditEventForm", "Ticket Price:", nullptr));
        editEvent_TicketAmountLabel->setText(QCoreApplication::translate("EditEventForm", "Ticket Amount:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditEventForm: public Ui_EditEventForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITEVENTFORM_H
