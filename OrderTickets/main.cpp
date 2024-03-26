#include <QApplication>
#include <authorization.h>
#include <mainmenu.h>
#include <customer.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainMenu mm;
    // mm.show();
   MainMenu mainMenu;
   Authorization auth;
   auth.show();
    QObject::connect(&mainMenu, &MainMenu::TransitToAuthorization, [&](){
       mainMenu.hide();
       auth.show();
   });
   QObject::connect(&auth, &Authorization::TransitToCustomerMenuSignal, [&](){
       auth.hide();
       mainMenu.setAccount(auth.getCurrentCustomer());
       mainMenu.show();
});
    return a.exec();
}
