#ifndef SCHEDULEOFWEATHER_H
#define SCHEDULEOFWEATHER_H

#include <QApplication>
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
#include <QDate>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

#include "src/FormForReport/forestdataform.h"

class ScheduleOfWeather : public QWidget
{
    Q_OBJECT

private:
    QList<QString> CategoriesForApi;
    QList<QString> CategoriesForDb;
    QVector<double> TemperaturesFromApi;
    QVector<double> WindSpeedsFromApi;

    QVector<double> TemperaturesFromDb;
    QVector<double> WindSpeedsFromDb;

    QChartView* temperatureChartView;
    QChartView* windSpeedChartView;
    QChartView* sensorTemperatureChartView;
    QChartView* sensorWindSpeedChartView;

    QNetworkReply* Reply = nullptr;

    QString ExtractDate(const QString& dateTimeString);


    void FetchWeatherFromApi();

    void WorkWithDb();

    void MakeCategories();
    QList<QString> MakeCategoriesForDb(QList<QString>& DateFromSevenDays);
    void SetDataToScheudle();

    QChart* MakeTempChartApi(const QList<double>& temperatures);
    QChart* MakeWindSpChartApi(const QList<double>& windSpeeds);

    QChart* MakeWindSpChartDataBase(const QList<double>& sensorTemperatures);
    QChart* MakeTempChartDataBase(const QList<double>& sensorWindSpeeds);

    void MakeWidgetsAndCharts();
    void PlacementOfCharts();
private slots:
    void OnReplyReceived();
public:


    explicit ScheduleOfWeather(QWidget *parent = nullptr);

};

#endif // SCHEDULEOFWEATHER_H
