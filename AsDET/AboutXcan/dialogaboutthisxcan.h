#ifndef DIALOGABOUTTHISXCAN_H
#define DIALOGABOUTTHISXCAN_H

#include <QDialog>

namespace Ui {
class DialogAboutThisXcan;
}

class DialogAboutThisXcan : public QDialog
{
    Q_OBJECT

public:

    static QString GetUsbCanSerial(void);
    explicit DialogAboutThisXcan(QWidget *parent = 0);
    ~DialogAboutThisXcan();

private:
    Ui::DialogAboutThisXcan *ui;


protected:
     void closeEvent(QCloseEvent *event);
};

#endif // DIALOGABOUTTHISXCAN_H
