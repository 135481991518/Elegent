#ifndef LOCKTHREAD_H
#define LOCKTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QTimer>
#include <QDebug>
#include <QMap>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class LockThread : public QThread {
    Q_OBJECT

public:
    explicit LockThread(const QString &serverAddress, quint16 serverPort, QObject *parent = nullptr);
    ~LockThread();// 如果有匹配的记录

    void run() override;

signals:
    void connected();
    void disconnected();
    void connectedToServer();
    void messageReceived(const QString& message);
    void errorOccurred(QAbstractSocket::SocketError socketError);

private slots:
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError error);
    void attemptReconnect();
    void receiveMessage();

private:
    QTcpSocket *socket;
    QString serverAddress;
    quint16 serverPort;
    QTimer *reconnectTimer;
    QTimer *debounceTimer;

    void connectToHost();
};

#endif // LOCKTHREAD_H
