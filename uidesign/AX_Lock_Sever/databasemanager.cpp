#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mydemo");
    db.setUserName("root");
    db.setPassword("123456");

    if (!db.open()) {
        qDebug() << "Error: Connection with database failed: " << db.lastError().text();
    }
}

DatabaseManager::~DatabaseManager()
{
    db.close();
}

QSqlDatabase &DatabaseManager::getDatabase()
{
    return db;
}

QSqlQuery DatabaseManager::executeQuery(const QString &queryText)
{
    QSqlQuery query(db);
    if (!query.prepare(queryText)) {
        qDebug() << "Failed to prepare query:" << queryText;
        return query; // Returning an invalid query object
    }

    if (!query.exec()) {
        qDebug() << "Failed to execute query:" << queryText << ":" << query.lastError().text();
    }

    return query;
}


