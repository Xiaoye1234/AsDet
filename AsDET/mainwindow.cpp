#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QFileDialog>

#include <QAxObject>

//#include <qDebug>

#include "AboutXcan/dialogaboutthisxcan.h"


bool MainWindow::isOpen_dialogAboutThisXcan_ui = false;

static QMenu *popMenu;
static QMenu *popMenu1;
static QAction *AddOneRow;
static QAction *DeleteThisRow;
static QAction *JoinToDataBase;

QSqlDatabase database;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*************initial tableWdget**********************/
    ui->tableWidget_Det_ReportError->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget_Det_ReportError->setColumnCount(2);//只设置列数，行数动态中增加
    ui->tableWidget_Det_ReportError->setHorizontalHeaderLabels(QStringList()<<"Module"<<"ModuleType");
    ui->tableWidget_Det_ReportError->setEditTriggers(QAbstractItemView::DoubleClicked);//double click修改

    int mywidth = ui->tableWidget_Det_ReportError->width();
    int mywidth0 = mywidth/2;
    ui->tableWidget_Det_ReportError->setColumnWidth(0,mywidth0);
    ui->tableWidget_Det_ReportError->setColumnWidth(1,mywidth0);
    ui->tableWidget_Det_ReportError->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget_Det_ReportError->horizontalHeaderItem(1)->setTextAlignment(Qt::AlignLeft);
    // 选中行颜色
    ui->tableWidget_Det_ReportError->setStyleSheet("selection-background-color: green");    // 行背景色
    ui->tableWidget_Det_ReportError->setSelectionBehavior(QAbstractItemView::SelectRows);   //整行选中的方式
    ui->tableWidget_Det_ReportError->setSelectionMode(QAbstractItemView::SingleSelection);  //
    ui->tableWidget_Det_ReportError->setAutoScroll(false);//去掉自动滚动
    ui->tableWidget_Det_ReportError->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分列
    ui->tableWidget_Det_ReportError->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
    /*************initial tableWdget1**********************/
    ui->tableWidget_Det_ReportError_API->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget_Det_ReportError_API->setColumnCount(2);//只设置列数，行数动态中增加
    ui->tableWidget_Det_ReportError_API->setHorizontalHeaderLabels(QStringList()<<"API"<<"APIType");
    ui->tableWidget_Det_ReportError_API->setEditTriggers(QAbstractItemView::DoubleClicked);//double click修改

    ui->tableWidget_Det_ReportError_API->setColumnWidth(0,mywidth0);
    ui->tableWidget_Det_ReportError_API->setColumnWidth(1,mywidth0);
    ui->tableWidget_Det_ReportError_API->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget_Det_ReportError_API->horizontalHeaderItem(1)->setTextAlignment(Qt::AlignLeft);
    // 选中行颜色
    ui->tableWidget_Det_ReportError_API->setStyleSheet("selection-background-color: green");    // 行背景色
    ui->tableWidget_Det_ReportError_API->setSelectionBehavior(QAbstractItemView::SelectRows);   //整行选中的方式
    ui->tableWidget_Det_ReportError_API->setSelectionMode(QAbstractItemView::SingleSelection);  //
    ui->tableWidget_Det_ReportError_API->setAutoScroll(false);//去掉自动滚动
    ui->tableWidget_Det_ReportError_API->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分列
    ui->tableWidget_Det_ReportError_API->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
    ui->progressBar_loadspeed->setVisible(false);//隐藏下载进度条
    ui->label_loadspeed->setVisible(false);//隐藏下载进度信息
    /*************initial tableWdget2**********************/
    ui->tableWidget_Det_ReportError_ERROR->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget_Det_ReportError_ERROR->setColumnCount(2);//只设置列数，行数动态中增加
    ui->tableWidget_Det_ReportError_ERROR->setHorizontalHeaderLabels(QStringList()<<"Error"<<"ErrorType");
    ui->tableWidget_Det_ReportError_ERROR->setEditTriggers(QAbstractItemView::DoubleClicked);//double click修改

    ui->tableWidget_Det_ReportError_ERROR->setColumnWidth(0,mywidth0);
    ui->tableWidget_Det_ReportError_ERROR->setColumnWidth(1,mywidth0);
    ui->tableWidget_Det_ReportError_ERROR->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget_Det_ReportError_ERROR->horizontalHeaderItem(1)->setTextAlignment(Qt::AlignLeft);
    // 选中行颜色
    ui->tableWidget_Det_ReportError_ERROR->setStyleSheet("selection-background-color: green");    // 行背景色
    ui->tableWidget_Det_ReportError_ERROR->setSelectionBehavior(QAbstractItemView::SelectRows);   //整行选中的方式
    ui->tableWidget_Det_ReportError_ERROR->setSelectionMode(QAbstractItemView::SingleSelection);  //
    ui->tableWidget_Det_ReportError_ERROR->setAutoScroll(false);//去掉自动滚动
    ui->tableWidget_Det_ReportError_ERROR->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分列
    ui->tableWidget_Det_ReportError_ERROR->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
    /*右击菜单**/
