#include "textedit_form.h"
#include "ui_textedit_form.h"

textEdit_form::textEdit_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::textEdit_form)
{
    ui->setupUi(this);
   inniFont();//初始化字体的函数
}

textEdit_form::~textEdit_form()
{
    delete ui;
}

void textEdit_form::inniFont()
{
    QFont font("华文行楷",14);
    ui->textEdit->setFont(font);
}


