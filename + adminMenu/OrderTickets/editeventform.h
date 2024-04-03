#ifndef EDITEVENTFORM_H
#define EDITEVENTFORM_H

#include <QDialog>
#include<QMessageBox>
#include"event.h"
#include"administrator.h"
namespace Ui {
class EditEventForm;
}

class EditEventForm : public QDialog
{
    Q_OBJECT

public:
    explicit EditEventForm(QWidget *parent = nullptr);
    bool isFieldsFilled();
    bool checkFields();
    void fillFields();
    void setEventForEdit(Event*);
    bool setAdmin(Administrator*);
    void editEventForm();
    ~EditEventForm();

private slots:
    void on_editEvent_ConfirmBtn_clicked();

private:
    Ui::EditEventForm *ui;
    Event* chosenEvent;
    Administrator* currentAdmin;
};

#endif // EDITEVENTFORM_H
