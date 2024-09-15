#include "onlinelock.h"
#include "ui_onlinelock.h"
#include "tcpserverworker.h"

onlineLock::onlineLock(QString username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::onlineLock)
{
    ui->setupUi(this);
    QVariantList deviceIds = om.fetchActiveDeviceIds(username);
    ui->listWidget->clear();
    for (const QVariant &deviceId : deviceIds) {
        DeviceItem *item = new DeviceItem(deviceId.toString(), ui->listWidget);
        connect(item, &DeviceItem::unlockRequested, this, [=](const QString &id) {

            TcpServerWorker &mytcpthread = TcpServerWorker::getInstance();
            QObject::connect(this, &onlineLock::unlockRequested, &mytcpthread, &TcpServerWorker::sendCommandSignal);
            // 发送命令
            emit unlockRequested(id);
            qDebug() << "Unlock requested for:" << id;
//            if(mytcpthread.sendCommand(id)){
//               qDebug() << "Unlock requested for:" << id;
//            }else{
//                qDebug() << "error requested for:" << id;
//            }
            QTimer::singleShot(5000, this, [=]() {

            });

        });
        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
        ui->listWidget->addItem(listWidgetItem);
        ui->listWidget->setItemWidget(listWidgetItem, item);
    }
    ui->listWidget->setSpacing(15);
    ui->listWidget->setUniformItemSizes(false);
}

onlineLock::~onlineLock()
{
    delete ui;
}

void onlineLock::setUsername(const QString &username)
{
    this->username = username;
}