//    popMenu = new QMenu(ui->tableWidget_Det_ReportError);
//    popMenu1 = new QMenu(ui->tableWidget_Det_ReportError);

//    AddOneRow = new QAction("AddOneRow", this);
//    DeleteThisRow = new QAction("DeleteThisRow",this);
//    JoinToDataBase = new QAction("JoinToDataBase",this);

//    popMenu->addAction(AddOneRow);
//    popMenu1->addAction(AddOneRow);
//    popMenu1->addAction(DeleteThisRow);
//    popMenu1->addAction(JoinToDataBase);

//    ui->tableWidget_Det_ReportError->setContextMenuPolicy (Qt::CustomContextMenu);
//    connect(ui->tableWidget_Det_ReportError,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(show_menu(QPoint)));

//    connect(AddOneRow, SIGNAL(triggered()), this, SLOT(slot_DL_AddOneRow()));
//    connect(DeleteThisRow, SIGNAL(triggered()), this, SLOT(slot_DL_DeleteThisRow()));
//    connect(JoinToDataBase, SIGNAL(triggered()), this, SLOT(slot_DL_JoinToDataBase()));
    /**************************************************/

    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setUserName("XingYeZhiXia");
        database.setDatabaseName("MyDataBase.db");
        database.setPassword("123456");
    }

    if (!database.open())
    {
        ui->textEdit_Det_ReportError->append("Error: Failed to connect database."+database.lastError().databaseText());
    }
    else
    {
        ui->textEdit_Det_ReportError->append("connect database ok");

        QSqlQuery sql_query1(database);
        QString create_sql = "create table Det_ReportError("
                             "ModuleId int,"
                             "ModuleIdname varchar,"
                             "ModuleType varchar,"
                             "ApiId int,"
                             "ApiIdname varchar,"
                             "ApiType varchar,"
                             "ErrorId int,"
                             "ErrorIdname varchar,"
                             "ErrorType varchar,"
                             "ErrorInfo varchar,"
                             "primary key (ModuleId,ApiId,ErrorId)"
                             ")";

        if(!sql_query1.exec(create_sql))
        {
            QSqlError error = sql_query1.lastError();
            ui->textEdit_Det_ReportError->append("Error: Fail to create table."+error.databaseText());
        }
        else
        {
            ui->textEdit_Det_ReportError->append("Table created!");
        }
    }
}
//void MainWindow::show_menu(const QPoint &pos)
//{
//    if(-1 != ui->tableWidget_Det_ReportError->currentRow())
//    {
//        popMenu1->exec(QCursor::pos());
//    }
//    else
//    {
//        popMenu->exec(QCursor::pos());
//    }
//}
//void MainWindow::slot_DL_AddOneRow(void)
//{
//    int RowCont;

//    RowCont=ui->tableWidget_Det_ReportError->rowCount();
//    ui->tableWidget_Det_ReportError->insertRow(RowCont);//增加一行
//    ui->tableWidget_Det_ReportError->setItem(RowCont,0,new QTableWidgetItem("--"));
//    ui->tableWidget_Det_ReportError->setItem(RowCont,1,new QTableWidgetItem("--"));
//    ui->tableWidget_Det_ReportError->setItem(RowCont,2,new QTableWidgetItem("--"));
//}
//void MainWindow::slot_DL_DeleteThisRow(void)
//{
//      int rowIndex = ui->tableWidget_Det_ReportError->currentRow();
//      if (rowIndex != -1)
//      {
//        ui->tableWidget_Det_ReportError->removeRow(rowIndex);
//      }
//}
//void MainWindow::slot_DL_JoinToDataBase(void)
//{
//    SQLiteInsertDet_ReportError();
//}

