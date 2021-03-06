#include "swimrecordtablemanager.h"

SwimRecordTableManager::SwimRecordTableManager()
{
    _pManager = DataBaseManager::getInstance();
}

bool SwimRecordTableManager::creatTable()
{
    QString create_sql = "create table if not exists 'SwimRecordTable'"
                         "(Id integer primary key autoincrement,"
                         "TotalLapCount integer NOT NULL,"
                         "TotalTimeCost TIME NOT NULL,"
                         "AvgTimeCost TIME,"
                         "FastestLap NVARCHAR(10),"
                         "FLapTimeCost TIME,"
                         "SlowestLap NVARCHAR(10),"
                         "SLapTimeCost TIME,"
                         "Date DATE NOT NULL)";

    QSqlQuery query(_pManager->getConnection());
    query.prepare(create_sql);

    bool flag = query.exec();
    if(false == flag)
    {
        qDebug() << "SwimRecordTableManager::creatTable"<<query.lastError();
    }
    return flag;
}

bool SwimRecordTableManager::appendRecord(SwimRecord &record)
{
    if(0 >= record.totalLap || QTime(0,0) == record.totalTime)
    {
        qDebug() << "total lap or total time is zero!";
        return false;
    }

    QString append_sql = "insert into SwimRecordTable"
                         " values(?,?,?,?,?,?,?,?)";
    QSqlQuery query(_pManager->getConnection());
    query.prepare(append_sql);
    query.addBindValue(record.totalLap);
    query.addBindValue(record.totalTime);
    query.addBindValue(record.avgTime);
    query.addBindValue(record.FastestLapNum);
    query.addBindValue(record.FLapTimeCost);
    query.addBindValue(record.SLowestLapNum);
    query.addBindValue(record.SLapTimeCost);
    query.addBindValue(record.date);

    bool flag = query.exec();
    if(false == flag)
    {
        qDebug() << "SwimRecordTableManager::appendRecord:"<< query.lastError();
    }

    record.id = query.lastInsertId().toInt();

    return flag;
}

bool SwimRecordTableManager::removeRecord(int id)
{
    if(0 >= id)
        return false;

    QString remove_sql = "delete from SwimRecordTable where Id=?";
    QSqlQuery query(_pManager->getConnection());
    query.prepare(remove_sql);
    query.addBindValue(id);

    bool flag = query.exec();
    if(false == flag)
    {
        qDebug() << "SwimRecordTableManager::removeRecord:"<< query.lastError();
    }

    return flag;
}

bool SwimRecordTableManager::getRecord(int id, SwimRecord &record)
{
    if(0 >= id)
        return false;

    QString select_sql = "select * from SwimRecordTable where Id=?";
    QSqlQuery query(_pManager->getConnection());
    query.prepare(select_sql);
    query.addBindValue(id);

    bool flag = query.exec();
    if(false == flag)
    {
        qDebug() << "SwimRecordTableManager::getRecord:"<< query.lastError();
        return false;
    }

    while(query.next())
    {
        record.id = query.value(0).toInt();
        record.totalLap = query.value(1).toInt();
        record.totalTime = query.value(2).toTime();
        record.avgTime = query.value(3).toTime();
        record.FastestLapNum = query.value(4).toString();
        record.FLapTimeCost = query.value(5).toTime();
        record.SLowestLapNum = query.value(6).toString();
        record.SLapTimeCost = query.value(7).toTime();
        record.date = query.value(8).toDate();
    }
    return true;
}
