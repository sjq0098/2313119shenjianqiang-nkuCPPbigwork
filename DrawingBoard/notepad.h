#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include<QPushButton>
#include<QFileDialog>
#include<QMessageBox>
#include<QSettings>
#include<QFontDialog>
#include<QList>
#include<QTabWidget>
#include<qevent.h>

#include"textedit_form.h"
namespace Ui {
class notepad;
}

class notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit notepad(QWidget *parent = nullptr);
    ~notepad();
    bool checkSaveState();

signals:
    void  back();
private slots:
    void on_action_newfile_triggered();

    void on_action_open_triggered();

    void on_action_save_triggered();

    void on_action_save_as_triggered();

    void on_action_paste_triggered();

    void on_action_cut_triggered();

    void on_action_copy_triggered();

    void on_action_bolder_triggered(bool checked);

    void on_action_italic_triggered(bool checked);

    void on_action_underline_triggered(bool checked);

    void on_action_font_triggered();

    void on_action_aboutinfo_triggered();

    void on_action_undo_triggered();

    void on_action_redo_triggered();

    void on_action_exit_triggered();

    void on_action_history_clear_triggered();

private:
    Ui::notepad *ui;

    QString m_FileName;    
    bool isSaved=false;



    void initMenu();
    void open_recent_file();
    void saveHistory(QString path);
    QList<QString> GetHistory();
    void updateSaveState();
protected:
    void closeEvent(QCloseEvent*event);
};

#endif // NOTEPAD_H
