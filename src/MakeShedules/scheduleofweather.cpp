#include "scheduleofweather.h"


QString ScheduleOfWeather::ExtractDate(const QString& dateTimeString)
{
    QDateTime dateTime = QDateTime::fromString(dateTimeString, "yyyy-MM-dd HH:mm:ss");
    if (dateTime.isValid())
    {
        return dateTime.date().toString("yyyy-MM-dd");
    }
    else
    {
        QMessageBox* BoxError = new QMessageBox();
        BoxError->setIcon(QMessageBox::Critical);
        BoxError->setWindowTitle("Error!");
        BoxError->setText("Contact with tech support");
        BoxError->exec();
        return QString();
    }
}

void ScheduleOfWeather::WorkWithDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/vitaliy/Qt_Projects/FireWatch/dump/employ.db");

    if (!db.open())
    {
        qDebug() << "Не удалось подключиться к базе данных:" << db.lastError().text();
        return;
    }
    else
    {
        qDebug() << "Подключение к базе данных успешно!";
    }

    QString employeeName = "1";
    QSqlQuery query;

    query.prepare(R"(
        SELECT temperature, wind_speed, weather, report_date
        FROM (
            SELECT r.temperature, r.wind_speed, r.weather, r.report_date
            FROM reports r
            JOIN employees e ON r.employee_id = e.id
            WHERE e.full_name = :full_name
            ORDER BY r.report_date DESC
            LIMIT 7
        ) AS last_reports
        ORDER BY report_date ASC;
    )");

    query.bindValue(":full_name", employeeName);

    if (query.exec())
    {
        QVector<double> TemperatureDb{};
        QList<QString> DateFromSevenDays{}; // возможно убрать
        int i = 0;
        while (query.next())
        {
            double temperature = query.value("temperature").toDouble();
            double windSpeed = query.value("wind_speed").toDouble();
            QString weather = query.value("weather").toString();
            QString reportDate = query.value("report_date").toString();

            TemperatureDb.push_back(temperature);
            DateFromSevenDays.push_back(ExtractDate(reportDate));
            qDebug() << ++i << "Температура:" << temperature
                     << "Скорость ветра:" << windSpeed
                     << "Погода:" << weather
                     << "Дата отчета:" << reportDate;
        }

        MakeCategories();
        SetDataToScheudle(TemperatureDb);
    }
    else
    {
        qDebug() << "Ошибка выполнения запроса: " << query.lastError().text();
    }

}

void ScheduleOfWeather::MakeCategories()
{

    QList<QString> TempCategories = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    QDate today = QDate::currentDate();
    QString dayOfWeek = today.toString("ddd");

    qDebug() << "Сегодняшняя дата:" << today.toString("yyyy-MM-dd");
    qDebug() << "Сегодня день недели (название):" << dayOfWeek;

    int dayIndex = TempCategories.indexOf(dayOfWeek);

    Categories = {" "};

    if (dayIndex != -1)
    {
        for (int i = dayIndex; i < TempCategories.size(); ++i)
        {
            Categories.push_back(TempCategories[i] + " (" + today.addDays(i - dayIndex).toString("MM-dd") + ")");
        }

        for (int i = 0; i < dayIndex; ++i)
        {
            Categories.push_back(TempCategories[i] + " (" + today.addDays(TempCategories.size() - dayIndex + i).toString("MM-dd") + ")");
        }
    }
    else
    {
        qDebug() << "День недели не найден в списке!";
    }


}


void ScheduleOfWeather::SetDataToScheudle(const QVector<double>& TemperatureDb)
{

    temperatures = {0, 17, 19, qQNaN(), 20, 18, 22, 24};
    windSpeeds = {0, 5, 7, 6, 8, 4, 9, 5};

    sensorTemperatures = {0, 17, 19, 21, 20, 18, 22, 24};
    sensorWindSpeeds = {0, 4, 6, 5, 7, 3, 8, 4};

}


QChart* ScheduleOfWeather::MakeTempChartApi(const QList<double>& temperatures)
{
    QChart *temperatureChart = new QChart();
    temperatureChart->setTitle("Температура за неделю");

    QLineSeries *temperatureSeries = new QLineSeries();
    for (int i = 0; i < Categories.size(); ++i) {
        temperatureSeries->append(i, temperatures[i]);
    }
    temperatureSeries->setName("Температура (°C)");
    temperatureChart->addSeries(temperatureSeries);

    QCategoryAxis *axisXTemp = new QCategoryAxis();
    for (int i = 0; i < Categories.size(); ++i) {
        axisXTemp->append(Categories[i], i);
    }
    temperatureChart->setAxisX(axisXTemp, temperatureSeries);

    QValueAxis *axisYTemp = new QValueAxis();
    axisYTemp->setTitleText("Температура (°C)");
    temperatureChart->setAxisY(axisYTemp, temperatureSeries);
    return temperatureChart;

}

