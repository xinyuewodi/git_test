#include "databasemanager.h"

#include <QMutexLocker>

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
    return true;
}

bool DataBaseManager::closeConnection()
{
    return true;
}

bool DataBaseManager::transaction()
{
    return true;
}

bool DataBaseManager::commit()
{
    return true;
}

bool DataBaseManager::rollback()
{
    return true;
}
