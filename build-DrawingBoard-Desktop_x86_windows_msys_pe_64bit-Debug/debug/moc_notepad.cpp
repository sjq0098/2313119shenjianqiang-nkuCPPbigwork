/****************************************************************************
** Meta object code from reading C++ file 'notepad.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DrawingBoard/notepad.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notepad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_notepad_t {
    QByteArrayData data[20];
    char stringdata0[451];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_notepad_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_notepad_t qt_meta_stringdata_notepad = {
    {
QT_MOC_LITERAL(0, 0, 7), // "notepad"
QT_MOC_LITERAL(1, 8, 4), // "back"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 27), // "on_action_newfile_triggered"
QT_MOC_LITERAL(4, 42, 24), // "on_action_open_triggered"
QT_MOC_LITERAL(5, 67, 24), // "on_action_save_triggered"
QT_MOC_LITERAL(6, 92, 27), // "on_action_save_as_triggered"
QT_MOC_LITERAL(7, 120, 25), // "on_action_paste_triggered"
QT_MOC_LITERAL(8, 146, 23), // "on_action_cut_triggered"
QT_MOC_LITERAL(9, 170, 24), // "on_action_copy_triggered"
QT_MOC_LITERAL(10, 195, 26), // "on_action_bolder_triggered"
QT_MOC_LITERAL(11, 222, 7), // "checked"
QT_MOC_LITERAL(12, 230, 26), // "on_action_italic_triggered"
QT_MOC_LITERAL(13, 257, 29), // "on_action_underline_triggered"
QT_MOC_LITERAL(14, 287, 24), // "on_action_font_triggered"
QT_MOC_LITERAL(15, 312, 29), // "on_action_aboutinfo_triggered"
QT_MOC_LITERAL(16, 342, 24), // "on_action_undo_triggered"
QT_MOC_LITERAL(17, 367, 24), // "on_action_redo_triggered"
QT_MOC_LITERAL(18, 392, 24), // "on_action_exit_triggered"
QT_MOC_LITERAL(19, 417, 33) // "on_action_history_clear_trigg..."

    },
    "notepad\0back\0\0on_action_newfile_triggered\0"
    "on_action_open_triggered\0"
    "on_action_save_triggered\0"
    "on_action_save_as_triggered\0"
    "on_action_paste_triggered\0"
    "on_action_cut_triggered\0"
    "on_action_copy_triggered\0"
    "on_action_bolder_triggered\0checked\0"
    "on_action_italic_triggered\0"
    "on_action_underline_triggered\0"
    "on_action_font_triggered\0"
    "on_action_aboutinfo_triggered\0"
    "on_action_undo_triggered\0"
    "on_action_redo_triggered\0"
    "on_action_exit_triggered\0"
    "on_action_history_clear_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_notepad[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    1,  107,    2, 0x08 /* Private */,
      12,    1,  110,    2, 0x08 /* Private */,
      13,    1,  113,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void notepad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<notepad *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back(); break;
        case 1: _t->on_action_newfile_triggered(); break;
        case 2: _t->on_action_open_triggered(); break;
        case 3: _t->on_action_save_triggered(); break;
        case 4: _t->on_action_save_as_triggered(); break;
        case 5: _t->on_action_paste_triggered(); break;
        case 6: _t->on_action_cut_triggered(); break;
        case 7: _t->on_action_copy_triggered(); break;
        case 8: _t->on_action_bolder_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_action_italic_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_action_underline_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_action_font_triggered(); break;
        case 12: _t->on_action_aboutinfo_triggered(); break;
        case 13: _t->on_action_undo_triggered(); break;
        case 14: _t->on_action_redo_triggered(); break;
        case 15: _t->on_action_exit_triggered(); break;
        case 16: _t->on_action_history_clear_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (notepad::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&notepad::back)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject notepad::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_notepad.data,
    qt_meta_data_notepad,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *notepad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *notepad::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_notepad.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int notepad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void notepad::back()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
