#ifndef DEVICEBINDDIALOG_H
#define DEVICEBINDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <databasemanager.h>
#include <usrdialog.h>

namespace Ui {
class DeviceBindDialog;
}

class DeviceBindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeviceBindDialog(QWidget *parent = nullptr);
    ~DeviceBindDialog();
    void setUsername(const QString &username);

private slots:
    void on_bindButton_clicked();

private:
    Ui::DeviceBindDialog *ui;
    QString username;
};

#endif // DEVICEBINDDIALOG_H
