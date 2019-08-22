#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "AboutXcan/dialogaboutthisxcan.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static bool isOpen_dialogAboutThisXcan_ui;

    void APIHasChanged(void);
    void ErrorHasChanged(void);
    void ModuleHasChanged(void);

    void SQLiteInsertDet_ReportError(void);
    QString SQLiteInsertData(
            int ModuleId,QString ModuleIdname,QString ModuleType,
            int ApiId,QString ApiIdname,QString ApiType,
            int ErrorId,QString ErrorIdname,QString ErrorType,
            QString ErrorInfo
                             );
private slots:

//    void show_menu(const QPoint &pos);
//    void slot_DL_AddOneRow(void);
//    void slot_DL_JoinToDataBase(void);
//    void slot_DL_DeleteThisRow(void);

    void on_lineEdit_mModuleId_textChanged(const QString &arg1);

    void on_lineEdit_mApiId_textChanged(const QString &arg1);

    void on_lineEdit_mErrorId_textChanged(const QString &arg1);

    void on_actionInputEXCEL_triggered();

    void on_actionConnect_triggered();

private:
    Ui::MainWindow *ui;

    DialogAboutThisXcan *dialogAboutThisXcan_ui;
};

#endif // MAINWINDOW_H
