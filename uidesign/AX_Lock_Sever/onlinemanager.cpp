#include "onlinemanager.h"

OnlineManager::OnlineManager()
{

}

OnlineManager::~OnlineManager()
{

}

QVariantList OnlineManager::fetchActiveDeviceIds(QString username) {
    QVariantList deviceIds;
    db = DatabaseManager::getInstance().getDatabase(); // 假设这个方法返回QSqlDatabase
    QSqlQuery query(db);
    query.prepare("SELECT device_id FROM user_device_link WHERE state = 1 AND user_id = :username");

    // 绑定username参数
    query.bindValue(":username", username);

    if (!query.exec()) {
        qDebug() << "Query failed: " << query.lastError().text();
        return deviceIds;
    }

    while (query.next()) {
        deviceIds.append(query.value(0));
    }

    return deviceIds;
}
