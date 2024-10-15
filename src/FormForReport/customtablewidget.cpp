#include "customtablewidget.h"

void CustomTableWidget::SetupTable()
{
    WheatherState =
    {
        "Blizzard", "Clear", "Cloudy",
        "DustStorm", "Heat", "Mist",
        "Rain", "Thunderstorm", "Wind"
    };

    TableWidget->setIconSize(QSize(55, 55));
    TableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    TableWidget->horizontalHeader()->setVisible(false);
    TableWidget->verticalHeader()->setVisible(false);
    TableWidget->horizontalHeader()->setStretchLastSection(true);
    TableWidget->verticalHeader()->setStretchLastSection(true);
    TableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    TableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int stateIndex = 0;

    for (int row = 0; row < TableWidget->rowCount(); ++row)
    {
        for (int col = 0; col < TableWidget->columnCount(); ++col)
        {
            if (stateIndex < WheatherState.size()) {
                QTableWidgetItem *item = new QTableWidgetItem(WheatherState[stateIndex]);
                item->setIcon(QIcon(":/resourses/Wheather/" + WheatherState[stateIndex] + ".png"));
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                TableWidget->setItem(row, col, item);
                ++stateIndex;
            }
        }
    }
}

void CustomTableWidget::UpdateLabel()
{
    QList<QTableWidgetItem*> selectedItems = TableWidget->selectedItems();
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
    TableWidget = new QTableWidget(3, 3, this);
    ChooseWeatherStateLabel = new QLabel("Choose weather state: ", this);
    State = "";
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(TableWidget);
    layout->addWidget(ChooseWeatherStateLabel);

    setLayout(layout);
    SetupTable();
    TableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(TableWidget, &QTableWidget::itemSelectionChanged, this, &CustomTableWidget::UpdateLabel);
}

QString CustomTableWidget::GetState() const
{
    return State;
}

