#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H


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
};

#endif // DATABASEMANAGER_H
