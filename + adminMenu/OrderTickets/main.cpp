#include <QApplication>
#include <authorization.h>
#include <mainmenu.h>
#include <customer.h>
#include <adminmenu.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu mainMenu;
    mainMenu.testAddEvents();
    Authorization auth;
    auth.show();
    AdminMenu aMenu;
    QObject::connect(&mainMenu, &MainMenu::TransitToAuthorization, [&mainMenu, &auth](){
        mainMenu.hide();
        auth.show();
    });
    QObject::connect(&auth, &Authorization::TransitToCustomerMenuSignal, [&auth, &mainMenu](Customer* _item){
        auth.hide();
        mainMenu.setAccount(_item);
        mainMenu.setDefaultMenu();
        mainMenu.show();
    });
    QObject::connect(&aMenu, &AdminMenu::TransitToAuthorization, [&auth, &aMenu](){
        aMenu.hide();
        auth.show();
    });
    QObject::connect(&auth, &Authorization::TransitToAdminMenuSignal, [&auth, &aMenu](Administrator* _item){
        auth.hide();
        aMenu.setAccount(_item);
        aMenu.show();
    });
    return a.exec();
}
