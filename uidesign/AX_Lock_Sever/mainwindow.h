#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <memory>
#include <QString>
#include "devicebinddialog.h"
#include "tcpserverworker.h"
#include "onlinelock.h"
#include "deviceitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUsername(const QString &username);

private slots:
    void on_DeviceBindButton_clicked();
    void on_onlinelockButton_clicked();
    void on_newDataReceived(const QString &deviceId);

private:
    Ui::MainWindow *ui;
    QString username;
};
#endif // MAINWINDOW_H
