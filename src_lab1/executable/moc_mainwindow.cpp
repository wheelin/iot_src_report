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
    QByteArrayData data[22];
    char stringdata[324];
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
QT_MOC_LITERAL(10, 124, 16),
QT_MOC_LITERAL(11, 141, 15),
QT_MOC_LITERAL(12, 157, 22),
QT_MOC_LITERAL(13, 180, 25),
QT_MOC_LITERAL(14, 206, 12),
QT_MOC_LITERAL(15, 219, 13),
QT_MOC_LITERAL(16, 233, 16),
QT_MOC_LITERAL(17, 250, 14),
QT_MOC_LITERAL(18, 265, 13),
QT_MOC_LITERAL(19, 279, 14),
QT_MOC_LITERAL(20, 294, 17),
QT_MOC_LITERAL(21, 312, 10)
    },
    "MainWindow\0startMeasure\0\0onResult\0"
    "QNetworkReply*\0reply\0onAddNodesResult\0"
    "onRemoveNodesResult\0onGetNodesResult\0"
    "onGetAllResult\0onStartNetResult\0"
    "onStopNetResult\0handleSingleMeasButton\0"
    "handleAutomaticMeasButton\0handleGetAll\0"
    "handleAddNode\0handleRemoveNode\0"
    "handleStartNet\0handleStopNet\0"
    "handleGetNodes\0handleMakeMeasure\0"
    "timerNotif\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,  105,    2, 0x08,
       6,    1,  108,    2, 0x08,
       7,    1,  111,    2, 0x08,
       8,    1,  114,    2, 0x08,
       9,    1,  117,    2, 0x08,
      10,    1,  120,    2, 0x08,
      11,    1,  123,    2, 0x08,
      12,    0,  126,    2, 0x08,
      13,    0,  127,    2, 0x08,
      14,    0,  128,    2, 0x08,
      15,    0,  129,    2, 0x08,
      16,    0,  130,    2, 0x08,
      17,    0,  131,    2, 0x08,
      18,    0,  132,    2, 0x08,
      19,    0,  133,    2, 0x08,
      20,    0,  134,    2, 0x08,
      21,    0,  135,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
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
        case 6: _t->onStartNetResult((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 7: _t->onStopNetResult((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 8: _t->handleSingleMeasButton(); break;
        case 9: _t->handleAutomaticMeasButton(); break;
        case 10: _t->handleGetAll(); break;
        case 11: _t->handleAddNode(); break;
        case 12: _t->handleRemoveNode(); break;
        case 13: _t->handleStartNet(); break;
        case 14: _t->handleStopNet(); break;
        case 15: _t->handleGetNodes(); break;
        case 16: _t->handleMakeMeasure(); break;
        case 17: _t->timerNotif(); break;
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
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 7:
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::startMeasure()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
