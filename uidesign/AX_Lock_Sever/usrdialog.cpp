#include "usrdialog.h"
#include "ui_usrdialog.h"
#include <databasemanager.h>

UsrDialog::UsrDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsrDialog)
{
    ui->setupUi(this);
    this->setStyleSheet(R"(
        QDialog {
            background-color: #f0f0f0; /* 背景色 */
            border: 2px solid #d0d0d0; /* 边框 */
            border-radius: 5px; /* 边框圆角 */
            padding: 10px; /* 内边距 */
        }

        QLineEdit {
            background-color: white; /* 输入框背景色 */
            border: 1px solid #cccccc; /* 输入框边框 */
            border-radius: 3px; /* 输入框边框圆角 */
            padding: 5px; /* 输入框内边距 */
        }

        QPushButton {
            background-color: #4CAF50; /* 按钮背景色 */
            color: white; /* 按钮文字颜色 */
            border: none; /* 无边框 */
            border-radius: 3px; /* 按钮边框圆角 */
            padding: 5px 15px; /* 按钮内边距，包括水平和垂直 */
            font-size: 16px; /* 字体大小 */
        }

        QPushButton:hover {
            background-color: #45a049; /* 鼠标悬停时的背景色 */
        }

        QPushButton:pressed {
            background-color: #388E3C; /* 按钮被按下时的背景色 */
        }
        )");
}

UsrDialog::~UsrDialog()
{
    delete ui;
}

bool UsrDialog::login(QString &username)
{
    if (exec() == QDialog::Accepted) { // 显示对话框并等待用户关闭
            username = ui->usernameLineEdit->text(); // 获取用户名
            return true; // 登录成功
        }
    return false; // 登录失败
}

bool UsrDialog::getUsername(QString &username)
{
    username = ui->usernameLineEdit->text().trimmed();
    return !username.isEmpty();
}

void UsrDialog::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    // 构造SQL查询
    QString queryText = QString("SELECT * FROM user WHERE name = '%1' AND pwd = '%2'").arg(username).arg(password);

    // 获取数据库实例并执行查询
    DatabaseManager dbManager;
    QSqlQuery query = dbManager.executeQuery(queryText);

    // 检查查询结果
    if (query.next()) {
        // 登录成功，可以关闭对话框或执行其他操作
        accept(); // 关闭对话框，并返回Accepted
    } else {
        // 登录失败，显示错误消息
        QMessageBox::warning(this, "登录失败", "账户或密码错误！");
    }
}

void UsrDialog::on_registerButton_clicked() // 假设你在UsrDialog中也有一个注册按钮
{
    RegDialog regDialog(this); // 父对象设置为this，以便RegDialog在UsrDialog之前关闭
    regDialog.exec(); // 显示RegDialog并等待用户关闭
}


