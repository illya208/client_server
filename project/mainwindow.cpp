#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include <QFileInfo>
#include <QDateTime>
#include <QWidget>
#include <QSize>
#include <QBitmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket= new QTcpSocket(this);
    connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
    connect(socket,SIGNAL(disconected()),this,SLOT(sockDics()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString fileNamePath;
void MainWindow::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "D:\\",
                                                      tr("All files(*.*)"));
    fileNamePath=fileName;


    QFile File(fileName);
    QString str = fileName.section('/', -1);
    ui->label_3->setText(str);
    QFileInfo file_info(fileName);
    QDateTime ddd=file_info.lastRead();
    QString str2=ddd.toString("dd/MM/yy");
    ui->label_4->setText(str2);


   //add dynamic

    QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
    ui->listWidget->addItem (listWidgetItem);

    WidgetItem *theWidgetItem = new WidgetItem;
    QString filename=str;
    qDebug()<<"str="+str;
    qDebug()<<"filename="+filename;
    qDebug()<<"fileName="+  fileName;

    theWidgetItem->setfile_name(filename);
    QString date=str2;
    theWidgetItem->setfile_date(date);
    QString str_file_type = fileName.section('.', -1);
     qDebug()<<"&&&&item"+str_file_type;
     if(str_file_type=="txt"){
           theWidgetItem->setfile_image("C:\\Users\\illya\\Documents\\project\\txt_icon.png");
     }
     else if (str_file_type=="pdf") {
           theWidgetItem->setfile_image("C:\\Users\\illya\\Documents\\project\\pdf_icon.png");
     }
     else if (str_file_type=="doc"||str_file_type=="docx") {
           theWidgetItem->setfile_image("C:\\Users\\illya\\Documents\\project\\doc_icon.png");
     }
     else if (str_file_type=="jpg") {
           theWidgetItem->setfile_image("C:\\Users\\illya\\Documents\\project\\jpg_icon.png");
     }
     else if (str_file_type=="png") {
           theWidgetItem->setfile_image("C:\\Users\\illya\\Documents\\project\\png_icon.png");
     }
     else {
          theWidgetItem->setfile_image("C:\\Users\\illya\\Documents\\project\\doc.png");
     }


    listWidgetItem->setSizeHint (theWidgetItem->size());
    ui->listWidget->setItemWidget (listWidgetItem, theWidgetItem);

    qDebug()<<"item";


}

void MainWindow::on_pushButton_5_clicked()
{
     QListWidgetItem *theWidgetItem1= ui->listWidget->currentItem();
    // theWidgetItem1->it;
     QListWidget *s=theWidgetItem1->listWidget();
     /* WidgetItem *widget = dynamic_cast<WidgetItem *>(ui->listWidget->currentItem());
      QString nameproba=  widget->get_file_name();
       qDebug()<<"!!!!!"+nameproba;*/
    WidgetItem *widget = qobject_cast<WidgetItem *>(s->itemWidget(s->currentItem()));
    QString nameproba=  widget->get_file_name();
     qDebug()<<"!!!!!"+nameproba;
socket->connectToHost("127.0.0.1",5555);
qDebug()<<"connected to server";
//QString filename= ui->label_3->text();
qDebug()<<fileNamePath;
// send file HERE
QByteArray block;
   QDataStream out(&block, QIODevice::WriteOnly);
   out.setVersion(QDataStream::Qt_5_4);

   // This part i  need to send not only file, but file name too

     QString str = fileNamePath.section('/', -1);
     qDebug()<<"sended file name "<<str;
   out  << str;


QFile file(fileNamePath);
file.open(QIODevice::ReadOnly);
QByteArray q = file.readAll();
block.append(q);
socket->write(block);
qDebug()<<block;

//end sending file
//socket->write(fileNamePath);
}

void MainWindow::on_pushButton_6_clicked()
{
//add widget
   QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
   ui->listWidget->addItem (listWidgetItem);
   WidgetItem *theWidgetItem = new WidgetItem;
   QString filename;
   theWidgetItem->setfile_name(filename);
   QString date;
   theWidgetItem->setfile_date(date);


   listWidgetItem->setSizeHint (theWidgetItem->size());
   ui->listWidget->setItemWidget (listWidgetItem, theWidgetItem);

   qDebug()<<"item";

}

void MainWindow::sockDisk(){
    socket->deleteLater();
}
void MainWindow::sockReady(){
     qDebug()<<"Data reading";
    if(socket->waitForConnected(500)){
        socket->waitForReadyRead(500);
        Data=socket->readAll();
        qDebug()<<Data;
          qDebug()<<"Data reading";
    }
}

void MainWindow::on_pushButton_7_clicked()
{
     delete ui->listWidget->currentItem ();
}
