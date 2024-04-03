#ifndef ADDEVENTFORM_H
#define ADDEVENTFORM_H

#include <QDialog>
#include<event.h>
#include<QFormLayout>
#include<QMessageBox>
#include <stylehandler.h>
#include <administrator.h>

namespace Ui {
class AddEventForm;
}

class AddEventForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddEventForm(QWidget *parent = nullptr);
    ~AddEventForm();
    bool isFieldsFilled();
    bool checkFields();
    void setStyles();
    void setAdmin(Administrator*);
private slots:
    void on_addEventBtn_clicked();

private:
    Ui::AddEventForm *ui;
    Administrator* currentAdmin;
};

#endif // ADDEVENTFORM_H
