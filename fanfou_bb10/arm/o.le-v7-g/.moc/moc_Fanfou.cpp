/****************************************************************************
** Meta object code from reading C++ file 'Fanfou.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/fanfou/Fanfou.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Fanfou.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Fanfou[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,    8,    7,    7, 0x05,
      34,    8,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   55,    7,    7, 0x08,

 // methods: signature, parameters, type, tag, flags
      96,    7,   91,    7, 0x02,
     124,  106,    7,    7, 0x02,
     147,    7,    7,    7, 0x02,
     156,    7,    7,    7, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_Fanfou[] = {
    "Fanfou\0\0msg\0loginSuccess(QString)\0"
    "loginFailed(QString)\0reply\0"
    "onLoginResult(QNetworkReply*)\0bool\0"
    "isLogin()\0username,password\0"
    "login(QString,QString)\0logout()\0"
    "setAsLogined()\0"
};

void Fanfou::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Fanfou *_t = static_cast<Fanfou *>(_o);
        switch (_id) {
        case 0: _t->loginSuccess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->loginFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onLoginResult((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: { bool _r = _t->isLogin();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->login((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->logout(); break;
        case 6: _t->setAsLogined(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Fanfou::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Fanfou::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Fanfou,
      qt_meta_data_Fanfou, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Fanfou::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Fanfou::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Fanfou::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Fanfou))
        return static_cast<void*>(const_cast< Fanfou*>(this));
    return QObject::qt_metacast(_clname);
}

int Fanfou::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Fanfou::loginSuccess(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Fanfou::loginFailed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
