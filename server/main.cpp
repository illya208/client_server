#include "mainwindow.h"
#include <QApplication>
#include "myserver.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    myserver Server;
      Server.startServer();
    return a.exec();
}
