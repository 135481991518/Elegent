#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置tcp连接，轮询连接服务器
    LockThread *thread = new LockThread("127.0.0.1", 1234);
    QObject::connect(thread, &LockThread::connected, []() {
        qDebug() << "Received connected signal in main thread.";
    });
    QObject::connect(thread, &LockThread::disconnected, []() {
        qDebug() << "Received disconnected signal in main thread.";
    });
    QObject::connect(thread, &LockThread::errorOccurred, [](QAbstractSocket::SocketError error) {
        qDebug() << "Error occurred in LockThread:" << error;
    });
    thread->start();
    connect(thread, &LockThread::connectedToServer, this, &MainWindow::GreenLight);
    connect(thread, &LockThread::disconnected, this, &MainWindow::YellowLight);
    connect(thread, &LockThread::messageReceived, this, &MainWindow::handleMessage);

    //设置按钮
    connectButtons();
    ui->lineEdit->setReadOnly(true); // 设置为只读
    connect(ui->BackButton, &QPushButton::clicked, this, &MainWindow::onBackButtonClicked);
    QTimer *longPressTimer = new QTimer(this);
            longPressTimer->setSingleShot(true); // 设置定时器为单次触发
            longPressTimer->setInterval(1000); // 设置长按时间为500毫秒

    // 连接信号和槽
    connect(ui->LockButton, &QPushButton::pressed, this, [this, longPressTimer]() {
        longPressTimer->start(); // 按钮被按下时启动定时器
        longPressDetected = false; // 重置长按检测标志
    });
    connect(ui->LockButton, &QPushButton::released, this, [this, longPressTimer]() {
        if (longPressTimer->isActive()) {
            // 如果定时器仍然激活，说明还没有达到长按时间，但我们要停止它，因为按钮已经被释放
            longPressTimer->stop();
            qDebug() << "Short press detected!";
        } else {
            // 如果定时器不激活，说明按钮被快速释放，执行短按逻辑
            if (!longPressDetected) {
                qDebug() << "Short press detected!";
                // 处理短按逻辑
            }
        }
    });
    connect(longPressTimer, &QTimer::timeout, this, [this]() {
        // 定时器超时，视为长按
        qDebug() << "Long press detected!";
        longPressDetected = true; // 设置长按检测标志
        // 处理长按逻辑
        QIcon FaceRecognitionIcon(":/icon/facerecognition.png"); // 使用资源文件路径或文件路径
        ui->LockButton->setIcon(FaceRecognitionIcon);
        FaceRecognition();
        QTimer::singleShot(5000, this, [=]() {
            // 这里写你的代码
            QIcon ButtonIcon(":/icon/Button1.png");
            ui->LockButton->setIcon(ButtonIcon);
            ui->lineEdit->setText("");
        });
    });

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleMessage(const QString &message)
{
    if (message == "Unlock") {
        ui->LockLight->setStyleSheet("background-color: green;border-radius:10px;border:2px groove gray;border-style:outset;");
        QTimer::singleShot(5000, this, [=]() {
            ui->LockLight->setStyleSheet("background-color: red;border-radius:10px;border:2px groove gray;border-style:outset;");
        });
    }

}


void MainWindow::FaceRecognition()
{
    QLineEdit *status = findChild<QLineEdit *>("lineEdit"); // 注意：这里需要根据实际布局调整查找方式
    if (status) {
        status->setText(tr("门锁状态：人脸识别成功，已解锁"));
    }
    //显示灯提示
    ui->LockLight->setStyleSheet("background-color: green;border-radius:10px;border:2px groove gray;border-style:outset;");
    QTimer::singleShot(5000, this, [=]() {
        ui->LockLight->setStyleSheet("background-color: red;border-radius:10px;border:2px groove gray;border-style:outset;");
    });
}

void MainWindow::GreenLight()
{
    qDebug() << "turn green";
    ui->ConnectLight->setStyleSheet("background-color: green;border-radius:10px;border:2px groove gray;border-style:outset;");
}

void MainWindow::YellowLight()
{
     qDebug() << "turn yellow";
     ui->ConnectLight->setStyleSheet("background-color: yellow;border-radius:10px;border:2px groove gray;border-style:outset;");
}

void MainWindow::connectButtons()
{
    for (int i = 0; i <= 10; ++i) {
        QPushButton *button = this->findChild<QPushButton *>("Button_" + QString::number(i));
        if (button) {
            connect(button, &QPushButton::clicked, [this, i]() {
                this->on_Button_Clicked(i);
            });
        }
    }
}

void MainWindow::on_Button_Clicked(int number)
{
    if(number == 10)
        ui->lineEdit->setText("");
    else
        ui->lineEdit->setText(ui->lineEdit->text() + QString::number(number)); // 假设你的QLineEdit对象名为lineEdit
}

void MainWindow::onBackButtonClicked()
{
    QString tmp = ui->lineEdit->text();
    tmp.remove(tmp.size()-1, 1);
    ui->lineEdit->setText(tmp);
}
