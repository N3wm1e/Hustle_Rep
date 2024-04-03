/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QDateEdit *searchDate;
    QLabel *balanceLabel;
    QPushButton *removeTicketButton;
    QPushButton *updateBalanceBtn;
    QListWidget *ticketsList;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *justButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *searchButton;
    QLineEdit *searchInput;
    QComboBox *chooseSearch;
    QListWidget *eventList;
    QPushButton *showAllEventsButton;
    QPushButton *showAllBoughtTickets;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(924, 660);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 2, 1, 1);

        searchDate = new QDateEdit(centralwidget);
        searchDate->setObjectName("searchDate");

        gridLayout->addWidget(searchDate, 3, 1, 1, 1);

        balanceLabel = new QLabel(centralwidget);
        balanceLabel->setObjectName("balanceLabel");
        balanceLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(balanceLabel, 0, 2, 1, 1);

        removeTicketButton = new QPushButton(centralwidget);
        removeTicketButton->setObjectName("removeTicketButton");

        gridLayout->addWidget(removeTicketButton, 7, 0, 1, 1);

        updateBalanceBtn = new QPushButton(centralwidget);
        updateBalanceBtn->setObjectName("updateBalanceBtn");

        gridLayout->addWidget(updateBalanceBtn, 1, 2, 1, 1);

        ticketsList = new QListWidget(centralwidget);
        ticketsList->setObjectName("ticketsList");

        gridLayout->addWidget(ticketsList, 6, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        justButton = new QPushButton(centralwidget);
        justButton->setObjectName("justButton");

        gridLayout->addWidget(justButton, 7, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
        searchButton->setSizePolicy(sizePolicy);
        searchButton->setMinimumSize(QSize(36, 24));

        horizontalLayout->addWidget(searchButton);

        searchInput = new QLineEdit(centralwidget);
        searchInput->setObjectName("searchInput");
        searchInput->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(searchInput->sizePolicy().hasHeightForWidth());
        searchInput->setSizePolicy(sizePolicy1);
        searchInput->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(searchInput);

        chooseSearch = new QComboBox(centralwidget);
        chooseSearch->addItem(QString());
        chooseSearch->addItem(QString());
        chooseSearch->setObjectName("chooseSearch");

        horizontalLayout->addWidget(chooseSearch);


        verticalLayout->addLayout(horizontalLayout);

        eventList = new QListWidget(centralwidget);
        eventList->setObjectName("eventList");

        verticalLayout->addWidget(eventList);

        showAllEventsButton = new QPushButton(centralwidget);
        showAllEventsButton->setObjectName("showAllEventsButton");

        verticalLayout->addWidget(showAllEventsButton);


        gridLayout->addLayout(verticalLayout, 4, 1, 1, 1);

        showAllBoughtTickets = new QPushButton(centralwidget);
        showAllBoughtTickets->setObjectName("showAllBoughtTickets");

        gridLayout->addWidget(showAllBoughtTickets, 5, 0, 1, 1);

        MainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 924, 21));
        MainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName("statusbar");
        MainMenu->setStatusBar(statusbar);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "MainMenu", nullptr));
        balanceLabel->setText(QCoreApplication::translate("MainMenu", "TextLabel", nullptr));
        removeTicketButton->setText(QCoreApplication::translate("MainMenu", "Remove Ticket", nullptr));
        updateBalanceBtn->setText(QCoreApplication::translate("MainMenu", "Update Balance", nullptr));
        justButton->setText(QCoreApplication::translate("MainMenu", "Log out", nullptr));
        searchButton->setText(QString());
        chooseSearch->setItemText(0, QCoreApplication::translate("MainMenu", "\320\237\320\276 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\216", nullptr));
        chooseSearch->setItemText(1, QCoreApplication::translate("MainMenu", "\320\237\320\276 \320\264\320\260\321\202\320\265", nullptr));

        showAllEventsButton->setText(QCoreApplication::translate("MainMenu", "Show all events", nullptr));
        showAllBoughtTickets->setText(QCoreApplication::translate("MainMenu", "Show all bought tickets", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
