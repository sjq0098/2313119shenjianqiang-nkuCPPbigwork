/********************************************************************************
** Form generated from reading UI file 'form_start.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_START_H
#define UI_FORM_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_start
{
public:
    QAction *action_aboutinfo;
    QWidget *centralwidget;
    QPushButton *pb1;
    QPushButton *pb2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *form_start)
    {
        if (form_start->objectName().isEmpty())
            form_start->setObjectName(QString::fromUtf8("form_start"));
        form_start->resize(1920, 1080);
        form_start->setStyleSheet(QString::fromUtf8("background-image: url(:/icon/recourse/bg_bggenerator_com.png);"));
        action_aboutinfo = new QAction(form_start);
        action_aboutinfo->setObjectName(QString::fromUtf8("action_aboutinfo"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/recourse/icon/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_aboutinfo->setIcon(icon);
        centralwidget = new QWidget(form_start);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pb1 = new QPushButton(centralwidget);
        pb1->setObjectName(QString::fromUtf8("pb1"));
        pb1->setGeometry(QRect(90, 400, 600, 200));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(16);
        pb1->setFont(font);
        pb1->setIconSize(QSize(100, 100));
        pb2 = new QPushButton(centralwidget);
        pb2->setObjectName(QString::fromUtf8("pb2"));
        pb2->setGeometry(QRect(90, 650, 600, 200));
        pb2->setFont(font);
        pb2->setMouseTracking(false);
        pb2->setIconSize(QSize(100, 100));
        form_start->setCentralWidget(centralwidget);
        menubar = new QMenuBar(form_start);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        form_start->setMenuBar(menubar);
        statusbar = new QStatusBar(form_start);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        form_start->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action_aboutinfo);

        retranslateUi(form_start);

        QMetaObject::connectSlotsByName(form_start);
    } // setupUi

    void retranslateUi(QMainWindow *form_start)
    {
        form_start->setWindowTitle(QCoreApplication::translate("form_start", "qtnote_\345\274\200\345\247\213", nullptr));
        action_aboutinfo->setText(QCoreApplication::translate("form_start", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(shortcut)
        action_aboutinfo->setShortcut(QCoreApplication::translate("form_start", "Ctrl+Shift+B", nullptr));
#endif // QT_CONFIG(shortcut)
        pb1->setText(QCoreApplication::translate("form_start", "\347\224\273\347\202\271\344\273\200\344\271\210\357\274\237\350\277\233\345\205\245\350\207\252\347\224\261\347\224\273\346\235\277", nullptr));
        pb2->setText(QCoreApplication::translate("form_start", "\345\206\231\347\202\271\344\273\200\344\271\210\357\274\237\350\277\233\345\205\245\346\226\207\346\234\254\347\274\226\350\276\221", nullptr));
        menu->setTitle(QCoreApplication::translate("form_start", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class form_start: public Ui_form_start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_START_H
