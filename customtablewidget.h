#ifndef CUSTOMTABLEWIDGET_H
#define CUSTOMTABLEWIDGET_H

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QHeaderView>


class CustomTableWidget : public QWidget {
    Q_OBJECT

public:
    CustomTableWidget(QWidget *parent = nullptr) : QWidget(parent) {
        tableWidget = new QTableWidget(3, 3, this);
        label = new QLabel("Выберите ячейку", this);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(tableWidget);
        layout->addWidget(label);

        setLayout(layout);

        setupTable();

        // Устанавливаем политики размера
        tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        connect(tableWidget, &QTableWidget::itemSelectionChanged, this, &CustomTableWidget::updateLabel);
    }

private:
    QTableWidget *tableWidget;
    QLabel *label;

    void setupTable() {
        int value = 1; // Начальное значение
        for (int row = 0; row < tableWidget->rowCount(); ++row) {
            for (int col = 0; col < tableWidget->columnCount(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(value));
                tableWidget->setItem(row, col, item);
                ++value;
            }
        }

        // Скрыть вертикальные и горизонтальные заголовки
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);

        // Растянуть таблицу на всё доступное пространство
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setStretchLastSection(true);
        tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    void updateLabel() {
        QList<QTableWidgetItem *> selectedItems = tableWidget->selectedItems();
        if (!selectedItems.isEmpty()) {
            QTableWidgetItem *item = selectedItems.first();
            label->setText("Вы выбрали: " + item->text());
        } else {
            label->setText("Выберите ячейку");
        }
    }
};



#endif // CUSTOMTABLEWIDGET_H
