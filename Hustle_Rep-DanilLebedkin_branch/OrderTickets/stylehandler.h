#ifndef STYLEHANDLER_H
#define STYLEHANDLER_H

#include <QString>
#include <QFontDatabase>

class StyleHandler
{
public:
    StyleHandler();
    static QString getStyleForSearch();
    static QString getStyleForSearchButton();
    static QString getStyleForButton();
    static QString getStyleForInput();
    static QString getStyleForText();
    static QString getStyleForList();
    static void setFonts();
};

#endif // STYLEHANDLER_H
