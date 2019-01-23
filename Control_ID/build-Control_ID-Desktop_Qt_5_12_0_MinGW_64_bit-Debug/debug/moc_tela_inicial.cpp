/****************************************************************************
** Meta object code from reading C++ file 'tela_inicial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Control_ID/tela_inicial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tela_inicial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tela_inicial_t {
    QByteArrayData data[8];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tela_inicial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tela_inicial_t qt_meta_stringdata_tela_inicial = {
    {
QT_MOC_LITERAL(0, 0, 12), // "tela_inicial"
QT_MOC_LITERAL(1, 13, 15), // "on_sair_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "on_conectar_clicked"
QT_MOC_LITERAL(4, 50, 18), // "on_acionar_clicked"
QT_MOC_LITERAL(5, 69, 18), // "on_alterar_clicked"
QT_MOC_LITERAL(6, 88, 20), // "on_cadastrar_clicked"
QT_MOC_LITERAL(7, 109, 17) // "on_listar_clicked"

    },
    "tela_inicial\0on_sair_clicked\0\0"
    "on_conectar_clicked\0on_acionar_clicked\0"
    "on_alterar_clicked\0on_cadastrar_clicked\0"
    "on_listar_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tela_inicial[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void tela_inicial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tela_inicial *_t = static_cast<tela_inicial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_sair_clicked(); break;
        case 1: _t->on_conectar_clicked(); break;
        case 2: _t->on_acionar_clicked(); break;
        case 3: _t->on_alterar_clicked(); break;
        case 4: _t->on_cadastrar_clicked(); break;
        case 5: _t->on_listar_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject tela_inicial::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_tela_inicial.data,
    qt_meta_data_tela_inicial,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *tela_inicial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tela_inicial::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tela_inicial.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int tela_inicial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
