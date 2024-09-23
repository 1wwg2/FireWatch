#ifndef SCHEDULEOFWEATHER_H
#define SCHEDULEOFWEATHER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QtCharts>
#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
class ScheduleOfWeather : public QWidget
{
    Q_OBJECT
public:
    explicit ScheduleOfWeather(QWidget *parent = nullptr);

};

#endif // SCHEDULEOFWEATHER_H
