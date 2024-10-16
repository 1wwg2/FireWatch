#include "scheduleofweather.h"
#include "src/LoginToApp/logintoapp.h"

namespace SettingPathDb
{
    extern const QString dbPath;
    extern const QString UrlApi;
}
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

void ScheduleOfWeather::FetchWeatherFromApi()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QUrl url(SettingPathDb::UrlApi);
    QNetworkRequest request(url);
    connect(manager, &QNetworkAccessManager::finished, this, &ScheduleOfWeather::OnReplyReceived);

    Reply = manager->get(request);
}

void ScheduleOfWeather::WorkWithDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(SettingPathDb::dbPath);

    if (!db.open())
    {
        QMessageBox* BoxError = new QMessageBox();
        BoxError->setIcon(QMessageBox::Critical);
        BoxError->setWindowTitle("Error!");
        BoxError->setText(db.lastError().text());
        BoxError->exec();
        return;
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
        CategoriesForDb = {" "};
        TemperaturesFromDb = {0};
        WindSpeedsFromDb = {0};
        QVector<QString> DateFromSevenDays{};
        while (query.next())
        {
            double temperature = query.value("temperature").toDouble();
            double windSpeed = query.value("wind_speed").toDouble();
            QString reportDate = query.value("report_date").toString();
             QDate date = QDate::fromString(ExtractDate(reportDate), "yyyy-MM-dd");
            //DateFromSevenDays.push_back();
             QString formattedTemperature = QString::number(temperature, 'f', 1); // 2 знака после запятой
             QString formattedWindSpeed = QString::number(windSpeed, 'f', 1); // 2 знака после запятой
            TemperaturesFromDb.push_back(formattedTemperature.toDouble());
            WindSpeedsFromDb.push_back(formattedWindSpeed.toDouble());
            CategoriesForDb.push_back(date.toString("ddd"));
        }
    }
    else
    {
        QMessageBox* BoxError = new QMessageBox();
        BoxError->setIcon(QMessageBox::Critical);
        BoxError->setWindowTitle("Error!");
        BoxError->setText("Contact with tech support");
        BoxError->exec();
    }

}

void ScheduleOfWeather::MakeCategories()
{

    QList<QString> TempCategories = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    QDate today = QDate::currentDate();
    QString dayOfWeek = today.toString("ddd");

    int dayIndex = TempCategories.indexOf(dayOfWeek);

    CategoriesForApi = {" "};

    if (dayIndex != -1)
    {
        for (int i = dayIndex; i < TempCategories.size(); ++i)
        {
            CategoriesForApi.push_back(TempCategories[i] + " (" + today.addDays(i - dayIndex).toString("MM-dd") + ")");
        }
        for (int i = 0; i < dayIndex; ++i)
        {
            CategoriesForApi.push_back(TempCategories[i] + " (" + today.addDays(TempCategories.size() - dayIndex + i).toString("MM-dd") + ")");
        }
    }
}



QList<QString>  ScheduleOfWeather::MakeCategoriesForDb(QList<QString>& DateFromSevenDays)
{
    QList<QString> daysOfWeek;

    for (const QString &dateString : DateFromSevenDays)
    {
        QDate date = QDate::fromString(dateString, "yyyy-MM-dd"); // Убедитесь, что формат даты соответствует вашему
        if (date.isValid())
        {
            QString dayOfWeek = date.toString("ddd"); // Полное название дня недели
            daysOfWeek.append(dayOfWeek);
        }
    }
    return daysOfWeek;
}

QChart* ScheduleOfWeather::MakeTempChartApi(const QList<double>& temperatures)
{
    QChart *temperatureChart = new QChart();
    temperatureChart->setTitle("Temperature from week");

    QLineSeries *temperatureSeries = new QLineSeries();
    for (int i = 0; i < CategoriesForApi.size(); ++i)
    {
        temperatureSeries->append(i, temperatures[i]);
    }
    temperatureSeries->setName("Temperature (°C)");
    temperatureChart->addSeries(temperatureSeries);

    temperatureSeries->setPointLabelsVisible(true);

    QCategoryAxis *axisXTemp = new QCategoryAxis();
    for (int i = 0; i < CategoriesForApi.size(); ++i)
    {
        axisXTemp->append(CategoriesForApi[i], i);
    }
    temperatureChart->setAxisX(axisXTemp, temperatureSeries);

    QValueAxis *axisYTemp = new QValueAxis();
    axisYTemp->setTitleText("Temperature (°C)");
    temperatureChart->setAxisY(axisYTemp, temperatureSeries);
    return temperatureChart;

}

QChart* ScheduleOfWeather::MakeWindSpChartApi(const QList<double>& windSpeeds)
{
    QChart *windSpeedChart = new QChart();
    windSpeedChart->setTitle("Wind speed from week");

    QLineSeries *windSpeedSeries = new QLineSeries();
    for (int i = 0; i < CategoriesForApi.size(); ++i) {
        windSpeedSeries->append(i, windSpeeds[i]);
    }
    windSpeedSeries->setName("Wind speed  (M/S)");
    windSpeedChart->addSeries(windSpeedSeries);

    windSpeedSeries->setPointLabelsVisible(true);

    QCategoryAxis *axisXWind = new QCategoryAxis();

    for (int i = 0; i < CategoriesForApi.size(); ++i)
    {
        axisXWind->append(CategoriesForApi[i], i);
    }
    windSpeedChart->setAxisX(axisXWind, windSpeedSeries);

    QValueAxis *axisYWind = new QValueAxis();
    axisYWind->setTitleText("Wind speed  (M/S)");
    windSpeedChart->setAxisY(axisYWind, windSpeedSeries);
    return windSpeedChart;

}

