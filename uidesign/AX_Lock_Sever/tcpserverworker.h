// TcpServerThread.h
#ifndef TCPSERVERWORKER_H
#define TCPSERVERWORKER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

class TcpServerWorker : public QObject {
    Q_OBJECT
public:
    explicit TcpServerWorker(QObject *parent = nullptr);
    Q_INVOKABLE bool startServer(quint16 port);
    QTcpSocket* getDeviceSocket(const QString &key) const;
    static TcpServerWorker& getInstance() {
        static TcpServerWorker worker;
        return worker;
    }

signals:
    void sendCommandSignal(const QString &key);

private slots:
    void handleNewConnection();
    void readClientData();
    Q_INVOKABLE void sendCommand(const QString &key);

private:
    QTcpServer *server;
    QMap<QString, QTcpSocket*> deviceSockets;
};

#endif // TCPSERVERWORKER_H
