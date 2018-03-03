#include "databasemanager.h"

#include <QMutexLocker>
#include <QMessageBox>

DataBaseManager * DataBaseManager::_pInstance = nullptr;

DataBaseManager::DataBaseManager()
{

}

DataBaseManager *DataBaseManager::getInstance()
{
    QMutex mutex;
    QMutexLocker loker(&mutex);

    if(nullptr == _pInstance)
    {
        _pInstance = new DataBaseManager;
    }
    return _pInstance;
}

bool DataBaseManager::createConnection()
{
    _connection = QSqlDatabase::addDatabase("QSQLITE");
    _connection.setDatabaseName("SwimRecord.db");
    if(false == _connection.open())
    {
        QMessageBox::critical(nullptr, "Cannot open database",
                              _connection.lastError().text());
        return false;
    }

    return true;
}

bool DataBaseManager::closeConnection()
{
    if(_connection.isOpen())
    {
        _connection.close();
    }
    return true;
}

QSqlDatabase DataBaseManager::getConnection()
{
    return _connection;
}

bool DataBaseManager::transaction()
{
    bool flag = _connection.transaction();
    return flag;
}

bool DataBaseManager::commit()
{
    bool flag = _connection.commit();
    return flag;
}

bool DataBaseManager::rollback()
{
    bool flag = _connection.rollback();
    return flag;
}
