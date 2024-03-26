#ifndef EVENTDESCRIPTIONWINDOW_H
#define EVENTDESCRIPTIONWINDOW_H

#include <QDialog>
#include "event.h"
namespace Ui {
class EventDescriptionWindow;
}

class EventDescriptionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EventDescriptionWindow(QWidget *parent = nullptr);
    void setEvent(const Event&);
    void displayInfo();
    ~EventDescriptionWindow();

private:
    Event event;
    Ui::EventDescriptionWindow *ui;
};

#endif // EVENTDESCRIPTIONWINDOW_H
