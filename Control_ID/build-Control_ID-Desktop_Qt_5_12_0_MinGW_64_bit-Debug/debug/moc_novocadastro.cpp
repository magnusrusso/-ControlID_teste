/****************************************************************************
** Meta object code from reading C++ file 'novocadastro.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Control_ID/novocadastro.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'novocadastro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_novocadastro_t {
    QByteArrayData data[8];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_novocadastro_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_novocadastro_t qt_meta_stringdata_novocadastro = {
    {
QT_MOC_LITERAL(0, 0, 12), // "novocadastro"
QT_MOC_LITERAL(1, 13, 20), // "on_cadastrar_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 17), // "on_cartao_clicked"
QT_MOC_LITERAL(4, 53, 20), // "on_escolha_activated"
QT_MOC_LITERAL(5, 74, 4), // "arg1"
QT_MOC_LITERAL(6, 79, 17), // "on_novo_activated"
QT_MOC_LITERAL(7, 97, 29) // "on_escolha_currentTextChanged"

    },
    "novocadastro\0on_cadastrar_clicked\0\0"
    "on_cartao_clicked\0on_escolha_activated\0"
    "arg1\0on_novo_activated\0"
    "on_escolha_currentTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_novocadastro[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x08 /* Private */,
       7,    1,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void novocadastro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        novocadastro *_t = static_cast<novocadastro *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_cadastrar_clicked(); break;
        case 2: _t->on_escolha_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_novo_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_escolha_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject novocadastro::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_novocadastro.data,
    qt_meta_data_novocadastro,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *novocadastro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *novocadastro::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_novocadastro.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int novocadastro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
