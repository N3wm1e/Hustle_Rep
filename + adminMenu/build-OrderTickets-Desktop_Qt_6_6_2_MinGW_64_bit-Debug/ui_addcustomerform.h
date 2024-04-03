/********************************************************************************
** Form generated from reading UI file 'addcustomerform.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCUSTOMERFORM_H
#define UI_ADDCUSTOMERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddCustomerForm
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *loginLabel;
    QLineEdit *loginInput;
    QLabel *passLabel;
    QLineEdit *passInput;
    QLabel *moneyLabel;
    QLineEdit *moneyInput;
    QPushButton *addCustomerButton;

    void setupUi(QDialog *AddCustomerForm)
    {
        if (AddCustomerForm->objectName().isEmpty())
            AddCustomerForm->setObjectName("AddCustomerForm");
        AddCustomerForm->resize(400, 300);
        verticalLayout = new QVBoxLayout(AddCustomerForm);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        loginLabel = new QLabel(AddCustomerForm);
        loginLabel->setObjectName("loginLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, loginLabel);

        loginInput = new QLineEdit(AddCustomerForm);
        loginInput->setObjectName("loginInput");

        formLayout->setWidget(0, QFormLayout::FieldRole, loginInput);

        passLabel = new QLabel(AddCustomerForm);
        passLabel->setObjectName("passLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, passLabel);

        passInput = new QLineEdit(AddCustomerForm);
        passInput->setObjectName("passInput");

        formLayout->setWidget(1, QFormLayout::FieldRole, passInput);

        moneyLabel = new QLabel(AddCustomerForm);
        moneyLabel->setObjectName("moneyLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, moneyLabel);

        moneyInput = new QLineEdit(AddCustomerForm);
        moneyInput->setObjectName("moneyInput");

        formLayout->setWidget(2, QFormLayout::FieldRole, moneyInput);


        verticalLayout->addLayout(formLayout);

        addCustomerButton = new QPushButton(AddCustomerForm);
        addCustomerButton->setObjectName("addCustomerButton");

        verticalLayout->addWidget(addCustomerButton);


        retranslateUi(AddCustomerForm);

        QMetaObject::connectSlotsByName(AddCustomerForm);
    } // setupUi

    void retranslateUi(QDialog *AddCustomerForm)
    {
        AddCustomerForm->setWindowTitle(QCoreApplication::translate("AddCustomerForm", "Dialog", nullptr));
        loginLabel->setText(QCoreApplication::translate("AddCustomerForm", "Login:", nullptr));
        passLabel->setText(QCoreApplication::translate("AddCustomerForm", "Password:", nullptr));
        moneyLabel->setText(QCoreApplication::translate("AddCustomerForm", "Money:", nullptr));
        addCustomerButton->setText(QCoreApplication::translate("AddCustomerForm", "Add Customer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCustomerForm: public Ui_AddCustomerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCUSTOMERFORM_H
