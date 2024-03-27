#include <QApplication>
#include <authorization.h>
#include <mainmenu.h>
#include <customer.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu mainMenu;
    mainMenu.testAddEvents();
    Authorization auth;
    auth.show();
    QObject::connect(&mainMenu, &MainMenu::TransitToAuthorization, [&](){
        mainMenu.hide();
        auth.show();
    });
    QObject::connect(&auth, &Authorization::TransitToCustomerMenuSignal, [&](Customer* _item){
        auth.hide();
        mainMenu.setAccount(_item);
        mainMenu.setDefaultMenu();
        mainMenu.show();
    });
    return a.exec();
}
