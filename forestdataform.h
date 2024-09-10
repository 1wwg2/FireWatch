#ifndef FORESTDATAFORM_H
#define FORESTDATAFORM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPixmap>
#include <QDateTime>

#include "customtablewidget.h"
// TODO: Сделать фиксированный минимум приложения и иконку с ГЛАВНЫМ ОКНОМ
class ForestDataForm : public QWidget
{
    Q_OBJECT
private:
    QLabel* NamesReporter;
    QLabel* DataAndTimeReport;
    QLabel* PictureOfTree;
    QLabel* PictureOfTitle;
    QLineEdit* Temperature;
    QLineEdit* WindSpeed;
    QComboBox* WeatherCondition;
    QPushButton* SumbitData;

    CustomTableWidget* TableOfWeather;
    void InitializationField();
    void SettingField();
    void PlacementComponents();\

    void TakeActualData();
public:
    explicit ForestDataForm(QWidget *parent = nullptr);


};

#endif // FORESTDATAFORM_H
