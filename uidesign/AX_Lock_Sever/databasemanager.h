#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QtDebug>
#include <QSqlQuery>

class DatabaseManager {
public:
    DatabaseManager();

    ~DatabaseManager();

    QSqlDatabase& getDatabase();
    QSqlQuery executeQuery(const QString &queryText);

    static DatabaseManager& getInstance() {
        static DatabaseManager instance;
        return instance;
    }

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
