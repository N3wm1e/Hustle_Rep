#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <StyleHandler.h>
#include <customer.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    void setAccount(Customer*);
    ~MainMenu();

signals:
    void TransitToAuthorization();
private slots:
    void on_searchButton_clicked();

    void on_justButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainMenu *ui;
    Customer* currentCustomer;
};
#endif // MAINMENU_H
