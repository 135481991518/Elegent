#include "usermanager.h"

UserManager(const QString &hostName, const QString &databaseName, const QString &userName, const QString &password)
        : dbManager(std::unique_ptr<DatabaseManager>(new DatabaseManager(hostName, databaseName, userName, password))) {}

bool UserManager::authenticateUser(const QString &username, const QString &password)
{
    // 这里应该使用密码的哈希值进行比较
    QSqlQuery query = dbManager->executeQuery("SELECT Password FROM Users WHERE Username = :username");
    if (!query.exec("SELECT Password FROM Users WHERE Username = '" + username + "'")) {
        return false;
    }
    if (query.next()) {
        // 假设这里直接比较明文密码（实际中应避免）
        return query.value(0).toString() == password;
    }
    return false;
}

bool UserManager::registerUser(const QString &username, const QString &password)
{
    QString hashedPassword = PasswordHash::hashPassword(password);
    QSqlQuery query = dbManager->executeQuery("INSERT INTO Users (Username, Password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", hashedPassword);
    if (!query.exec()) {
            return false;
    }

    return query.numRowsAffected() > 0;
}

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
