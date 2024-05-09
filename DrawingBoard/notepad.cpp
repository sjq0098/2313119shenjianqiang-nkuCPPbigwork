#include "notepad.h"
#include "ui_notepad.h"
#include<QDebug>

 QSettings *m_settings;
notepad::notepad(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    setWindowIcon(QIcon(QString(":/icon/recourse/icon/note.png")));
    if(m_settings==NULL){
        m_settings= new QSettings("setings.ini",QSettings::IniFormat);
    }
    initMenu();
    initFont();
    connect(this,SIGNAL(ui->textEdit->textChanged()),this,SLOT(updateSaveState()));
}

notepad::~notepad()
{
    delete ui;
}


QList<QString> notepad::GetHistory(){
    //开始读取数据
    int iSize=m_settings->beginReadArray("history");
    //创建返回对象
    QList<QString> history_list;
    for(int i=0;i<iSize;i++){
        m_settings->setArrayIndex(i);
        QString path=m_settings->value("path").toString();
        history_list.append( path);
    }
    m_settings->endArray();
    return history_list;
}


void notepad::saveHistory(QString path){
    /*开始获取数组长度
    int iSize= m_settings->beginReadArray("history");
     m_settings->endArray();
    //如果只写一个的话就会导致每一次都会覆盖,当写过gethistory这个函数后作了一定修改,使其能够去重*/
    QList<QString> history_list=GetHistory();
    history_list.append(path);
    history_list.removeDuplicates(); // 去重
        // 确保历史记录列表不超过某个大小（例如，10个）
        while (history_list.size() >= 10 && !history_list.isEmpty()) {
            history_list.removeFirst();
        }

    //开始写入
    m_settings->beginWriteArray("history");
    for(int i=0;i<history_list.size();i++){
        m_settings->setArrayIndex(i);
        //保存字符串
        m_settings->setValue("path",history_list[i]);
    }
    //结束写入
    m_settings->endArray();
    initMenu();
}//保存打开历史记录


void notepad::initMenu()
{
    QMenu *recently=this->findChild<QMenu *>("recently");
    QList<QObject*> chLists= recently->children();
    foreach(QObject *ch,chLists){
        QAction *action=(QAction *)ch;
        recently->removeAction(action);
    }
    QList<QString> history_lists=GetHistory();
    foreach(QString string,history_lists){
        recently->addAction(string,this,&notepad::open_recent_file);
    }
}//初始化菜单

void notepad::open_recent_file()
{
    QAction *action=(QAction*)sender();
    QString m_Current_FlieName=action->text();
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
    saveHistory(m_FileName);
}//打开最近文件



void notepad::on_action_newfile_triggered()
{
    QFont font("华文行楷",14);
    m_FileName.clear();
    ui->textEdit->setText("");
    ui->textEdit->setFont(font);
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
    setWindowTitle(m_FileName+("-open with qtnote5.0"));
    QTextStream in(&file);
    in.setCodec("UTF_8");
    QString Current_text=in.readAll();
    ui->textEdit->setText(Current_text);
    file.close();
    saveHistory(m_FileName);
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
    saveHistory(m_FileName);
    isSaved=true;
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
    saveHistory(m_FileName);
    isSaved=true;
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

void notepad::on_action_history_clear_triggered()
{
    m_settings->remove("history");
    initMenu();

}//清空打开历史记录

void notepad::closeEvent(QCloseEvent *event)
{
    if(!checkSaveState()){
         QMessageBox::StandardButton btn=  QMessageBox::question(this,"提示","还未保存，是否保存并退出？",QMessageBox::Yes|QMessageBox::No|QMessageBox::NoAll);
         if(btn==QMessageBox::Yes){
             on_action_save_triggered();
             event->accept();
         }
         else if(btn==QMessageBox::No){
             event->ignore();
         }
         else{
             event->accept();
         }
    }
}
void notepad::updateSaveState()
{
    isSaved=false;
}//更新保存状态
bool notepad::checkSaveState()
{
    return isSaved;
}//检查保存状态

void notepad::initFont()
{
     QFont font("华文行楷",14);
     ui->textEdit->setFont(font);
}
