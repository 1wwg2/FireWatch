#include "customtablewidget.h"

void CustomTableWidget::setupTable()
{
    WheatherState =
    {
        "Blizzard", "Clear", "Cloudy",
        "DustStorm", "Heat", "Mist",
        "Rain", "Thunderstorm", "Wind"
    };

    tableWidget->setIconSize(QSize(55, 55));
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    tableWidget->horizontalHeader()->setVisible(false);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->verticalHeader()->setStretchLastSection(true);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int stateIndex = 0;

    for (int row = 0; row < tableWidget->rowCount(); ++row)
    {
        for (int col = 0; col < tableWidget->columnCount(); ++col)
        {
            if (stateIndex < WheatherState.size()) {
                QTableWidgetItem *item = new QTableWidgetItem(WheatherState[stateIndex]);
                item->setIcon(QIcon(":/resourses/Wheather/" + WheatherState[stateIndex] + ".png"));
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                tableWidget->setItem(row, col, item);
                ++stateIndex;
            }
        }
    }
}

void CustomTableWidget::updateLabel()
{
    QList<QTableWidgetItem*> selectedItems = tableWidget->selectedItems();
    if (!selectedItems.isEmpty())
    {
        QTableWidgetItem *item = selectedItems.first();
        State = item->text();
        ChooseWeatherStateLabel->setText("The weather is:  " + State);
    }
    else
    {
        ChooseWeatherStateLabel->setText("Choose weather state: ");
    }
}

CustomTableWidget::CustomTableWidget(QWidget *parent) : QWidget(parent)
{
    tableWidget = new QTableWidget(3, 3, this);
    ChooseWeatherStateLabel = new QLabel("Choose weather state: ", this);
    State = "";
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tableWidget);
    layout->addWidget(ChooseWeatherStateLabel);

    setLayout(layout);

    setupTable();

    tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    connect(tableWidget, &QTableWidget::itemSelectionChanged, this, &CustomTableWidget::updateLabel);
}

QString CustomTableWidget::GetState() const
{
    return State;
}

