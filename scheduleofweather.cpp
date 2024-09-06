#include "scheduleofweather.h"

ScheduleOfWeather::ScheduleOfWeather(QWidget *parent) : QWidget(parent)
{

    QVBoxLayout *layout1 = new QVBoxLayout(this);
    QLabel *label1 = new QLabel("Sheudle", this);
    layout1->addWidget(label1);
    setLayout(layout1);

}
