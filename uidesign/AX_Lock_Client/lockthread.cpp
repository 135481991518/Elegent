#include "lockthread.h"

LockThread::LockThread(const QString &serverAddress, quint16 serverPort, QObject *parent)
    : QThread(parent), socket(new QTcpSocket(this)), reconnectTimer(new QTimer(this)) {
    this->serverAddress = serverAddress;
    this->serverPort = serverPort;
    debounceTimer = new QTimer(this);
    debounceTimer->setSingleShot(true); // 设置为单次触发

    connect(socket, &QTcpSocket::connected, this, &LockThread::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &LockThread::onDisconnected);
    connect(socket, static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketError)>(&QTcpSocket::error),
            this, &LockThread::onError);
    connect(reconnectTimer, &QTimer::timeout, this, &LockThread::attemptReconnect);
    connect(socket, &QTcpSocket::readyRead, this, &LockThread::receiveMessage, Qt::QueuedConnection);

    // 初始连接尝试
    connectToHost();
}

LockThread::~LockThread() {
    socket->disconnectFromHost();
    socket->deleteLater();
    reconnectTimer->stop();
    reconnectTimer->deleteLater();
    wait();
}

void LockThread::run() {
    exec(); // 启动事件循环
}

void LockThread::onConnected() {
    qDebug() << "Connected to server!";
    reconnectTimer->stop(); // 停止重连计时器
    QByteArray deviceId = "12345678";
    qDebug() << "write to server!";
    socket->write(deviceId.constData(), deviceId.size());
    socket->flush(); // 确保数据被发送出去
    emit connected();
    emit connectedToServer();
}

void LockThread::onDisconnected() {
    qDebug() << "Disconnected from server, attempting to reconnect...";
    // 如果不是由我们主动断开连接，则尝试重连
    //if (socket->state() != QAbstractSocket::UnconnectedState) {
        reconnectTimer->start(10000); // 设置5秒后重连
    //}
    emit disconnected();
}

void LockThread::onError(QAbstractSocket::SocketError socketError) {
    qDebug() << "Socket error:" << socket->errorString();
    emit errorOccurred(socketError);
    //if (socket->state() != QAbstractSocket::UnconnectedState) {
        reconnectTimer->start(10000); // 设置5秒后重连
    //}
    emit disconnected();
}

void LockThread::attemptReconnect() {
    connectToHost();
}

void LockThread::receiveMessage()
{
    if (debounceTimer->isActive()) {
       return;
    }
    debounceTimer->start(500); // 设置500毫秒的超时时间
    if (!socket->isOpen()) {
        return;
    }

    QString message = socket->readAll();
    qDebug() << message;
    emit messageReceived(message);
}

void LockThread::connectToHost() {
    //setSignRed();
    socket->connectToHost(serverAddress, serverPort);
}
