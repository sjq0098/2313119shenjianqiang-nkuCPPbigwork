/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_notepad
{
public:
    QAction *action_newfile;
    QAction *action_open;
    QAction *action_save;
    QAction *action_save_as;
    QAction *action_paste;
    QAction *action_cut;
    QAction *action_copy;
    QAction *action_bolder;
    QAction *action_italic;
    QAction *action_underline;
    QAction *action_font;
    QAction *action_aboutinfo;
    QAction *action_undo;
    QAction *action_redo;
    QAction *action_exit;
    QAction *action_history_clear;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *recently;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *notepad)
    {
        if (notepad->objectName().isEmpty())
            notepad->setObjectName(QString::fromUtf8("notepad"));
        notepad->resize(1920, 1080);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/recourse/icon/note.png"), QSize(), QIcon::Normal, QIcon::Off);
        notepad->setWindowIcon(icon);
        action_newfile = new QAction(notepad);
        action_newfile->setObjectName(QString::fromUtf8("action_newfile"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/recourse/icon/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_newfile->setIcon(icon1);
        action_open = new QAction(notepad);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/recourse/icon/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon2);
        action_save = new QAction(notepad);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/recourse/icon/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_save->setIcon(icon3);
        action_save_as = new QAction(notepad);
        action_save_as->setObjectName(QString::fromUtf8("action_save_as"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/recourse/icon/keepas.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_save_as->setIcon(icon4);
        action_paste = new QAction(notepad);
        action_paste->setObjectName(QString::fromUtf8("action_paste"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/recourse/icon/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_paste->setIcon(icon5);
        action_cut = new QAction(notepad);
        action_cut->setObjectName(QString::fromUtf8("action_cut"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/recourse/icon/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_cut->setIcon(icon6);
        action_copy = new QAction(notepad);
        action_copy->setObjectName(QString::fromUtf8("action_copy"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/recourse/icon/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_copy->setIcon(icon7);
        action_bolder = new QAction(notepad);
        action_bolder->setObjectName(QString::fromUtf8("action_bolder"));
        action_bolder->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/recourse/icon/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_bolder->setIcon(icon8);
        action_italic = new QAction(notepad);
        action_italic->setObjectName(QString::fromUtf8("action_italic"));
        action_italic->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/recourse/icon/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_italic->setIcon(icon9);
        action_underline = new QAction(notepad);
        action_underline->setObjectName(QString::fromUtf8("action_underline"));
        action_underline->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icon/recourse/icon/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_underline->setIcon(icon10);
        action_font = new QAction(notepad);
        action_font->setObjectName(QString::fromUtf8("action_font"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icon/recourse/icon/font.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_font->setIcon(icon11);
        action_aboutinfo = new QAction(notepad);
        action_aboutinfo->setObjectName(QString::fromUtf8("action_aboutinfo"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icon/recourse/icon/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_aboutinfo->setIcon(icon12);
        action_undo = new QAction(notepad);
        action_undo->setObjectName(QString::fromUtf8("action_undo"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icon/recourse/icon/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_undo->setIcon(icon13);
        action_redo = new QAction(notepad);
        action_redo->setObjectName(QString::fromUtf8("action_redo"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icon/recourse/icon/redo_.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_redo->setIcon(icon14);
        action_exit = new QAction(notepad);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icon/recourse/icon/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon15);
        action_history_clear = new QAction(notepad);
        action_history_clear->setObjectName(QString::fromUtf8("action_history_clear"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icon/recourse/icon/clear_history.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_history_clear->setIcon(icon16);
        centralwidget = new QWidget(notepad);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(40, 20, 104, 70));
        notepad->setCentralWidget(centralwidget);
        menubar = new QMenuBar(notepad);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setTearOffEnabled(false);
        recently = new QMenu(menu);
        recently->setObjectName(QString::fromUtf8("recently"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        notepad->setMenuBar(menubar);
        statusbar = new QStatusBar(notepad);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        notepad->setStatusBar(statusbar);
        toolBar = new QToolBar(notepad);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(36, 36));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        notepad->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action_open);
        menu->addAction(recently->menuAction());
        menu->addAction(action_save);
        menu->addAction(action_save_as);
        menu->addAction(action_newfile);
        menu->addSeparator();
        menu->addAction(action_exit);
        recently->addAction(action_history_clear);
        menu_2->addAction(action_cut);
        menu_2->addAction(action_copy);
        menu_2->addAction(action_paste);
        menu_2->addAction(action_bolder);
        menu_2->addAction(action_italic);
        menu_2->addAction(action_underline);
        menu_2->addAction(action_font);
        menu_2->addSeparator();
        menu_3->addAction(action_aboutinfo);
        toolBar->addAction(action_newfile);
        toolBar->addAction(action_open);
        toolBar->addAction(action_save);
        toolBar->addAction(action_save_as);
        toolBar->addSeparator();
        toolBar->addAction(action_copy);
        toolBar->addAction(action_paste);
        toolBar->addAction(action_cut);
        toolBar->addSeparator();
        toolBar->addAction(action_font);
        toolBar->addAction(action_bolder);
        toolBar->addAction(action_italic);
        toolBar->addAction(action_underline);
        toolBar->addSeparator();
        toolBar->addAction(action_undo);
        toolBar->addAction(action_redo);
        toolBar->addSeparator();
        toolBar->addAction(action_exit);
        toolBar->addAction(action_aboutinfo);
        toolBar->addSeparator();

        retranslateUi(notepad);

        QMetaObject::connectSlotsByName(notepad);
    } // setupUi

    void retranslateUi(QMainWindow *notepad)
    {
        notepad->setWindowTitle(QCoreApplication::translate("notepad", "qtnote4.0-notepad", nullptr));
        action_newfile->setText(QCoreApplication::translate("notepad", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(shortcut)
        action_newfile->setShortcut(QCoreApplication::translate("notepad", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_open->setText(QCoreApplication::translate("notepad", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(shortcut)
        action_open->setShortcut(QCoreApplication::translate("notepad", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_save->setText(QCoreApplication::translate("notepad", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(shortcut)
        action_save->setShortcut(QCoreApplication::translate("notepad", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_save_as->setText(QCoreApplication::translate("notepad", "\345\217\246\345\255\230\344\270\272", nullptr));
#if QT_CONFIG(shortcut)
        action_save_as->setShortcut(QCoreApplication::translate("notepad", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_paste->setText(QCoreApplication::translate("notepad", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(shortcut)
        action_paste->setShortcut(QCoreApplication::translate("notepad", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        action_cut->setText(QCoreApplication::translate("notepad", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(shortcut)
        action_cut->setShortcut(QCoreApplication::translate("notepad", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        action_copy->setText(QCoreApplication::translate("notepad", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(shortcut)
        action_copy->setShortcut(QCoreApplication::translate("notepad", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        action_bolder->setText(QCoreApplication::translate("notepad", "\345\212\240\347\262\227", nullptr));
#if QT_CONFIG(shortcut)
        action_bolder->setShortcut(QCoreApplication::translate("notepad", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        action_italic->setText(QCoreApplication::translate("notepad", "\346\226\234\344\275\223", nullptr));
#if QT_CONFIG(shortcut)
        action_italic->setShortcut(QCoreApplication::translate("notepad", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        action_underline->setText(QCoreApplication::translate("notepad", "\344\270\213\345\210\222\347\272\277", nullptr));
#if QT_CONFIG(shortcut)
        action_underline->setShortcut(QCoreApplication::translate("notepad", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        action_font->setText(QCoreApplication::translate("notepad", "\345\255\227\344\275\223", nullptr));
#if QT_CONFIG(shortcut)
        action_font->setShortcut(QCoreApplication::translate("notepad", "Ctrl+Shift+F", nullptr));
#endif // QT_CONFIG(shortcut)
        action_aboutinfo->setText(QCoreApplication::translate("notepad", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(shortcut)
        action_aboutinfo->setShortcut(QCoreApplication::translate("notepad", "Ctrl+Shift+B", nullptr));
#endif // QT_CONFIG(shortcut)
        action_undo->setText(QCoreApplication::translate("notepad", "\346\222\244\345\233\236", nullptr));
#if QT_CONFIG(shortcut)
        action_undo->setShortcut(QCoreApplication::translate("notepad", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        action_redo->setText(QCoreApplication::translate("notepad", "\351\207\215\345\201\232", nullptr));
#if QT_CONFIG(shortcut)
        action_redo->setShortcut(QCoreApplication::translate("notepad", "Ctrl+Shift+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        action_exit->setText(QCoreApplication::translate("notepad", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(shortcut)
        action_exit->setShortcut(QCoreApplication::translate("notepad", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        action_history_clear->setText(QCoreApplication::translate("notepad", "\346\270\205\351\231\244\345\216\206\345\217\262", nullptr));
#if QT_CONFIG(shortcut)
        action_history_clear->setShortcut(QCoreApplication::translate("notepad", "Ctrl+Alt+Shift+C", nullptr));
#endif // QT_CONFIG(shortcut)
        menu->setTitle(QCoreApplication::translate("notepad", "\346\226\207\344\273\266", nullptr));
        recently->setTitle(QCoreApplication::translate("notepad", "\346\234\200\350\277\221\346\211\223\345\274\200", nullptr));
        menu_2->setTitle(QCoreApplication::translate("notepad", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("notepad", "\345\205\263\344\272\216", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("notepad", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class notepad: public Ui_notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