MainWindow::~MainWindow()
{
    database.close();
    delete ui;
}

void MainWindow::ModuleHasChanged(void)
{
    int ModuleId;
    bool execOk;
    bool ok1;

    QSqlQuery sql_query(database);
    QString ModuleIdStr = ui->lineEdit_mModuleId->text();

    if(ModuleIdStr.toLower().contains("0x"))
    {
        ModuleId = ModuleIdStr.toInt(&ok1,16);
    }
    else
    {
        ModuleId = ModuleIdStr.toInt(&ok1,10);
    }
    if(ModuleIdStr!="")
    {
        execOk = sql_query.exec(QString("select * from Det_ReportError where ModuleId='%1'").arg(ModuleId));
    }
    else
    {
        execOk = sql_query.exec(QString("select * from Det_ReportError"));
    }
    if(execOk == true)
    {
        int RowCont;
        QString ModuleIdnameStr;
        QString ModuleTypeStr;

        ui->tableWidget_Det_ReportError->setRowCount(0);
        ui->tableWidget_Det_ReportError->clearContents();

        QString text;
        while(sql_query.next())
        {
          ModuleIdnameStr = sql_query.value(1).toString();
          ModuleTypeStr = sql_query.value(2).toString();

          if(text!=ModuleIdnameStr)
          {
              RowCont=ui->tableWidget_Det_ReportError->rowCount();
              ui->tableWidget_Det_ReportError->insertRow(RowCont);//增加一行
              ui->tableWidget_Det_ReportError->setItem(RowCont,0,new QTableWidgetItem(ModuleIdnameStr));
              ui->tableWidget_Det_ReportError->setItem(RowCont,1,new QTableWidgetItem(ModuleTypeStr));

              text = ModuleIdnameStr;
          }
        }
    }
}
void MainWindow::APIHasChanged(void)
{
    int ModuleId;
    int ApiId;

    bool execOk;
    bool ok1,ok2;

    QSqlQuery sql_query(database);
    QString ModuleIdStr = ui->lineEdit_mModuleId->text();
    QString ApiIdStr = ui->lineEdit_mApiId->text();

    if(ModuleIdStr.toLower().contains("0x"))
    {
        ModuleId = ModuleIdStr.toInt(&ok1,16);
    }
    else
    {
        ModuleId = ModuleIdStr.toInt(&ok1,10);
    }
    if(ApiIdStr.toLower().contains("0x"))
    {
        ApiId = ApiIdStr.toInt(&ok2,16);
    }
    else
    {
        ApiId = ApiIdStr.toInt(&ok2,10);
    }
    if((ModuleIdStr!="")&&(ApiIdStr!=""))
    {
        execOk = sql_query.exec(QString("select * from Det_ReportError where ModuleId='%1' and ApiId='%2'").arg(ModuleId).arg(ApiId));
    }
    else
    {
        execOk = sql_query.exec(QString("select * from Det_ReportError"));
    }

    if(execOk == true)
    {
        int RowCont;
        QString ApiIdnameStr;
        QString ApiTypeStr;

        ui->tableWidget_Det_ReportError_API->setRowCount(0);
        ui->tableWidget_Det_ReportError_API->clearContents();

        while(sql_query.next())
        {
          ApiIdnameStr = sql_query.value(4).toString();
          ApiTypeStr = sql_query.value(5).toString();

          if(ApiIdnameStr!="")
          {
              RowCont=ui->tableWidget_Det_ReportError_API->rowCount();
              ui->tableWidget_Det_ReportError_API->insertRow(RowCont);//增加一行
              ui->tableWidget_Det_ReportError_API->setItem(RowCont,0,new QTableWidgetItem(ApiIdnameStr));
              ui->tableWidget_Det_ReportError_API->setItem(RowCont,1,new QTableWidgetItem(ApiTypeStr));
          }
        }
    }
}
void MainWindow::ErrorHasChanged(void)
{
    int ModuleId;
    int ErrorId;

    bool execOk;
    bool ok1,ok3;

    QSqlQuery sql_query(database);
    QString ModuleIdStr = ui->lineEdit_mModuleId->text();
    QString ErrorIdStr = ui->lineEdit_mErrorId->text();

    if(ModuleIdStr.toLower().contains("0x"))
    {
        ModuleId = ModuleIdStr.toInt(&ok1,16);
    }
    else
    {
        ModuleId = ModuleIdStr.toInt(&ok1,10);
    }
    if(ErrorIdStr.toLower().contains("0x"))
    {
        ErrorId = ErrorIdStr.toInt(&ok3,16);
    }
    else
    {
        ErrorId = ErrorIdStr.toInt(&ok3,10);
    }

    if((ModuleIdStr!="")&&(ErrorIdStr!=""))
    {
        execOk = sql_query.exec(QString("select * from Det_ReportError where ModuleId='%1' and ErrorId='%2'").arg(ModuleId).arg(ErrorId));
    }
    else
    {
        execOk = sql_query.exec(QString("select * from Det_ReportError"));
    }

    if(execOk == true)
    {
        int RowCont;
        QString ErrornameStr;
        QString ErrorTypeStr;
        QString ErrorInfoStr;

        ui->tableWidget_Det_ReportError_ERROR->setRowCount(0);
        ui->tableWidget_Det_ReportError_ERROR->clearContents();

        while(sql_query.next())
        {
          ErrornameStr = sql_query.value(7).toString();
          ErrorTypeStr = sql_query.value(8).toString();
          ErrorInfoStr = sql_query.value(9).toString();

          if(ErrornameStr!="")
          {
              RowCont=ui->tableWidget_Det_ReportError_ERROR->rowCount();
              ui->tableWidget_Det_ReportError_ERROR->insertRow(RowCont);//增加一行
              ui->tableWidget_Det_ReportError_ERROR->setItem(RowCont,0,new QTableWidgetItem(ErrornameStr));
              ui->tableWidget_Det_ReportError_ERROR->setItem(RowCont,1,new QTableWidgetItem(ErrorTypeStr));
              ui->textEdit_Det_ReportError->setText(ErrorInfoStr);
          }
        }
    }
}
void MainWindow::on_lineEdit_mModuleId_textChanged(const QString &arg1)
{
    ModuleHasChanged();
    APIHasChanged();
    ErrorHasChanged();
}

