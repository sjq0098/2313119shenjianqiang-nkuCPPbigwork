#ifndef TEXTEDIT_FORM_H
#define TEXTEDIT_FORM_H

#include <QWidget>

namespace Ui {
class textEdit_form;
}

class textEdit_form : public QWidget
{
    Q_OBJECT

public:
    explicit textEdit_form(QWidget *parent = nullptr);
    ~textEdit_form();
    void inniFont();

private:
    Ui::textEdit_form *ui;
};

#endif // TEXTEDIT_FORM_H
