/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/header-files/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainwindow_t {
    const uint offsetsAndSize[44];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_mainwindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_mainwindow_t qt_meta_stringdata_mainwindow = {
    {
QT_MOC_LITERAL(0, 10), // "mainwindow"
QT_MOC_LITERAL(11, 11), // "newDocument"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 4), // "open"
QT_MOC_LITERAL(29, 4), // "save"
QT_MOC_LITERAL(34, 6), // "saveAs"
QT_MOC_LITERAL(41, 10), // "selectFont"
QT_MOC_LITERAL(52, 16), // "setFontUnderLine"
QT_MOC_LITERAL(69, 9), // "underline"
QT_MOC_LITERAL(79, 13), // "setFontItalic"
QT_MOC_LITERAL(93, 6), // "italic"
QT_MOC_LITERAL(100, 11), // "setFontBold"
QT_MOC_LITERAL(112, 4), // "bold"
QT_MOC_LITERAL(117, 5), // "about"
QT_MOC_LITERAL(123, 10), // "closeEvent"
QT_MOC_LITERAL(134, 12), // "QCloseEvent*"
QT_MOC_LITERAL(147, 5), // "event"
QT_MOC_LITERAL(153, 9), // "cursorLoc"
QT_MOC_LITERAL(163, 8), // "notSaved"
QT_MOC_LITERAL(172, 4), // "exit"
QT_MOC_LITERAL(177, 8), // "findFunc"
QT_MOC_LITERAL(186, 11) // "replaceFunc"

    },
    "mainwindow\0newDocument\0\0open\0save\0"
    "saveAs\0selectFont\0setFontUnderLine\0"
    "underline\0setFontItalic\0italic\0"
    "setFontBold\0bold\0about\0closeEvent\0"
    "QCloseEvent*\0event\0cursorLoc\0notSaved\0"
    "exit\0findFunc\0replaceFunc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainwindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x08,    1 /* Private */,
       3,    0,  105,    2, 0x08,    2 /* Private */,
       4,    0,  106,    2, 0x08,    3 /* Private */,
       5,    0,  107,    2, 0x08,    4 /* Private */,
       6,    0,  108,    2, 0x08,    5 /* Private */,
       7,    1,  109,    2, 0x08,    6 /* Private */,
       9,    1,  112,    2, 0x08,    8 /* Private */,
      11,    1,  115,    2, 0x08,   10 /* Private */,
      13,    0,  118,    2, 0x08,   12 /* Private */,
      14,    1,  119,    2, 0x08,   13 /* Private */,
      17,    0,  122,    2, 0x08,   15 /* Private */,
      18,    0,  123,    2, 0x08,   16 /* Private */,
      19,    0,  124,    2, 0x08,   17 /* Private */,
      20,    0,  125,    2, 0x08,   18 /* Private */,
      21,    0,  126,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newDocument(); break;
        case 1: _t->open(); break;
        case 2: _t->save(); break;
        case 3: _t->saveAs(); break;
        case 4: _t->selectFont(); break;
        case 5: _t->setFontUnderLine((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->setFontItalic((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->setFontBold((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->about(); break;
        case 9: _t->closeEvent((*reinterpret_cast< std::add_pointer_t<QCloseEvent*>>(_a[1]))); break;
        case 10: _t->cursorLoc(); break;
        case 11: _t->notSaved(); break;
        case 12: _t->exit(); break;
        case 13: _t->findFunc(); break;
        case 14: _t->replaceFunc(); break;
        default: ;
        }
    }
}

const QMetaObject mainwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_mainwindow.offsetsAndSize,
    qt_meta_data_mainwindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_mainwindow_t
, QtPrivate::TypeAndForceComplete<mainwindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *mainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainwindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
