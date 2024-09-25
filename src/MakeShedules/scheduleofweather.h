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
#include <QtMath>


class ScheduleOfWeather : public QWidget
{
    Q_OBJECT

private:
    /*QChart *temperatureChart;
    QChart *windSpeedChart;
    QChart *sensorTemperatureChart;
    QChart *sensorWindSpeedChart;*/

   /* QStringList categories;
    QList<double> temperatures;
    QList<double> windSpeeds;
    QList<double> sensorTemperatures;
    QList<double> sensorWindSpeeds;*/


    void WorkWithDb();

    QChart* MakeTempChartApi(const QStringList& categories, const QList<double>& temperatures);
    QChart* MakeWindSpChartApi(const QStringList& categories, const QList<double>& windSpeeds);

    QChart* MakeWindSpChartDataBase(const QStringList& categories, const QList<double>& sensorTemperatures);
    QChart* MakeTempChartDataBase(const QStringList& categories, const QList<double>& sensorWindSpeeds);

    void PlacementOfCharts();
public:
    explicit ScheduleOfWeather(QWidget *parent = nullptr);

};

#endif // SCHEDULEOFWEATHER_H
