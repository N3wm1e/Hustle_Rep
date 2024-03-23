#include "stylehandler.h"

StyleHandler::StyleHandler() {}

QString StyleHandler::getStyleForSearch()
{
    return
    "QLineEdit {"
        "border: 2px solid #ccc;"
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
           //"image: url(:/img/searchIcon.png);"
           "padding: 7.5px;"
           "background-color: #96e8b8;"
           "border: none;"
           "border-radius: 10px;"
        "}"
        "QPushButton:hover{"
           "border: 1px solid #f4cb5a;"
           "background-color: #8bffbb;"
           "}";
}

QString StyleHandler::getStyleForJustButton()
{
    return
        "QPushButton {"
        "background-color: #00BFFF;"
        "border-radius: 5px;"
        "color: white;"
        "padding: 10px 20px;"
        "font-size: 30px;"
        "font-weight: bold;"
        "text-align: center;"
        "text-decoration: none;"
        "margin: 4px 2px;"
        "font-family: 'Prosto One';"
        "font-weight: 400;"
        "font-style: normal;"
    "}"
"QPushButton:hover {"
        "background-color: #1E90FF;"
    "}"
    "QPushButton:pressed{"
           "background-color: #DC143C;"
           "}";
}
