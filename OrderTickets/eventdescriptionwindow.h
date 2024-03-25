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
    explicit EventDescriptionWindow(Event _event,QWidget *parent = nullptr);
    ~EventDescriptionWindow();

private:
    Event event;
    Ui::EventDescriptionWindow *ui;
};

#endif // EVENTDESCRIPTIONWINDOW_H
