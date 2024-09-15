#ifndef NETWORKTHREAD_H
#define NETWORKTHREAD_H
#include <QThread>
#include <QTcpSocket>
#include <QTimer>
#include <QDebug>

class NetworkThread : public QThread {
    Q_OBJECT

public:
    NetworkThread(QObject *parent = nullptr) : QThread(parent), socket(new QTcpSocket(this)) {
        connect(socket, &QTcpSocket::connected, this, &NetworkThread::onConnected);
        connect(socket, &QTcpSocket::disconnected, this, &NetworkThread::onDisconnected);
        //connect(socket, &QTcpSocket::error, this, &NetworkThread::onError);

        // 可以设置一个初始连接尝试
        connectToServer();
    }

    ~NetworkThread() {
        socket->disconnectFromHost();
        socket->deleteLater();
    }

protected:
    void run() override {
        // 通常不需要在这里执行太多操作，因为网络IO是异步的
        // 但如果你确实需要在这里执行循环（不推荐），你应该小心处理
        exec(); // 如果你打算使用事件循环（但通常不需要）
    }

private slots:
    void connectToServer() {
        // 设置服务器地址和端口
        socket->connectToHost("example.com", 1234);
        // 可以在这里设置一个QTimer来在连接失败时重试，但通常QTcpSocket会处理重连逻辑（如果启用了）
    }

    void onConnected() {
        qDebug() << "Connected to server!";
        // 连接成功后的处理
    }

    void onDisconnected() {
        qDebug() << "Disconnected from server!";
        // 这里可以设置一个QTimer来在5秒后重连
        QTimer::singleShot(5000, this, &NetworkThread::connectToServer);
    }

    void onError(QAbstractSocket::SocketError error) {
        qDebug() << "Socket error:" << error;
        // 根据错误类型决定是否需要重连
    }

private:
    QTcpSocket *socket;
};

#endif // NETWORKTHREAD_H
