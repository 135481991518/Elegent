#ifndef REGDIALOG_H
#define REGDIALOG_H

#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class RegDialog;
}

class RegDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegDialog(QWidget *parent = nullptr);
    ~RegDialog();

private slots:
    void on_registerButton_clicked();

private:
    Ui::RegDialog *ui;
    DatabaseManager dbManager;
};

#endif // REGDIALOG_H
