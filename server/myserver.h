#ifndef MYSERVER_H
#define MYSERVER_H
#include <QTcpServer>
#include <QTcpSocket>

#include <QTcpServer>
#include <QTcpSocket>

#include <QSqlDatabase>
#include <QSqlQuery>


class myserver: public QTcpServer
{
    Q_OBJECT
public:
    myserver();
    ~myserver();

    QTcpSocket* socket;
    QByteArray Data;
    QSqlDatabase db;

public slots:
    void startServer();
    //void write_into_db();
    void incomingConnection(int socketDescriptor);
    void sockReady();
    void sockDisc();
};

#endif // MYSERVER_H
