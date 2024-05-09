/****************************************************************************
** Meta object code from reading C++ file 'DrawingBoard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DrawingBoard/DrawingBoard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DrawingBoard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DrawingboardWidget_t {
    QByteArrayData data[12];
    char stringdata0[296];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawingboardWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawingboardWidget_t qt_meta_stringdata_DrawingboardWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DrawingboardWidget"
QT_MOC_LITERAL(1, 19, 4), // "back"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 31), // "fn_Recv_RectangleButton_Clicked"
QT_MOC_LITERAL(4, 57, 29), // "fn_Recv_EllipseButton_Clicked"
QT_MOC_LITERAL(5, 87, 29), // "fn_Recv_trangleButton_Clicked"
QT_MOC_LITERAL(6, 117, 26), // "fn_Recv_lineButton_Clicked"
QT_MOC_LITERAL(7, 144, 26), // "fn_Recv_TextButton_Clicked"
QT_MOC_LITERAL(8, 171, 32), // "fn_Recv_rotateLeftButton_Clicked"
QT_MOC_LITERAL(9, 204, 33), // "fn_Recv_rotateRightButton_Cli..."
QT_MOC_LITERAL(10, 238, 22), // "fn_Recv_Pencil_Clicked"
QT_MOC_LITERAL(11, 261, 34) // "fn_Recv_SwitchToNoteButton_Cl..."

    },
    "DrawingboardWidget\0back\0\0"
    "fn_Recv_RectangleButton_Clicked\0"
    "fn_Recv_EllipseButton_Clicked\0"
    "fn_Recv_trangleButton_Clicked\0"
    "fn_Recv_lineButton_Clicked\0"
    "fn_Recv_TextButton_Clicked\0"
    "fn_Recv_rotateLeftButton_Clicked\0"
    "fn_Recv_rotateRightButton_Clicked\0"
    "fn_Recv_Pencil_Clicked\0"
    "fn_Recv_SwitchToNoteButton_Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawingboardWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x09 /* Protected */,
       4,    0,   66,    2, 0x09 /* Protected */,
       5,    0,   67,    2, 0x09 /* Protected */,
       6,    0,   68,    2, 0x09 /* Protected */,
       7,    0,   69,    2, 0x09 /* Protected */,
       8,    0,   70,    2, 0x09 /* Protected */,
       9,    0,   71,    2, 0x09 /* Protected */,
      10,    0,   72,    2, 0x09 /* Protected */,
      11,    0,   73,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void DrawingboardWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DrawingboardWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back(); break;
        case 1: { int _r = _t->fn_Recv_RectangleButton_Clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->fn_Recv_EllipseButton_Clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->fn_Recv_trangleButton_Clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->fn_Recv_lineButton_Clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->fn_Recv_TextButton_Clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->fn_Recv_rotateLeftButton_Clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->fn_Recv_rotateRightButton_Clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->fn_Recv_Pencil_Clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->fn_Recv_SwitchToNoteButton_Clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DrawingboardWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrawingboardWidget::back)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DrawingboardWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DrawingboardWidget.data,
    qt_meta_data_DrawingboardWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawingboardWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawingboardWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawingboardWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DrawingboardWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void DrawingboardWidget::back()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