void MainWindow::on_lineEdit_mApiId_textChanged(const QString &arg1)
{
    APIHasChanged();
}

void MainWindow::on_lineEdit_mErrorId_textChanged(const QString &arg1)
{
    ErrorHasChanged();
}
void MainWindow::SQLiteInsertDet_ReportError(void)
{
//    int ModuleId;
//    int ApiId;
//    int ErrorId;
//    bool ok1,ok2,ok3;

//    QSqlQuery sql_query(database);

//    int rowIndex = ui->tableWidget_Det_ReportError->currentRow();
//    QString ModuleIdname = ui->tableWidget_Det_ReportError->item(rowIndex,0)->text();//取出字符
//    QString ApiIdname = ui->tableWidget_Det_ReportError->item(rowIndex,1)->text();//取出字符
//    QString TypenameStr = ui->tableWidget_Det_ReportError->item(rowIndex,2)->text();//取出字符
//    QString ErrorIdname = ui->textEdit_Det_ReportError->toPlainText();

//    if(ui->lineEdit_mModuleId->text().toLower().contains("0x"))
//    {
//        ModuleId = ui->lineEdit_mModuleId->text().toInt(&ok1,16);
//    }
//    else
//    {
//        ModuleId = ui->lineEdit_mModuleId->text().toInt(&ok1,10);
//    }
//    if(ui->lineEdit_mApiId->text().toLower().contains("0x"))
//    {
//        ApiId = ui->lineEdit_mApiId->text().toInt(&ok2,16);
//    }
//    else
//    {
//        ApiId = ui->lineEdit_mApiId->text().toInt(&ok2,10);
//    }
//    if(ui->lineEdit_mErrorId->text().toLower().contains("0x"))
//    {
//        ErrorId = ui->lineEdit_mErrorId->text().toInt(&ok3,16);
//    }
//    else
//    {
//        ErrorId = ui->lineEdit_mErrorId->text().toInt(&ok3,10);
//    }

//    if ((rowIndex != -1)&&(ok1)&&(ok2)&&(ok3))
//    {
//        QString retStr = SQLiteInsertData(
//                                     ModuleId, ModuleIdname,
//                                     ApiId, ApiIdname,
//                                     ErrorId, ErrorIdname,
//                                     TypenameStr
//                                 );
//        if(retStr!="inserted ok!")
//        {
//            ui->textEdit_Det_ReportError->append(retStr);
//        }
//        else
//        {
//            ui->textEdit_Det_ReportError->append(retStr);
//        }
//    }
//    else
//    {
//        ui->textEdit_Det_ReportError->append("Data element format error!");
//    }
}

