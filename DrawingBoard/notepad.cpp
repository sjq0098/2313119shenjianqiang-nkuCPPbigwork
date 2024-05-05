#include "notepad.h"
#include "ui_notepad.h"
#include<QDebug>

notepad::notepad(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    setWindowIcon(QIcon(QString(":/icon/recourse/icon/note.png")));

}

notepad::~notepad()
{
    delete ui;
}

void notepad::on_action_newfile_triggered()
{
    m_FileName.clear();
    ui->textEdit->setText("");
}//新建文件

void notepad::on_action_open_triggered()
{
    QString m_Current_FlieName= QFileDialog::getOpenFileName(this,"打开文件");
    QFile file(m_Current_FlieName);
    if(!file.open(QIODevice::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"警告","无法打开或无法修改本文件："+file.errorString());
        return;
    }
    m_FileName=m_Current_FlieName;
    setWindowTitle(m_FileName+("-open with qtnote3.0"));
    QTextStream in(&file);
    in.setCodec("UTF_8");
    QString Current_text=in.readAll();
    ui->textEdit->setText(Current_text);
    file.close();
}//打开文件

void notepad::on_action_save_triggered()
{
    QString Current_fileName;
    if(m_FileName.isEmpty()){
        Current_fileName=QFileDialog::getSaveFileName(this,"保存文件");
        m_FileName=Current_fileName;
    }
    else{
        Current_fileName=m_FileName;
    }
    QFile file(Current_fileName);
    if(!file.open(QIODevice::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"警告","无法保存或无法阅读本文件："+file.errorString());
        return;
    }
    setWindowTitle(Current_fileName);
    QTextStream out(&file);
    out.setCodec("UTF_8");
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.close();
}//保存文件

void notepad::on_action_save_as_triggered()
{
    QString Current_fileName=QFileDialog::getSaveFileName(this,"另存为文件");
    QFile file(Current_fileName);
    if(!file.open(QIODevice::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"警告","无法保存或无法阅读本文件："+file.errorString());
        return;
    }
        m_FileName=Current_fileName;
    setWindowTitle(Current_fileName);
    QTextStream out(&file);
    out.setCodec("UTF_8");
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.close();
}//另存为

void notepad::on_action_paste_triggered()
{
    ui->textEdit->paste();
}//粘贴

void notepad::on_action_cut_triggered()
{
     ui->textEdit->cut();
}//剪切

void notepad::on_action_copy_triggered()
{
    ui->textEdit->copy();
}//复制

void notepad::on_action_bolder_triggered(bool checked)
{
    ui->textEdit->setFontWeight(checked?QFont::Bold:QFont::Normal);
}//加粗

void notepad::on_action_italic_triggered(bool checked)
{
    ui->textEdit->setFontItalic(checked);
}//斜体

void notepad::on_action_underline_triggered(bool checked)
{
    ui->textEdit->setFontUnderline(checked);
}//下划线

void notepad::on_action_font_triggered()
{
    bool m_Font_Selected;
    QFont m_font=QFontDialog::getFont(&m_Font_Selected,this);
    if(m_Font_Selected){
        ui->textEdit->setFont(m_font);
    }
}

void notepad::on_action_aboutinfo_triggered()
{
    QMessageBox::about(this,"基于Qt自封装的文本编辑器的实现！","模仿的是Notepad++,虽然比较简陋，欢迎批评指正");
}

void notepad::on_action_undo_triggered()
{
    ui->textEdit->undo();
}//撤销

void notepad::on_action_redo_triggered()
{
    ui->textEdit->redo();
}//重做

void notepad::on_action_exit_triggered()
{
    emit this->back();
}


