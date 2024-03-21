#include "mainmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    w.setWindowTitle("Online Cash Register");
    w.setWindowIcon(QIcon("://img/Icon.png"));
    w.show();
    return a.exec();
}
