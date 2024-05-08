/********************************************************************************
** Form generated from reading UI file 'textedit_form.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEDIT_FORM_H
#define UI_TEXTEDIT_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_textEdit_form
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *textEdit_form)
    {
        if (textEdit_form->objectName().isEmpty())
            textEdit_form->setObjectName(QString::fromUtf8("textEdit_form"));
        textEdit_form->resize(400, 300);
        verticalLayout = new QVBoxLayout(textEdit_form);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textEdit = new QTextEdit(textEdit_form);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit->setLineWrapMode(QTextEdit::WidgetWidth);

        horizontalLayout->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(textEdit_form);

        QMetaObject::connectSlotsByName(textEdit_form);
    } // setupUi

    void retranslateUi(QWidget *textEdit_form)
    {
        textEdit_form->setWindowTitle(QCoreApplication::translate("textEdit_form", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class textEdit_form: public Ui_textEdit_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDIT_FORM_H
