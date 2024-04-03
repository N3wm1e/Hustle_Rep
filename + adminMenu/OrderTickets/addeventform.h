#ifndef ADDEVENTFORM_H
#define ADDEVENTFORM_H

#include <QDialog>
#include<event.h>
#include<QFormLayout>
#include<QMessageBox>
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
private slots:
    void on_addEventBtn_clicked();

private:
    Ui::AddEventForm *ui;
};

#endif // ADDEVENTFORM_H
