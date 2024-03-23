#ifndef STYLEHANDLER_H
#define STYLEHANDLER_H

#include <QString>

class StyleHandler
{
public:
    StyleHandler();
    static QString getStyleForSearch();
    static QString getStyleForSearchButton();
    static QString getStyleForJustButton();
};

#endif // STYLEHANDLER_H
