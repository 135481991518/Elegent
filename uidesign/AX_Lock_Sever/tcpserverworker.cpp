#include "tcpserverworker.h"
#include <QDebug>
#include "databasemanager.h"
#include "QMessageBox"

TcpServerWorker::TcpServerWorker(QObject *parent) : QObject(parent), server(new QTcpServer(this)) {
    connect(server, &QTcpServer::newConnection, this, &TcpServerWorker::handleNewConnection);
     connect(this, &TcpServerWorker::sendCommandSignal, this, &TcpServerWorker::sendCommand);
}

bool TcpServerWorker::startServer(quint16 port) {
    if (!server->listen(QHostAddress::Any, port)) {
        qDebug() << "Server could not start on port" << port;
        return false;
    }
    qDebug() << "Server started on port" << port;
    return true;
}

void TcpServerWorker::handleNewConnection() {
    QTcpSocket *clientSocket = server->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, [this, clientSocket]() {
        QByteArray data = clientSocket->readAll();
        qDebug() << "Received message from client:" << data;
        QString deviceId = data;
        if (!deviceId.isEmpty()) {
            deviceSockets[deviceId] = clientSocket;
            //设置数据库登录
            QString queryText = QString("UPDATE user_device_link SET state = 1  WHERE device_id = '%1'").arg(deviceId);

            // 获取数据库实例并执行查询
            QSqlDatabase db = DatabaseManager::getInstance().getDatabase();
            QSqlQuery query(db);
            query.prepare(queryText);
            if (query.exec()) {
                QMessageBox::information(nullptr, "设备激活", "设备"+deviceId+"激活成功！");
            } else {
                // 登录失败，显示错误消息
                QMessageBox::warning(nullptr, "设备激活", "设备"+deviceId+"激活错误！");
            }

            // 送欢迎消息或确认
            clientSocket->write("Welcome, device " + deviceId.toUtf8() + "\n");
        }
        qDebug() << "finish";

    });

    connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
    connect(clientSocket, &QTcpSocket::disconnected, this, [this, clientSocket]() {
        QString deviceId;
        // 从设备映射中移除已断开连接的socket
        for (auto it = deviceSockets.begin(); it != deviceSockets.end(); ) {
            if (it.value() == clientSocket) {
                deviceId = it.key();
               it = deviceSockets.erase(it);
               break;
            }
            ++it;
        }
        QString queryText = QString("UPDATE user_device_link SET state = 0  WHERE device_id = '%1'").arg(deviceId);

        // 获取数据库实例并执行查询
        QSqlDatabase db = DatabaseManager::getInstance().getDatabase();
        QSqlQuery query(db);
        query.prepare(queryText);
        if (query.exec()) {
            QMessageBox::information(nullptr, "设备离线", "设备"+deviceId+"离线处理完成！");
        } else {
            // 登录失败，显示错误消息
            QMessageBox::warning(nullptr, "设备离线", "设备"+deviceId+"离线处理异常！");
        }
     });
}

QTcpSocket* TcpServerWorker::getDeviceSocket(const QString &key) const {
    qDebug() << "Looking for key:" << key;
    QTcpSocket* socket = deviceSockets.value(key);
    if (socket) {
        qDebug() << "Found socket for key:" << key;
    } else {
        qDebug() << "No socket found for key:"  << key;
    }
    return socket;
}

void TcpServerWorker::sendCommand(const QString &key){
    qDebug() << deviceSockets[key];
    QTcpSocket* socket = getDeviceSocket(key);
    if (socket) {
        // 发送 "Unlock" 消息
        QByteArray unlockMessage = "Unlock";
        if (socket->state() == QTcpSocket::ConnectedState) {
            if (socket->write(unlockMessage) > 0) {
                socket->flush();
                qDebug() << "Message sent successfully";
            } else {
                qDebug() << "Failed to write message to socket. Error:" << socket->errorString();
            }
        } else {
            qDebug() << "Socket is not connected.";
        }
    } else {
        qDebug() << "No socket found for device ID:" << key;
    }
    QTimer::singleShot(5000, this, [=]() {

    });
    //return socket != nullptr;
}

void TcpServerWorker::readClientData()
{

}

