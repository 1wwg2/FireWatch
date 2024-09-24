#ifndef CUSTOMTABLEWIDGET_H
#define CUSTOMTABLEWIDGET_H

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QHeaderView>
#include <QIcon>
#include <QSize>
#include <QString>

class CustomTableWidget : public QWidget
{
    Q_OBJECT

private:
    QTableWidget *tableWidget;
    QLabel* ChooseWeatherStateLabel;
    QString State;
    QVector<QString> WheatherState;
    void setupTable();
    void updateLabel();
public:
    explicit CustomTableWidget(QWidget *parent = nullptr);

    QString GetState() const;
};



#endif // CUSTOMTABLEWIDGET_H
