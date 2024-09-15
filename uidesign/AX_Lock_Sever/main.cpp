#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "usrdialog.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString username;
    UsrDialog UsrDialog; // 创建登录对话框实例，没有指定父窗口
    if (UsrDialog.exec() == QDialog::Accepted && UsrDialog.getUsername(username)) { // 显示对话框并尝试登录
        // 登录成功
        QMessageBox::information(nullptr, "欢迎", "欢迎，" + username + "！");
        MainWindow w;
        w.setUsername(username);
        w.show();
        return a.exec(); // 只有在登录成功后才进入事件循环
    } else {
        // 登录失败
        QMessageBox::warning(nullptr, "程序启动", "登录失败，程序将退出。");
        return -1; // 直接退出程序
    }
    return 0;
}
