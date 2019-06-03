#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDebug>
#include "widgetitem.h"
#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QtDebug>
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTcpSocket* socket;
    QByteArray Data;


private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void sockReady();
    void sockDisk();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
