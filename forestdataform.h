#ifndef FORESTDATAFORM_H
#define FORESTDATAFORM_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPixmap>
#include <QDateTime>
#include <QDoubleValidator>
#include <QMessageBox>
#include <QTimer>

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
    QPushButton* SumbitData;
    QTimer* Timer;
    CustomTableWidget* TableOfWeather;
    void InitializationField();
    void SettingField();
    void PlacementComponents();

    void TakeActualData();

    class CustomValidator : public QDoubleValidator
    {
    public:
        CustomValidator(QObject* parent = nullptr) : QDoubleValidator(parent)
        {
            setDecimals(1);
        }
        QValidator::State validate(QString &input, int &pos) const override
        {
            if(input.contains('E') || input.contains('e'))
            {
                return QValidator::Invalid;
            }
            else
            {
                return QDoubleValidator::validate(input, pos);
            }
        }
    };

private slots:
    void SentDataFromDay();
public:
    explicit ForestDataForm(QWidget *parent = nullptr);


};

#endif // FORESTDATAFORM_H
