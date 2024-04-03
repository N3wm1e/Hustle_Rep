/********************************************************************************
** Form generated from reading UI file 'eventdescriptionwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTDESCRIPTIONWINDOW_H
#define UI_EVENTDESCRIPTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_EventDescriptionWindow
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout;
    QLabel *EventName;
    QLabel *Tickets;
    QLabel *labelForTicketsCount;
    QLabel *isFinishedStatus;
    QLabel *labelForStatus;
    QLabel *TicketPrice;
    QLabel *labelForEventName;
    QLabel *labelForTicketPrice;
    QLabel *EventTime;
    QLabel *labelForTime;
    QPushButton *BuyTicketButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *EventDescriptionWindow)
    {
        if (EventDescriptionWindow->objectName().isEmpty())
            EventDescriptionWindow->setObjectName("EventDescriptionWindow");
        EventDescriptionWindow->resize(447, 357);
        gridLayout = new QGridLayout(EventDescriptionWindow);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        EventName = new QLabel(EventDescriptionWindow);
        EventName->setObjectName("EventName");

        formLayout->setWidget(0, QFormLayout::LabelRole, EventName);

        Tickets = new QLabel(EventDescriptionWindow);
        Tickets->setObjectName("Tickets");

        formLayout->setWidget(1, QFormLayout::LabelRole, Tickets);

        labelForTicketsCount = new QLabel(EventDescriptionWindow);
        labelForTicketsCount->setObjectName("labelForTicketsCount");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelForTicketsCount->sizePolicy().hasHeightForWidth());
        labelForTicketsCount->setSizePolicy(sizePolicy);
        labelForTicketsCount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, labelForTicketsCount);

        isFinishedStatus = new QLabel(EventDescriptionWindow);
        isFinishedStatus->setObjectName("isFinishedStatus");

        formLayout->setWidget(2, QFormLayout::LabelRole, isFinishedStatus);

        labelForStatus = new QLabel(EventDescriptionWindow);
        labelForStatus->setObjectName("labelForStatus");
        sizePolicy.setHeightForWidth(labelForStatus->sizePolicy().hasHeightForWidth());
        labelForStatus->setSizePolicy(sizePolicy);
        labelForStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, labelForStatus);

        TicketPrice = new QLabel(EventDescriptionWindow);
        TicketPrice->setObjectName("TicketPrice");

        formLayout->setWidget(3, QFormLayout::LabelRole, TicketPrice);

        labelForEventName = new QLabel(EventDescriptionWindow);
        labelForEventName->setObjectName("labelForEventName");
        sizePolicy.setHeightForWidth(labelForEventName->sizePolicy().hasHeightForWidth());
        labelForEventName->setSizePolicy(sizePolicy);
        labelForEventName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, labelForEventName);

        labelForTicketPrice = new QLabel(EventDescriptionWindow);
        labelForTicketPrice->setObjectName("labelForTicketPrice");
        sizePolicy.setHeightForWidth(labelForTicketPrice->sizePolicy().hasHeightForWidth());
        labelForTicketPrice->setSizePolicy(sizePolicy);
        labelForTicketPrice->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, labelForTicketPrice);

        EventTime = new QLabel(EventDescriptionWindow);
        EventTime->setObjectName("EventTime");

        formLayout->setWidget(4, QFormLayout::LabelRole, EventTime);

        labelForTime = new QLabel(EventDescriptionWindow);
        labelForTime->setObjectName("labelForTime");
        labelForTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, labelForTime);


        gridLayout->addLayout(formLayout, 1, 1, 1, 1);

        BuyTicketButton = new QPushButton(EventDescriptionWindow);
        BuyTicketButton->setObjectName("BuyTicketButton");

        gridLayout->addWidget(BuyTicketButton, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);


        retranslateUi(EventDescriptionWindow);

        QMetaObject::connectSlotsByName(EventDescriptionWindow);
    } // setupUi

    void retranslateUi(QDialog *EventDescriptionWindow)
    {
        EventDescriptionWindow->setWindowTitle(QCoreApplication::translate("EventDescriptionWindow", "Dialog", nullptr));
        EventName->setText(QCoreApplication::translate("EventDescriptionWindow", "Event name", nullptr));
        Tickets->setText(QCoreApplication::translate("EventDescriptionWindow", "Tickets", nullptr));
        labelForTicketsCount->setText(QString());
        isFinishedStatus->setText(QCoreApplication::translate("EventDescriptionWindow", "Event status", nullptr));
        labelForStatus->setText(QString());
        TicketPrice->setText(QCoreApplication::translate("EventDescriptionWindow", "Price", nullptr));
        labelForEventName->setText(QString());
        labelForTicketPrice->setText(QString());
        EventTime->setText(QCoreApplication::translate("EventDescriptionWindow", "Time", nullptr));
        labelForTime->setText(QString());
        BuyTicketButton->setText(QCoreApplication::translate("EventDescriptionWindow", "Buy ticket", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventDescriptionWindow: public Ui_EventDescriptionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTDESCRIPTIONWINDOW_H
