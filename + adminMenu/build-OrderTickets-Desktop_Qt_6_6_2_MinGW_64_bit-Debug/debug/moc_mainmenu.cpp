/****************************************************************************
** Meta object code from reading C++ file 'mainmenu.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OrderTickets/mainmenu.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainMenuENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainMenuENDCLASS = QtMocHelpers::stringData(
    "MainMenu",
    "TransitToAuthorization",
    "",
    "on_searchButton_clicked",
    "on_justButton_clicked",
    "on_chooseSearch_currentIndexChanged",
    "index",
    "on_updateBalanceBtn_clicked",
    "on_eventList_itemDoubleClicked",
    "QListWidgetItem*",
    "item",
    "on_showAllEventsButton_clicked",
    "on_removeTicketButton_clicked",
    "on_showAllBoughtTickets_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainMenuENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[9];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[24];
    char stringdata4[22];
    char stringdata5[36];
    char stringdata6[6];
    char stringdata7[28];
    char stringdata8[31];
    char stringdata9[17];
    char stringdata10[5];
    char stringdata11[31];
    char stringdata12[30];
    char stringdata13[32];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainMenuENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainMenuENDCLASS_t qt_meta_stringdata_CLASSMainMenuENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "MainMenu"
        QT_MOC_LITERAL(9, 22),  // "TransitToAuthorization"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 23),  // "on_searchButton_clicked"
        QT_MOC_LITERAL(57, 21),  // "on_justButton_clicked"
        QT_MOC_LITERAL(79, 35),  // "on_chooseSearch_currentIndexC..."
        QT_MOC_LITERAL(115, 5),  // "index"
        QT_MOC_LITERAL(121, 27),  // "on_updateBalanceBtn_clicked"
        QT_MOC_LITERAL(149, 30),  // "on_eventList_itemDoubleClicked"
        QT_MOC_LITERAL(180, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(197, 4),  // "item"
        QT_MOC_LITERAL(202, 30),  // "on_showAllEventsButton_clicked"
        QT_MOC_LITERAL(233, 29),  // "on_removeTicketButton_clicked"
        QT_MOC_LITERAL(263, 31)   // "on_showAllBoughtTickets_clicked"
    },
    "MainMenu",
    "TransitToAuthorization",
    "",
    "on_searchButton_clicked",
    "on_justButton_clicked",
    "on_chooseSearch_currentIndexChanged",
    "index",
    "on_updateBalanceBtn_clicked",
    "on_eventList_itemDoubleClicked",
    "QListWidgetItem*",
    "item",
    "on_showAllEventsButton_clicked",
    "on_removeTicketButton_clicked",
    "on_showAllBoughtTickets_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainMenuENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    1,   71,    2, 0x08,    4 /* Private */,
       7,    0,   74,    2, 0x08,    6 /* Private */,
       8,    1,   75,    2, 0x08,    7 /* Private */,
      11,    0,   78,    2, 0x08,    9 /* Private */,
      12,    0,   79,    2, 0x08,   10 /* Private */,
      13,    0,   80,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainMenuENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainMenuENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainMenuENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainMenu, std::true_type>,
        // method 'TransitToAuthorization'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_searchButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_justButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_chooseSearch_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_updateBalanceBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_eventList_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_showAllEventsButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_removeTicketButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_showAllBoughtTickets_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->TransitToAuthorization(); break;
        case 1: _t->on_searchButton_clicked(); break;
        case 2: _t->on_justButton_clicked(); break;
        case 3: _t->on_chooseSearch_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_updateBalanceBtn_clicked(); break;
        case 5: _t->on_eventList_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 6: _t->on_showAllEventsButton_clicked(); break;
        case 7: _t->on_removeTicketButton_clicked(); break;
        case 8: _t->on_showAllBoughtTickets_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainMenu::*)();
            if (_t _q_method = &MainMenu::TransitToAuthorization; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainMenuENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MainMenu::TransitToAuthorization()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
