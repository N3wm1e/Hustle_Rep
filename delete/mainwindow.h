#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <test.h>
#include <QListWidgetItem>
#include <dialog.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Test& getElement(QString);
    ~MainWindow();

private slots:
    void slotik(QListWidgetItem*);

private:
    Ui::MainWindow *ui;
    QList<Test> list;
};
#endif // MAINWINDOW_H
