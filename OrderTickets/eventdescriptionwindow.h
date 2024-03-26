#ifndef EVENTDESCRIPTIONWINDOW_H
#define EVENTDESCRIPTIONWINDOW_H

#include <QDialog>
#include "event.h"

class Customer;
namespace Ui {
class EventDescriptionWindow;
}

class EventDescriptionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EventDescriptionWindow(QWidget *parent = nullptr);
    void setCustomer(Customer*);
    void setEvent(Event*);
    void displayInfo();
    void displayTicketPrice(Event*);
    int freeTicketsCount(Event*);

    ~EventDescriptionWindow();

private slots:
    void on_BuyTicketButton_clicked();

private:
    Event* event;
    Customer* customer;
    Ui::EventDescriptionWindow *ui;
};

#endif // EVENTDESCRIPTIONWINDOW_H
