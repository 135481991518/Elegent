#ifndef USRDIALOG_H
#define USRDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <regdialog.h>

namespace Ui {
class UsrDialog;
}

class UsrDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UsrDialog(QWidget *parent = nullptr);
    ~UsrDialog();

    bool login(QString &username);
    bool getUsername(QString &username);

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();

private:
    Ui::UsrDialog *ui;
};

#endif // USRDIALOG_H
