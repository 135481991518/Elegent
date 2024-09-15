#ifndef USERMANGER_H
#define USERMANGER_H
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <memory>
#include "databasemanager.h"
#include "PasswordHash.h" // 引入假设的 PasswordHash 类

class UserManager
{    
public:
    std::unique_ptr<DatabaseManager> dbManager;
    UserManager();
    bool authenticateUser(const QString &username, const QString &password);
    bool registerUser(const QString &username, const QString &password);

};

#endif // USERMANGER_H
