#ifndef ONLINELOCK_H
#define ONLINELOCK_H

#include <QDialog>
#include "onlinemanager.h"
#include "deviceitem.h"

namespace Ui {
class onlineLock;
}

class onlineLock : public QDialog
{
    Q_OBJECT

public:
    explicit onlineLock(QString username, QWidget *parent = nullptr);
    void setUsername(const QString &username);
    ~onlineLock();

signals:
    void unlockRequested(const QString &key);

private:
    Ui::onlineLock *ui;
    OnlineManager om;
    QString username;
};

#endif // ONLINELOCK_H
