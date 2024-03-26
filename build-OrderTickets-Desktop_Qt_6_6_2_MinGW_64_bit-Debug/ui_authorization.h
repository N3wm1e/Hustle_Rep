/********************************************************************************
** Form generated from reading UI file 'authorization.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATION_H
#define UI_AUTHORIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Authorization
{
public:
    QGridLayout *gridLayout;
    QPushButton *loginButton;
    QLabel *labelInfo;
    QFormLayout *formLayout;
    QLabel *loginLabel;
    QLineEdit *loginInput;
    QLabel *passLabel;
    QLineEdit *passInput;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Authorization)
    {
        if (Authorization->objectName().isEmpty())
            Authorization->setObjectName("Authorization");
        Authorization->resize(997, 673);
        gridLayout = new QGridLayout(Authorization);
        gridLayout->setObjectName("gridLayout");
        loginButton = new QPushButton(Authorization);
        loginButton->setObjectName("loginButton");

        gridLayout->addWidget(loginButton, 3, 1, 1, 1);

        labelInfo = new QLabel(Authorization);
        labelInfo->setObjectName("labelInfo");
        labelInfo->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelInfo, 1, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        loginLabel = new QLabel(Authorization);
        loginLabel->setObjectName("loginLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, loginLabel);

        loginInput = new QLineEdit(Authorization);
        loginInput->setObjectName("loginInput");

        formLayout->setWidget(0, QFormLayout::FieldRole, loginInput);

        passLabel = new QLabel(Authorization);
        passLabel->setObjectName("passLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, passLabel);

        passInput = new QLineEdit(Authorization);
        passInput->setObjectName("passInput");

        formLayout->setWidget(1, QFormLayout::FieldRole, passInput);


        gridLayout->addLayout(formLayout, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);


        retranslateUi(Authorization);

        QMetaObject::connectSlotsByName(Authorization);
    } // setupUi

    void retranslateUi(QDialog *Authorization)
    {
        Authorization->setWindowTitle(QCoreApplication::translate("Authorization", "Dialog", nullptr));
        loginButton->setText(QCoreApplication::translate("Authorization", "WConfirm", nullptr));
        labelInfo->setText(QCoreApplication::translate("Authorization", "Enter your login and password", nullptr));
        loginLabel->setText(QCoreApplication::translate("Authorization", "Login:", nullptr));
        passLabel->setText(QCoreApplication::translate("Authorization", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Authorization: public Ui_Authorization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATION_H
