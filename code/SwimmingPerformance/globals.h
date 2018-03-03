#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>
#include <QTime>
#include <QDebug>

/**
 * @brief 游泳记录结构体
 */
struct SwimRecord
{
    int id;
    int totalLap;                       //总圈数
    QTime totalTime;                    //总时间
    QTime avgTime;                      //每圈平均时间
    QString FastestLapNum;              //最快圈号
    QTime FLapTimeCost;                 //最快圈时间
    QString SLowestLapNum;              //最慢圈号
    QTime SLapTimeCost;                 //最慢圈时间
    QDate date;
};

/**
 * @brief 每圈详细数据
 */
struct DetailSwimRecord
{
    int id;
    QString lapNum;                     //圈号
    QTime record;                       //该圈时间
};

#endif // GLOBALS_H
