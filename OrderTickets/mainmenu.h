#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <StyleHandler.h>
#include <QFontDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_searchButton_clicked();

private:
    Ui::MainMenu *ui;
};
#endif // MAINMENU_H
