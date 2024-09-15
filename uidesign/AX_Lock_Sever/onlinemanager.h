#ifndef ONLINEMANAGER_H
#define ONLINEMANAGER_H
#include <QSqlQuery>
#include <QVariantList>
#include <QDebug>
#include "databasemanager.h"

class OnlineManager
{
public:
    OnlineManager();
    ~OnlineManager();
    QVariantList fetchActiveDeviceIds(QString username);

private:
    QSqlDatabase db;
};

#endif // ONLINEMANAGER_H
