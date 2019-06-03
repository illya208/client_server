#include "myserver.h"
#include "mainwindow.h"
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
myserver::myserver(){}

myserver::~myserver(){}

void myserver::startServer()
{
    if (this->listen(QHostAddress::Any,5555))
    {
        db=QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("D:\\SQLiteDatabaseBrowserPortable\\Data\\files.db");
        if(db.open()){
            qDebug()<<"Listening and DB open";
        }
        else {
            qDebug()<<"DB not open";
        }

        //add to lsit






    }
    else
    {
        qDebug()<<"Not listening";
    }
}

void myserver::incomingConnection(int socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisc()));

    qDebug()<<socketDescriptor<<" Client connected";

    socket->write("You are connect");

    qDebug()<<"Send client connect status - YES";
}

void write_into_db( QByteArray line2 ){
    QSqlDatabase db;
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\SQLiteDatabaseBrowserPortable\\Data\\files.db");
    if(db.open()){
        qDebug()<<"Listening and DB open";
    }
    qDebug() << "in writing to db!";

    QString user_name = "illya";
     QSqlQuery query = QSqlQuery( db );
      qDebug() << "Finished!";
   query.prepare( "INSERT INTO filelist (name, date, file) VALUES (\"illya\", \"02.11.2011\",:imageData)" );
    qDebug() << "Finished!";
     query.bindValue( ":imageData", line2 );
      qDebug() << "Finished!4";
      if( !query.exec() ){
          qDebug() << "Error inserting image into table:\n" ;
      }
}




void myserver::sockReady()
{
// ACCEPT file HERE
    qint32      m_blockSize;
    QDataStream in(socket);

    in.setVersion(QDataStream::Qt_5_4);
    if (m_blockSize == 0) {
           if (socket->bytesAvailable() < sizeof(quint32))
           return;
           in >> m_blockSize;
       }
       if (socket->bytesAvailable() < m_blockSize)
           return;


    QString fileName;
       // get sending file name
       in >> fileName;
    QByteArray line = socket->readAll();

    QFile target;
    target.setFileName("C:/Users/illya/Documents/server/files/" + fileName);

 qDebug() <<"C:/Users/illya/Documents/server/files/" + fileName;
    if (!target.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << "Can't open file for written";
        return;
    }
    target.write(line);

    target.close();

    qDebug() << "file size: " << target.size();

    qDebug() << "Finished!";

    write_into_db(line);



}

void myserver::sockDisc()
{
    qDebug()<<"Disconnect";
    socket->deleteLater();
}
