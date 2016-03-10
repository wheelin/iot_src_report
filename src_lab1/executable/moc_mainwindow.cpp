/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QTWorkspace/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 12),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 8),
QT_MOC_LITERAL(4, 34, 14),
QT_MOC_LITERAL(5, 49, 5),
QT_MOC_LITERAL(6, 55, 16),
QT_MOC_LITERAL(7, 72, 19),
QT_MOC_LITERAL(8, 92, 16),
QT_MOC_LITERAL(9, 109, 14),
QT_MOC_LITERAL(10, 124, 22),
QT_MOC_LITERAL(11, 147, 25),
QT_MOC_LITERAL(12, 173, 12),
QT_MOC_LITERAL(13, 186, 13),
QT_MOC_LITERAL(14, 200, 16),
QT_MOC_LITERAL(15, 217, 14),
QT_MOC_LITERAL(16, 232, 17),
QT_MOC_LITERAL(17, 250, 10)
    },
    "MainWindow\0startMeasure\0\0onResult\0"
    "QNetworkReply*\0reply\0onAddNodesResult\0"
    "onRemoveNodesResult\0onGetNodesResult\0"
    "onGetAllResult\0handleSingleMeasButton\0"
    "handleAutomaticMeasButton\0handleGetAll\0"
    "handleAddNode\0handleRemoveNode\0"
    "handleGetNodes\0handleMakeMeasure\0"
    "timerNotif\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   85,    2, 0x08,
       6,    1,   88,    2, 0x08,
       7,    1,   91,    2, 0x08,
       8,    1,   94,    2, 0x08,
       9,    1,   97,    2, 0x08,
      10,    0,  100,    2, 0x08,
      11,    0,  101,    2, 0x08,
      12,    0,  102,    2, 0x08,
      13,    0,  103,    2, 0x08,
      14,    0,  104,    2, 0x08,
      15,    0,  105,    2, 0x08,
      16,    0,  106,    2, 0x08,
      17,    0,  107,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->startMeasure(); break;
        case 1: _t->onResult((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->onAddNodesResult((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->onRemoveNodesResult((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->onGetNodesResult((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->onGetAllResult((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->handleSingleMeasButton(); break;
        case 7: _t->handleAutomaticMeasButton(); break;
        case 8: _t->handleGetAll(); break;
        case 9: _t->handleAddNode(); break;
        case 10: _t->handleRemoveNode(); break;
        case 11: _t->handleGetNodes(); break;
        case 12: _t->handleMakeMeasure(); break;
        case 13: _t->timerNotif(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::startMeasure)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::startMeasure()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
