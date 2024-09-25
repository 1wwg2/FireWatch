#include "scheduleofweather.h"
#include "src/FormForReport/customtablewidget.h"

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

    QString employeeName = "ff ddd";
    QString reportDate = "2024-09-24";
    QSqlQuery query;

    // Подготовка SQL-запроса для получения данных отчета за определенную дату
    query.prepare(R"(
        SELECT r.temperature, r.wind_speed, r.weather, r.report_date
        FROM reports r
        JOIN employees e ON r.employee_id = e.id
        WHERE e.full_name = :full_name
        AND DATE(r.report_date) = :report_date
    )");

    // Связываем параметры
    query.bindValue(":full_name", employeeName);
    query.bindValue(":report_date", reportDate);

    // Выполняем запрос и извлекаем данные
    if (query.exec())
    {
        while (query.next())
        {
            double temperature = query.value("temperature").toDouble();
            double windSpeed = query.value("wind_speed").toDouble();
            QString weather = query.value("weather").toString();
            QString reportDate = query.value("report_date").toString();

            // Выводим данные в консоль
            qDebug() << "Температура:" << temperature
                     << "Скорость ветра:" << windSpeed
                     << "Погода:" << weather
                     << "Дата отчета:" << reportDate;
        }
    }
    else
    {
        qDebug() << "Ошибка выполнения запроса: " << query.lastError().text();
    }

}

QChart* ScheduleOfWeather::MakeTempChartApi(const QStringList& categories, const QList<double>& temperatures)
{
    QChart *temperatureChart = new QChart();
    temperatureChart->setTitle("Температура за неделю");

    QLineSeries *temperatureSeries = new QLineSeries();
    for (int i = 0; i < categories.size(); ++i) {
        temperatureSeries->append(i, temperatures[i]);
    }
    temperatureSeries->setName("Температура (°C)");
    temperatureChart->addSeries(temperatureSeries);

    QCategoryAxis *axisXTemp = new QCategoryAxis();
    for (int i = 0; i < categories.size(); ++i) {
        axisXTemp->append(categories[i], i);
    }
    temperatureChart->setAxisX(axisXTemp, temperatureSeries);

    QValueAxis *axisYTemp = new QValueAxis();
    axisYTemp->setTitleText("Температура (°C)");
    temperatureChart->setAxisY(axisYTemp, temperatureSeries);
    return temperatureChart;

}

QChart* ScheduleOfWeather::MakeWindSpChartApi(const QStringList& categories, const QList<double>& windSpeeds)
{
    QChart *windSpeedChart = new QChart();
    windSpeedChart->setTitle("Скорость ветра за неделю");

    QLineSeries *windSpeedSeries = new QLineSeries();
    for (int i = 0; i < categories.size(); ++i) {
        windSpeedSeries->append(i, windSpeeds[i]);
    }
    windSpeedSeries->setName("Скорость ветра (м/с)");
    windSpeedChart->addSeries(windSpeedSeries);

    QCategoryAxis *axisXWind = new QCategoryAxis();
    for (int i = 0; i < categories.size(); ++i)
    {
        axisXWind->append(categories[i], i);
    }
    windSpeedChart->setAxisX(axisXWind, windSpeedSeries);

    QValueAxis *axisYWind = new QValueAxis();
    axisYWind->setTitleText("Скорость ветра (м/с)");
    windSpeedChart->setAxisY(axisYWind, windSpeedSeries);
    return windSpeedChart;

}

QChart* MakeWindSpChartDataBase(const QStringList& categories, const QList<double>& sensorTemperatures)
{
    QChart *sensorTemperatureChart = new QChart();
    sensorTemperatureChart->setTitle("Температура с датчика за неделю");
    QLineSeries *sensorTemperatureSeries = new QLineSeries();
    sensorTemperatureSeries->setColor(QColor(Qt::red));

    for (int i = 0; i < categories.size(); ++i) {
        sensorTemperatureSeries->append(i, sensorTemperatures[i]);
    }
    sensorTemperatureSeries->setName("Температура с датчика (°C)");

    sensorTemperatureChart->addSeries(sensorTemperatureSeries);

    QCategoryAxis *axisXSensorTemp = new QCategoryAxis();
    for (int i = 0; i < categories.size(); ++i) {
        axisXSensorTemp->append(categories[i], i);
    }
    sensorTemperatureChart->setAxisX(axisXSensorTemp, sensorTemperatureSeries);

    QValueAxis *axisYSensorTemp = new QValueAxis();
    axisYSensorTemp->setTitleText("Температура (°C)");
    sensorTemperatureChart->setAxisY(axisYSensorTemp, sensorTemperatureSeries);
    return sensorTemperatureChart;
}

