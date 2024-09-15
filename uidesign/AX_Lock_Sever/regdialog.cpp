#include "regdialog.h"
#include "ui_regdialog.h"
#include <QMessageBox>

RegDialog::RegDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegDialog)
{
    ui->setupUi(this);
}

RegDialog::~RegDialog()
{
    delete ui;
}

void RegDialog::on_registerButton_clicked()
{
    QString username = ui->usernameLineEdit->text().trimmed();
    QString password = ui->passwordLineEdit->text().trimmed();
    QString confirmPassword = ui->confirmPasswordLineEdit->text().trimmed();

    if (password != confirmPassword) {
        QMessageBox::warning(this, "注册失败", "两次输入的密码不一致！");
        return;
    }

    // 使用参数化查询来避免SQL注入
    QSqlQuery query(dbManager.getDatabase());
    query.prepare("INSERT INTO user (name, pwd) VALUES (:name, :pwd)");
    query.bindValue(":name", username);
    query.bindValue(":pwd", password);

    if (!query.exec()) {
        QMessageBox::warning(this, "注册失败", "注册时发生错误：" + query.lastError().text());
    } else {
        QMessageBox::information(this, "注册成功", "注册成功，请登录！");
        accept(); // 关闭对话框
    }
}