void MainWindow::on_actionInputEXCEL_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("InputExcelDataBase"),
                                                    "D:",
                                                    tr("ExcelFile(*.xlsx)"
                                                       ));
    if(true == fileName.isEmpty())
    {
        return;
    }

    QAxObject *excel = NULL;    //本例中，excel设定为Excel文件的操作对象
    QAxObject *workbooks = NULL;
    QAxObject *workbook = NULL;  //Excel操作对象
    excel = new QAxObject("Excel.Application");
    excel->dynamicCall("SetVisible(bool)", false); //true 表示操作文件时可见，false表示为不可见
    workbooks = excel->querySubObject("WorkBooks");

    workbook = workbooks->querySubObject("Open(QString&)", fileName);//按文件路径打开文件
    QAxObject * worksheets = workbook->querySubObject("WorkSheets");//获取打开的excel文件中所有的工作sheet
    int iWorkSheet = worksheets->property("Count").toInt();//Excel文件中表的个数

    /***********循环读取出每个sheet中的数据***********/

    QAxObject * worksheet;
    QAxObject * usedrange;
    QAxObject * rows;
    int iRows;
    QAxObject * columns;
    int iColumns;
//    int iStartRow;
//    int iColumn;

    QString ModuleIdStr;
    QString ModuleIdname;
    QString ModuleType;

    QString ApiIdStr;
    QString ApiIdname;
    QString ApiType;

    QString ErrorIdStr;
    QString ErrorIdname;
    QString ErrorType;

    QString ErrorInfo;

    QAxObject *range1;

    QString retStr;


    ui->progressBar_loadspeed->setVisible(true);//下载进度条
    ui->label_loadspeed->setVisible(true);//下载进度信息

    ui->progressBar_loadspeed->setValue(0);
    ui->label_loadspeed->setText("0/"+QString::number(iWorkSheet,10));

    for(int i=1;i<iWorkSheet+1;i++)
    {
        ui->label_loadspeed->setText(QString::number(i,10)+"/"+QString::number(iWorkSheet,10));

        worksheet = worksheets->querySubObject("Item(int)", i);//获取第n个工作表
        ModuleIdname = worksheet->property("Name").toString();  //获取工作表名称
        usedrange = worksheet->querySubObject("UsedRange");//获取该sheet的数据范围（可以理解为有数据的矩形区域

        rows = usedrange->querySubObject("Rows");//获取行数
        iRows = rows->property("Count").toInt();

        columns = usedrange->querySubObject("Columns");//获取列数
        iColumns = columns->property("Count").toInt();

//        iStartRow = rows->property("Row").toInt();//数据的起始行
//        iColumn = columns->property("Column").toInt();//数据的起始列

        ui->progressBar_loadspeed->setMaximum(iRows-2);
        for(int j = 2;j<iRows+1;j++)//读出数据
        {
            ui->progressBar_loadspeed->setValue(j-2);
            range1 = worksheet->querySubObject("Range(QString)", "A"+QString::number(j,10));
            ModuleIdStr = range1->property("Value").toString();

            range1 = worksheet->querySubObject("Range(QString)", "B"+QString::number(j,10));
            ModuleType = range1->property("Value").toString();

            range1 = worksheet->querySubObject("Range(QString)", "C"+QString::number(j,10));
            ApiIdStr = range1->property("Value").toString();

            range1 = worksheet->querySubObject("Range(QString)", "D"+QString::number(j,10));
            ApiIdname = range1->property("Value").toString();

            range1 = worksheet->querySubObject("Range(QString)", "E"+QString::number(j,10));
            ApiType = range1->property("Value").toString();

            range1 = worksheet->querySubObject("Range(QString)", "F"+QString::number(j,10));
            ErrorIdStr = range1->property("Value").toString();

            range1 = worksheet->querySubObject("Range(QString)", "G"+QString::number(j,10));
            ErrorIdname = range1->property("Value").toString();

            range1 = worksheet->querySubObject("Range(QString)", "H"+QString::number(j,10));
            ErrorType = range1->property("Value").toString();

            range1 = worksheet->querySubObject("Range(QString)", "I"+QString::number(j,10));
            ErrorInfo = range1->property("Value").toString();

            bool ok1,ok2,ok3;

            int ModuleId = -1;
            int ApiId = -1;
            int ErrorId = -1;
            QString result1;

            if(ModuleIdStr.toLower().contains("0x"))
            {
                ModuleId = ModuleIdStr.toInt(&ok1,16);
            }
            else
            {
                ModuleId = ModuleIdStr.toInt(&ok1,10);
            }
            if(ApiIdStr.toLower().contains("0x"))
            {
                ApiId = ApiIdStr.toInt(&ok2,16);
            }
            else if(ApiIdStr!="")
            {
                ApiId = ApiIdStr.toInt(&ok2,10);
            }
            if(ErrorIdStr.toLower().contains("0x"))
            {
                ErrorId = ErrorIdStr.toInt(&ok3,16);
            }
            else if(ErrorIdStr!="")
            {
                ErrorId = ErrorIdStr.toInt(&ok3,10);
            }

            if(!ok1)
            {
                result1 = "ModuleId";
            }
            if(!ok2)
            {
                result1 = "ApiId";
            }
            if(!ok3)
            {
                result1 = "ErrorId";
            }
            if((ok1)&&(ok2)&&(ok3))
            {
                retStr = SQLiteInsertData(
                             ModuleId, ModuleIdname, ModuleType,
                             ApiId, ApiIdname, ApiType,
                             ErrorId, ErrorIdname, ErrorType,
                             ErrorInfo
                     );
                if(retStr!="inserted ok!")
                {
                    ui->textEdit_Det_ReportError->append("Row:"+QString::number(j,10)+retStr);
                }
                else
                {
//                    ui->textEdit_Det_ReportError->append("Row:"+QString::number(i,10)+retStr);
                }
            }
            else
            {
                ui->textEdit_Det_ReportError->append("Sheet:"+QString::number(i,10)+"Row:"+QString::number(j,10)+": "+result1+" :Data element format error!");
            }
        }
    }
    ui->textEdit_Det_ReportError->append("ExcelImportFinished!");

    ui->progressBar_loadspeed->setVisible(false);//隐藏下载进度条
    ui->label_loadspeed->setVisible(false);//隐藏下载进度信息

    //!!!!!!!一定要记得close，不然系统进程里会出现n个EXCEL.EXE进程
   workbook->dynamicCall("Close()");
   excel->dynamicCall("Quit()");
   if (excel)
   {
      delete excel;
      excel = NULL;
   }
}

