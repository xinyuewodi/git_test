#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlIndex>
#include <QSqlError>


class DataBaseManager
{
private:
    DataBaseManager();
    static DataBaseManager *_pInstance;
public:
    static DataBaseManager* getInstance();

    bool createConnection();
    bool closeConnection();

    bool transaction();
    bool commit();
    bool rollback();

private:
    QSqlDatabase _connection;
};

#endif // DATABASEMANAGER_H
