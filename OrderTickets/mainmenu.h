#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <StyleHandler.h>
#include <customer.h>
#include <QListWidgetItem>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    void setAccount(Customer*);
    void testAddEvents();
    void setDefaultMenu();
    void setStyles();
    ~MainMenu();

signals:
    void TransitToAuthorization();
private slots:
    void on_searchButton_clicked();

    void on_justButton_clicked();

    void on_chooseSearch_currentIndexChanged(int index);

    void on_updateBalanceBtn_clicked();

    void on_eventList_itemDoubleClicked(QListWidgetItem *item);

    void on_showAllEventsButton_clicked();

    void on_removeTicketButton_clicked();

    void on_showAllBoughtTickets_clicked();

private:
    Ui::MainMenu *ui;
    Customer* currentCustomer;
    bool searchByDate;
};
#endif // MAINMENU_H