QString MainWindow::SQLiteInsertData(
                            int ModuleId,QString ModuleIdname,QString ModuleType,
                            int ApiId,QString ApiIdname,QString ApiType,
                            int ErrorId,QString ErrorIdname,QString ErrorType,
                            QString ErrorInfo
                         )
{
    QString retStr;
    QSqlQuery sql_query(database);

    QString insert_sql = "insert into Det_ReportError values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    sql_query.prepare(insert_sql);

    sql_query.addBindValue(ModuleId);
    sql_query.addBindValue(ModuleIdname);
    sql_query.addBindValue(ModuleType);

    sql_query.addBindValue(ApiId);
    sql_query.addBindValue(ApiIdname);
    sql_query.addBindValue(ApiType);

    sql_query.addBindValue(ErrorId);
    sql_query.addBindValue(ErrorIdname);
    sql_query.addBindValue(ErrorType);

    sql_query.addBindValue(ErrorInfo);

    if(!sql_query.exec())
    {
        retStr = sql_query.lastError().databaseText();
    }
    else
    {
        retStr = "inserted ok!";
    }

    return retStr;
}

void MainWindow::on_actionConnect_triggered()
{
    if(!isOpen_dialogAboutThisXcan_ui)
    {
        isOpen_dialogAboutThisXcan_ui = true;
        dialogAboutThisXcan_ui = new DialogAboutThisXcan(this);
        dialogAboutThisXcan_ui->setModal(false);
        dialogAboutThisXcan_ui->show();
    }
}
