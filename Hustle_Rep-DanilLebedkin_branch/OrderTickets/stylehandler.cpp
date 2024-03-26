#include "stylehandler.h"

StyleHandler::StyleHandler() {}

QString StyleHandler::getStyleForSearch()
{
    return
    "QLineEdit {"
        "border: 2px solid #00C0A3;"
        "border-radius: 10%;"
        "background-color: #fff;"
        "padding: 5px;"
    "}"
    "QLineEdit:focus {"
        "border-color: #f4cb5a;"
        "background-color: #e4ecf1;"
    "}";
}

QString StyleHandler::getStyleForSearchButton()
{
    return
        "QPushButton{"
           "qproperty-icon: url(:/img/searchIcon.png);"
           "padding: 7.5px;"
           "background-color: #00C0A3;"
           "border: none;"
           "border-radius: 10px;"
        "}"
        "QPushButton:hover{"
           "border: 1px solid #f4cb5a;"
           "background-color: #8bffbb;"
           "}";
}

QString StyleHandler::getStyleForButton()
{
    return
    "QPushButton {"
        "background-color: #00C9A7;"
        "border-radius: 10%;"
        "color: white;"
        "padding: 10px 20px;"
        "font-size: 30px;"
        "font-weight: bold;"
        "text-align: center;"
        "text-decoration: none;"
        "margin: 4px 2px;"
        "font-family: 'Dosis';"
    "}"
    "QPushButton:hover {"
        "background-color: #1E90FF;"
    "}"
    "QPushButton:pressed{"
           "background-color: #DC143C;"
           "}";
}

QString StyleHandler::getStyleForInput()
{
    return
        "QLineEdit {"
            "background-color: #ffffff;"
            "border: 1px solid #cccccc;"
            "border-radius: 5px;"
            "padding: 5px;"
        "}"
        "QLineEdit:focus{"
           "border: 1px solid #845EC2;"
        "}";
}

QString StyleHandler::getStyleForText()
{
    return
        "QLabel {"
           "color: #4B4453;"
           "font-family: 'Dosis';"
           "font-weight: bold;"
           "font-size: 20px;"
           "}";
}

QString StyleHandler::getStyleForList()
{
    return
    "QListWidget {"
        "border: 2px solid #ccc;"
        "border-radius: 5px;"
        "padding: 5px;"
        "background-color: #ffffff;"
        "font-size: 15px;"
    "}"

    "QListWidget::item:hover {"
        "background-color: #00C0A3;"
    "}"

    "QListWidget::item:selected {"
        "background-color: #00C0A3;"
        "color: #ffffff;"
           "}";
}

void StyleHandler::setFonts()
{
    QFontDatabase::addApplicationFont(":/img/Dosis-VariableFont_wght.ttf");
    QFontDatabase::addApplicationFont(":/img/Kanit-Black.ttf");
    QFontDatabase::addApplicationFont(":/img/Kanit-Regular.ttf");
}