QChart* MakeTempChartDataBase(const QStringList& categories, const QList<double>& sensorWindSpeeds)
{
    QChart *sensorWindSpeedChart = new QChart();
    sensorWindSpeedChart->setTitle("Скорость ветра с датчика за неделю");

    QLineSeries *sensorWindSpeedSeries = new QLineSeries();
    sensorWindSpeedSeries->setColor(QColor(Qt::red));

    for (int i = 0; i < categories.size(); ++i) {
        sensorWindSpeedSeries->append(i, sensorWindSpeeds[i]);
    }
    sensorWindSpeedSeries->setName("Скорость ветра с датчика (м/с)");
    sensorWindSpeedChart->addSeries(sensorWindSpeedSeries);

    QCategoryAxis *axisXSensorWind = new QCategoryAxis();
    for (int i = 0; i < categories.size(); ++i) {
        axisXSensorWind->append(categories[i], i);
    }
    sensorWindSpeedChart->setAxisX(axisXSensorWind, sensorWindSpeedSeries);

    QValueAxis *axisYSensorWind = new QValueAxis();
    axisYSensorWind->setTitleText("Скорость ветра (м/с)");
    sensorWindSpeedChart->setAxisY(axisYSensorWind, sensorWindSpeedSeries);
    return sensorWindSpeedChart;
}

void ScheduleOfWeather::PlacementOfCharts()
{

}

ScheduleOfWeather::ScheduleOfWeather(QWidget *parent) : QWidget(parent)
{


    WorkWithDb();
    QStringList categories{" ", "Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};
    QList<double> temperatures{0, 2, 0, 0, -10, 0, 23, 25};
    //QList<double> temperatures2{0, 18, 20, 22, 21, 19, 23, 25};
    QList<double> windSpeeds{0, 5, 7, 6, 8, 4, 9, 5};

    // Данные для новых графиков
    QList<double> sensorTemperatures{0, 17, 19, 21, 20, 18, 22, 24};
    QList<double> sensorWindSpeeds{0, 4, 6, 5, 7, 3, 8, 4};

    // Создание графика температуры
    QChart* temperatureChart = MakeTempChartApi(categories, temperatures);
    // Создание графика скорости ветра
    QChart* windSpeedChart = MakeWindSpChartApi(categories, windSpeeds);
    // Создание графика температуры с датчика
    QChart* sensorTemperatureChart = MakeWindSpChartApi(categories, sensorTemperatures);
    // Создание графика скорости ветра с датчика
    QChart* sensorWindSpeedChart = MakeWindSpChartApi(categories, sensorWindSpeeds);

    // Создание виджетов графиков
    QChartView *temperatureChartView = new QChartView(temperatureChart);
    temperatureChartView->setRenderHint(QPainter::Antialiasing);

    QChartView *windSpeedChartView = new QChartView(windSpeedChart);
    windSpeedChartView->setRenderHint(QPainter::Antialiasing);

    QChartView *sensorTemperatureChartView = new QChartView(sensorTemperatureChart);
    sensorTemperatureChartView->setRenderHint(QPainter::Antialiasing);

    QChartView *sensorWindSpeedChartView = new QChartView(sensorWindSpeedChart);
    sensorWindSpeedChartView->setRenderHint(QPainter::Antialiasing);

    // Создание вертикального layout для размещения графиков
    QHBoxLayout* mainlayout = new QHBoxLayout();
    QVBoxLayout *leftLayout = new QVBoxLayout();
    QVBoxLayout *rightLayout = new QVBoxLayout();

    leftLayout->addWidget(temperatureChartView);
    leftLayout->addWidget(windSpeedChartView);

    rightLayout->addWidget(sensorTemperatureChartView);
    rightLayout->addWidget(sensorWindSpeedChartView);


    mainlayout->addLayout(leftLayout);

    mainlayout->addLayout(rightLayout);

    CustomTableWidget* TableOfWeather = new CustomTableWidget();

//    mainlayout->addWidget(TableOfWeather);


    setLayout(mainlayout);
}
