/********************************************************************************
** Form generated from reading UI file 'editcustomerform.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCUSTOMERFORM_H
#define UI_EDITCUSTOMERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditCustomerForm
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
    QPushButton *editCustomerButton;

    void setupUi(QDialog *EditCustomerForm)
    {
        if (EditCustomerForm->objectName().isEmpty())
            EditCustomerForm->setObjectName("EditCustomerForm");
        EditCustomerForm->resize(400, 300);
        verticalLayout = new QVBoxLayout(EditCustomerForm);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        loginLabel = new QLabel(EditCustomerForm);
        loginLabel->setObjectName("loginLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, loginLabel);

        loginInput = new QLineEdit(EditCustomerForm);
        loginInput->setObjectName("loginInput");

        formLayout->setWidget(0, QFormLayout::FieldRole, loginInput);

        passLabel = new QLabel(EditCustomerForm);
        passLabel->setObjectName("passLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, passLabel);

        passInput = new QLineEdit(EditCustomerForm);
        passInput->setObjectName("passInput");

        formLayout->setWidget(1, QFormLayout::FieldRole, passInput);

        moneyLabel = new QLabel(EditCustomerForm);
        moneyLabel->setObjectName("moneyLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, moneyLabel);

        moneyInput = new QLineEdit(EditCustomerForm);
        moneyInput->setObjectName("moneyInput");

        formLayout->setWidget(2, QFormLayout::FieldRole, moneyInput);


        verticalLayout->addLayout(formLayout);

        editCustomerButton = new QPushButton(EditCustomerForm);
        editCustomerButton->setObjectName("editCustomerButton");

        verticalLayout->addWidget(editCustomerButton);


        retranslateUi(EditCustomerForm);

        QMetaObject::connectSlotsByName(EditCustomerForm);
    } // setupUi

    void retranslateUi(QDialog *EditCustomerForm)
    {
        EditCustomerForm->setWindowTitle(QCoreApplication::translate("EditCustomerForm", "Dialog", nullptr));
        loginLabel->setText(QCoreApplication::translate("EditCustomerForm", "Login:", nullptr));
        passLabel->setText(QCoreApplication::translate("EditCustomerForm", "Password:", nullptr));
        moneyLabel->setText(QCoreApplication::translate("EditCustomerForm", "Money:", nullptr));
        editCustomerButton->setText(QCoreApplication::translate("EditCustomerForm", "Edit Customer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditCustomerForm: public Ui_EditCustomerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCUSTOMERFORM_H