QChart* ScheduleOfWeather::MakeWindSpChartApi(const QList<double>& windSpeeds)
{
    QChart *windSpeedChart = new QChart();
    windSpeedChart->setTitle("Скорость ветра за неделю");

    QLineSeries *windSpeedSeries = new QLineSeries();
    for (int i = 0; i < Categories.size(); ++i) {
        windSpeedSeries->append(i, windSpeeds[i]);
    }
    windSpeedSeries->setName("Скорость ветра (м/с)");
    windSpeedChart->addSeries(windSpeedSeries);

    QCategoryAxis *axisXWind = new QCategoryAxis();
    for (int i = 0; i < Categories.size(); ++i)
    {
        axisXWind->append(Categories[i], i);
    }
    windSpeedChart->setAxisX(axisXWind, windSpeedSeries);

    QValueAxis *axisYWind = new QValueAxis();
    axisYWind->setTitleText("Скорость ветра (м/с)");
    windSpeedChart->setAxisY(axisYWind, windSpeedSeries);
    return windSpeedChart;

}

QChart* ScheduleOfWeather::MakeWindSpChartDataBase(const QList<double>& sensorTemperatures)
{
    QChart *sensorTemperatureChart = new QChart();
    sensorTemperatureChart->setTitle("Температура с датчика за неделю");
    QLineSeries *sensorTemperatureSeries = new QLineSeries();
    sensorTemperatureSeries->setColor(QColor(Qt::red));

    for (int i = 0; i < Categories.size(); ++i) {
        sensorTemperatureSeries->append(i, sensorTemperatures[i]);
    }
    sensorTemperatureSeries->setName("Температура с датчика (°C)");

    sensorTemperatureChart->addSeries(sensorTemperatureSeries);

    QCategoryAxis *axisXSensorTemp = new QCategoryAxis();
    for (int i = 0; i < Categories.size(); ++i) {
        axisXSensorTemp->append(Categories[i], i);
    }
    sensorTemperatureChart->setAxisX(axisXSensorTemp, sensorTemperatureSeries);

    QValueAxis *axisYSensorTemp = new QValueAxis();
    axisYSensorTemp->setTitleText("Температура (°C)");
    sensorTemperatureChart->setAxisY(axisYSensorTemp, sensorTemperatureSeries);
    return sensorTemperatureChart;
}

QChart* ScheduleOfWeather::MakeTempChartDataBase(const QList<double>& sensorWindSpeeds)
{
    QChart *sensorWindSpeedChart = new QChart();
    sensorWindSpeedChart->setTitle("Скорость ветра с датчика за неделю");

    QLineSeries *sensorWindSpeedSeries = new QLineSeries();
    sensorWindSpeedSeries->setColor(QColor(Qt::red));

    for (int i = 0; i < Categories.size(); ++i) {
        sensorWindSpeedSeries->append(i, sensorWindSpeeds[i]);
    }
    sensorWindSpeedSeries->setName("Скорость ветра с датчика (м/с)");
    sensorWindSpeedChart->addSeries(sensorWindSpeedSeries);

    QCategoryAxis *axisXSensorWind = new QCategoryAxis();
    for (int i = 0; i < Categories.size(); ++i) {
        axisXSensorWind->append(Categories[i], i);
    }
    sensorWindSpeedChart->setAxisX(axisXSensorWind, sensorWindSpeedSeries);

    QValueAxis *axisYSensorWind = new QValueAxis();
    axisYSensorWind->setTitleText("Скорость ветра (м/с)");
    sensorWindSpeedChart->setAxisY(axisYSensorWind, sensorWindSpeedSeries);
    return sensorWindSpeedChart;
}

void ScheduleOfWeather::MakeWidgetsAndCharts()
{
    QChart* temperatureChart = MakeTempChartApi(temperatures);
    QChart* windSpeedChart = MakeWindSpChartApi(windSpeeds);
    QChart* sensorTemperatureChart = MakeTempChartDataBase(sensorTemperatures);
    QChart* sensorWindSpeedChart = MakeWindSpChartApi(sensorWindSpeeds);

    temperatureChartView = new QChartView(temperatureChart);
    temperatureChartView->setRenderHint(QPainter::Antialiasing);

    windSpeedChartView = new QChartView(windSpeedChart);
    windSpeedChartView->setRenderHint(QPainter::Antialiasing);

    sensorTemperatureChartView = new QChartView(sensorTemperatureChart);
    sensorTemperatureChartView->setRenderHint(QPainter::Antialiasing);

    sensorWindSpeedChartView = new QChartView(sensorWindSpeedChart);
    sensorWindSpeedChartView->setRenderHint(QPainter::Antialiasing);
}

void ScheduleOfWeather::PlacementOfCharts()
{
    QHBoxLayout* mainlayout = new QHBoxLayout(this);
    QVBoxLayout *leftLayout = new QVBoxLayout();
    QVBoxLayout *rightLayout = new QVBoxLayout();

    leftLayout->addWidget(temperatureChartView);
    leftLayout->addWidget(windSpeedChartView);

    rightLayout->addWidget(sensorTemperatureChartView);
    rightLayout->addWidget(sensorWindSpeedChartView);

    mainlayout->addLayout(leftLayout);
    mainlayout->addLayout(rightLayout);

    setLayout(mainlayout);
}

ScheduleOfWeather::ScheduleOfWeather(QWidget *parent) : QWidget(parent)
{
   // MakeCategories();
    WorkWithDb();

   // SetDataToScheudle();
    MakeWidgetsAndCharts();
    PlacementOfCharts();
}
