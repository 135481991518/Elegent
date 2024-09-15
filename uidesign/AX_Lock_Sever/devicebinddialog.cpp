#include "devicebinddialog.h"
#include "ui_devicebinddialog.h"

DeviceBindDialog::DeviceBindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceBindDialog)
{
    ui->setupUi(this);
}

DeviceBindDialog::~DeviceBindDialog()
{
    delete ui;
}

void DeviceBindDialog::setUsername(const QString &username)
{
    this->username = username;
}

void DeviceBindDialog::on_bindButton_clicked()
{
    QString device_id = ui->DeviceIdLineEdit->text();
    QString user_id = username;

    if (device_id.isEmpty() || user_id.isEmpty()) {
        QMessageBox::warning(this, "绑定失败", "设备ID或用户ID不能为空！");
        return;
    }

    // 构造SQL插入语句
    QString insertQuery = "INSERT INTO user_device_link (user_id, device_id) VALUES (?, ?)";

    // 获取数据库实例并准备查询
    QSqlDatabase db = DatabaseManager::getInstance().getDatabase(); // 假设这个方法返回QSqlDatabase
    QSqlQuery query(db);
    query.prepare(insertQuery);

    // 绑定参数
    query.bindValue(0, user_id);
    query.bindValue(1, device_id);

    if (query.exec()) {
        accept(); // 如果需要关闭对话框
    } else {
        QMessageBox::warning(this, "绑定失败", "无法将设备绑定到"+ username + "，请重试！");
        qDebug() << query.lastError().text();
    }
}

