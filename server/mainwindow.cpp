#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileDialog>
#include <QPixmap>
#include <QFileInfo>
#include <QDateTime>
#include <QWidget>
#include <QSize>
#include <QBitmap>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
