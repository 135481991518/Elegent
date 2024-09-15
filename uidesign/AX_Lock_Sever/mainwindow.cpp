#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "usrdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet(R"(
        QPushButton {
            border: 1px solid #ccc;
            border-radius: 5px;
            padding: 5px;
            background-color: #f0f0f0;
        }

        QPushButton:hover {
            background-color: #e0e0e0;
        }

        QPushButton:pressed {
            background-color: #d0d0d0;
        }

        QToolButton {
            icon-size: 24px; /* 设置图标大小 */
            padding: 5px; /* 设置按钮内边距 */
        }

        QToolButton:hover {
            background-color: #e0e0e0; /* 鼠标悬停时的背景颜色 */
            color: #0000ff; /* 鼠标悬停时的图标颜色 */
        }
     )");

    QThread *thread = new QThread;
    TcpServerWorker &worker = TcpServerWorker::getInstance();
    worker.moveToThread(thread);
    QObject::connect(thread, &QThread::started, [&worker]() {
        worker.startServer(1234);
    });

    thread->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setUsername(const QString &username)
{
    this->username = username;
    //ui->usernameLabel->setText("hello, " + username); // 更新UI中的标签
}

void MainWindow::on_DeviceBindButton_clicked()
{
    // 这里实现设备绑定的逻辑
    DeviceBindDialog dialog(this); // 创建设备绑定对话框，将MainWindow作为其父窗口
    dialog.setUsername(username);
    if (dialog.exec() == QDialog::Accepted) {
        QMessageBox::information(this, "绑定成功", "设备已成功绑定！");
    }
}

void MainWindow::on_onlinelockButton_clicked()
{
    // 这里实现设备绑定的逻辑
    onlineLock ol(username,this); // 创建设备绑定对话框，将MainWindow作为其父窗口
    ol.setUsername(username);
    ol.exec();
}

void MainWindow::on_newDataReceived(const QString& deviceId)
{

//    // 考虑极端情况
//    if(NULL == username || NULL == deviceId)
//    {
//        return;
//    }
//    // 数据库查询
//    QString strQuery = QString("select * from userInfo where user_id = \'%1\' and device_id = \'%2\' "
//                               "and state = 0").arg(username).arg(deviceId); // online = 0 可以判定用户是否未登录，不允许重复登陆
//    qDebug() << strQuery;
//    QSqlDatabase db = DatabaseManager::getInstance().getDatabase(); // 假设这个方法返回QSqlDatabase
//    QSqlQuery query(db);
//    query.exec(strQuery);

//    if(query.next()) // 每次调用next都会读取一条数据，并将结果放入query中，返回值为true，无数据则返回false
//    {
//        strQuery = QString("update userInfo set state = 1 where user_id = \'%1\' and device_id = \'%2\' ").arg(username).arg(deviceId);
//    }
//    else
//    {
//        qDebug() << "设备连接异常:" + deviceId;
//    }

}