QChart* ScheduleOfWeather::MakeWindSpChartDataBase(const QList<double>& sensorTemperatures)
{
    QChart *sensorTemperatureChart = new QChart();

    sensorTemperatureChart->setTitle("Wind speed from the sensor for the last 7 readings");

    QLineSeries *sensorTemperatureSeries = new QLineSeries();
    sensorTemperatureSeries->setColor(QColor(Qt::red));
    sensorTemperatureSeries->setPointLabelsVisible(true);
    for (int i = 0; i < CategoriesForDb.size(); ++i)
    {
        sensorTemperatureSeries->append(i, sensorTemperatures[i]);
    }
    sensorTemperatureSeries->setName("Wind speed (M/S)");

    sensorTemperatureChart->addSeries(sensorTemperatureSeries);

    QCategoryAxis *axisXSensorTemp = new QCategoryAxis();
    for (int i = 0; i < CategoriesForDb.size(); ++i)
    {
        axisXSensorTemp->append(CategoriesForDb[i], i);
    }
    sensorTemperatureChart->setAxisX(axisXSensorTemp, sensorTemperatureSeries);

    QValueAxis *axisYSensorTemp = new QValueAxis();
    axisYSensorTemp->setTitleText("Wind speed  (M/S)");
    sensorTemperatureChart->setAxisY(axisYSensorTemp, sensorTemperatureSeries);
    return sensorTemperatureChart;
}

QChart* ScheduleOfWeather::MakeTempChartDataBase(const QList<double>& sensorWindSpeeds)
{
    QChart *sensorWindSpeedChart = new QChart();
    sensorWindSpeedChart->setTitle("Temperature from the sensor for the last 7 readings");

    QLineSeries *sensorWindSpeedSeries = new QLineSeries();
    sensorWindSpeedSeries->setColor(QColor(Qt::red));
    sensorWindSpeedSeries->setPointLabelsVisible(true);

    for (int i = 0; i < CategoriesForDb.size(); ++i)
    {
        sensorWindSpeedSeries->append(i, sensorWindSpeeds[i]);
    }
    sensorWindSpeedSeries->setName("Temperature (°C)");
    sensorWindSpeedChart->addSeries(sensorWindSpeedSeries);

    QCategoryAxis *axisXSensorWind = new QCategoryAxis();
    for (int i = 0; i < CategoriesForDb.size(); ++i)
    {
        axisXSensorWind->append(CategoriesForDb[i], i);
    }
    sensorWindSpeedChart->setAxisX(axisXSensorWind, sensorWindSpeedSeries);

    QValueAxis *axisYSensorWind = new QValueAxis();
    axisYSensorWind->setTitleText("Temperature (°C)");
    sensorWindSpeedChart->setAxisY(axisYSensorWind, sensorWindSpeedSeries);
    return sensorWindSpeedChart;
}

void ScheduleOfWeather::MakeWidgetsAndCharts()
{
    QChart* temperatureChart = MakeTempChartApi(TemperaturesFromApi);
    QChart* windSpeedChart = MakeWindSpChartApi(WindSpeedsFromApi);
    QChart* sensorTemperatureChart = MakeTempChartDataBase(TemperaturesFromDb);
    QChart* sensorWindSpeedChart = MakeWindSpChartDataBase(WindSpeedsFromDb);

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


void ScheduleOfWeather::OnReplyReceived()
{
    TemperaturesFromApi = {0};
    WindSpeedsFromApi = {0};
    if (Reply->error() == QNetworkReply::NoError)
    {
        QByteArray responseData = Reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonArray forecastArray = jsonDoc["list"].toArray();

        const QString targetTime = "15:00:00";

        for (const QJsonValue &value : forecastArray)
        {
            QJsonObject forecast = value.toObject();
            QString dt_txt = forecast["dt_txt"].toString();

            if (dt_txt.contains(targetTime))
            {
                QJsonObject mainObject = forecast["main"].toObject();
                TemperaturesFromApi.push_back(mainObject["temp"].toDouble());

                QJsonObject windObject = forecast["wind"].toObject();
                WindSpeedsFromApi.push_back(windObject["speed"].toDouble());
            }
        }

        while(WindSpeedsFromApi.size() < 8)
        {
            TemperaturesFromApi.push_back(qQNaN());
            WindSpeedsFromApi.push_back(qQNaN());
        }
        MakeCategories();
        MakeWidgetsAndCharts();
        PlacementOfCharts();
    }
    else
    {
        QMessageBox::critical(this, "Error",
                              "API or Database is not working. Please contact support.");
    }
    Reply->deleteLater();
}


ScheduleOfWeather::ScheduleOfWeather(QWidget *parent) : QWidget(parent)
{
    WorkWithDb();
    FetchWeatherFromApi();
}
