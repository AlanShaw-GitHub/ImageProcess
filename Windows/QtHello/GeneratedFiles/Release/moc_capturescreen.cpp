/****************************************************************************
** Meta object code from reading C++ file 'capturescreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../capturescreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'capturescreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CaptureScreen_t {
    QByteArrayData data[6];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CaptureScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CaptureScreen_t qt_meta_stringdata_CaptureScreen = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CaptureScreen"
QT_MOC_LITERAL(1, 14, 20), // "signalCompleteCature"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 12), // "m_beginPoint"
QT_MOC_LITERAL(4, 49, 10), // "m_endPoint"
QT_MOC_LITERAL(5, 60, 21) // "signalCompleteCature2"

    },
    "CaptureScreen\0signalCompleteCature\0\0"
    "m_beginPoint\0m_endPoint\0signalCompleteCature2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CaptureScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       5,    1,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint, QMetaType::QPoint,    3,    4,
    QMetaType::Void, QMetaType::QPoint,    3,

       0        // eod
};

void CaptureScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CaptureScreen *_t = static_cast<CaptureScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalCompleteCature((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 1: _t->signalCompleteCature2((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CaptureScreen::*_t)(QPoint , QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CaptureScreen::signalCompleteCature)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CaptureScreen::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CaptureScreen::signalCompleteCature2)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CaptureScreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CaptureScreen.data,
      qt_meta_data_CaptureScreen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CaptureScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaptureScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CaptureScreen.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CaptureScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CaptureScreen::signalCompleteCature(QPoint _t1, QPoint _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CaptureScreen::signalCompleteCature2(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
