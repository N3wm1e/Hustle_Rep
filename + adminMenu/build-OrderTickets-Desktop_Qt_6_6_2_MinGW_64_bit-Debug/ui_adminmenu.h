/********************************************************************************
** Form generated from reading UI file 'adminmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMENU_H
#define UI_ADMINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminMenu
{
public:
    QPushButton *logOutButton;
    QPushButton *addCustomerButton;
    QPushButton *editCustomerButton;
    QListWidget *accountsList;
    QPushButton *showAllAccountsBtn;
    QListWidget *eventsList;
    QPushButton *showAllEventsBtn;
    QPushButton *editEventBtn;
    QPushButton *addEventBtn;
    QPushButton *deleteEventBtn;

    void setupUi(QWidget *AdminMenu)
    {
        if (AdminMenu->objectName().isEmpty())
            AdminMenu->setObjectName("AdminMenu");
        AdminMenu->resize(722, 591);
        logOutButton = new QPushButton(AdminMenu);
        logOutButton->setObjectName("logOutButton");
        logOutButton->setGeometry(QRect(70, 130, 80, 24));
        addCustomerButton = new QPushButton(AdminMenu);
        addCustomerButton->setObjectName("addCustomerButton");
        addCustomerButton->setGeometry(QRect(290, 120, 80, 24));
        editCustomerButton = new QPushButton(AdminMenu);
        editCustomerButton->setObjectName("editCustomerButton");
        editCustomerButton->setGeometry(QRect(480, 540, 80, 24));
        accountsList = new QListWidget(AdminMenu);
        accountsList->setObjectName("accountsList");
        accountsList->setGeometry(QRect(390, 350, 256, 192));
        showAllAccountsBtn = new QPushButton(AdminMenu);
        showAllAccountsBtn->setObjectName("showAllAccountsBtn");
        showAllAccountsBtn->setGeometry(QRect(460, 320, 131, 31));
        eventsList = new QListWidget(AdminMenu);
        eventsList->setObjectName("eventsList");
        eventsList->setGeometry(QRect(100, 350, 256, 192));
        showAllEventsBtn = new QPushButton(AdminMenu);
        showAllEventsBtn->setObjectName("showAllEventsBtn");
        showAllEventsBtn->setGeometry(QRect(170, 320, 131, 31));
        editEventBtn = new QPushButton(AdminMenu);
        editEventBtn->setObjectName("editEventBtn");
        editEventBtn->setGeometry(QRect(190, 540, 80, 24));
        addEventBtn = new QPushButton(AdminMenu);
        addEventBtn->setObjectName("addEventBtn");
        addEventBtn->setGeometry(QRect(110, 540, 80, 24));
        deleteEventBtn = new QPushButton(AdminMenu);
        deleteEventBtn->setObjectName("deleteEventBtn");
        deleteEventBtn->setGeometry(QRect(270, 540, 80, 24));

        retranslateUi(AdminMenu);

        QMetaObject::connectSlotsByName(AdminMenu);
    } // setupUi

    void retranslateUi(QWidget *AdminMenu)
    {
        AdminMenu->setWindowTitle(QCoreApplication::translate("AdminMenu", "Form", nullptr));
        logOutButton->setText(QCoreApplication::translate("AdminMenu", "Log Out", nullptr));
        addCustomerButton->setText(QCoreApplication::translate("AdminMenu", "Add Customer", nullptr));
        editCustomerButton->setText(QCoreApplication::translate("AdminMenu", "Edit Customer", nullptr));
        showAllAccountsBtn->setText(QCoreApplication::translate("AdminMenu", "Show All Accounts", nullptr));
        showAllEventsBtn->setText(QCoreApplication::translate("AdminMenu", "Show All Events", nullptr));
        editEventBtn->setText(QCoreApplication::translate("AdminMenu", "Edit Event", nullptr));
        addEventBtn->setText(QCoreApplication::translate("AdminMenu", "Add Event", nullptr));
        deleteEventBtn->setText(QCoreApplication::translate("AdminMenu", "Delete Event", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminMenu: public Ui_AdminMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMENU_H
