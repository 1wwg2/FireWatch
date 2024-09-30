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


class ScheduleOfWeather : public QWidget
{
    Q_OBJECT

private:
    QList<QString> Categories;
    QVector<double> temperatures;
    QList<double> windSpeeds;

    QList<double> sensorTemperatures;
    QList<double> sensorWindSpeeds;


    QChartView* temperatureChartView;
    // Создание графика скорости ветра
    QChartView* windSpeedChartView;
    // // Создание графика температуры с датчика
    QChartView* sensorTemperatureChartView;
    // // Создание графика скорости ветра с датчика
    QChartView* sensorWindSpeedChartView;
    // Поле класса для хранения категорий
    QString ExtractDate(const QString& dateTimeString);

    void WorkWithDb();

    void MakeCategories();
    void SetDataToScheudle(const QVector<double>& TemperatureDb);

    QChart* MakeTempChartApi(const QList<double>& temperatures);
    QChart* MakeWindSpChartApi(const QList<double>& windSpeeds);

    QChart* MakeWindSpChartDataBase(const QList<double>& sensorTemperatures);
    QChart* MakeTempChartDataBase(const QList<double>& sensorWindSpeeds);

    void MakeWidgetsAndCharts();
    void PlacementOfCharts();
public:
    explicit ScheduleOfWeather(QWidget *parent = nullptr);

};

#endif // SCHEDULEOFWEATHER_H
