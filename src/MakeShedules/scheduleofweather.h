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

   QVector<QString> categories; // Поле класса для хранения категорий
    void WorkWithDb();

    QChart* MakeTempChartApi(const QList<double>& temperatures);
    QChart* MakeWindSpChartApi(const QList<double>& windSpeeds);

    QChart* MakeWindSpChartDataBase(const QList<double>& sensorTemperatures);
    QChart* MakeTempChartDataBase(const QList<double>& sensorWindSpeeds);


    /*QChart* MakeTempChartApi(const QList<double>& temperatures);
    QChart* MakeWindSpChartApi(const QList<double>& windSpeeds);

    QChart* MakeWindSpChartDataBase(const QList<double>& sensorTemperatures);
    QChart* MakeTempChartDataBase(const QList<double>& sensorWindSpeeds);*/

    void PlacementOfCharts();
public:
    explicit ScheduleOfWeather(QWidget *parent = nullptr);

};

#endif // SCHEDULEOFWEATHER_H
