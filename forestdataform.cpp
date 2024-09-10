#include "forestdataform.h"

void ForestDataForm::InitializationField()
{
    NamesReporter = new QLabel("Reported by ", this);
    DataAndTimeReport = new QLabel(this);
    PictureOfTitle = new QLabel(this);
    PictureOfTree = new QLabel("Picturetree", this);
    Temperature = new QLineEdit("Enter Temp", this);
    WindSpeed = new QLineEdit("Enter W/S", this);
    WeatherCondition = new QComboBox();
    SumbitData = new QPushButton("Submit", this);

    TableOfWeather = new CustomTableWidget(this);
}
void ForestDataForm::SettingField()
{
    QPixmap ToLogoUser(":/resourses/LoginForm/FireWatchForm.png");
    QPixmap scaledToLogoUser = ToLogoUser.scaled(600, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    PictureOfTitle->setPixmap(scaledToLogoUser);

    QPixmap TreePicture(":/resourses/LoginForm/FirTree.png");
    QPixmap scaledTreePicture = TreePicture.scaled(300, 1000, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    PictureOfTree->setPixmap(scaledTreePicture);

    TakeActualData();
}

void ForestDataForm::PlacementComponents()
{
    QLabel* Celsius = new QLabel(" Temperature\t\t\t\t\t\t\t\t°C", this);
    QLabel* WindSpeedLabel = new QLabel(" Wind Speed\t\t\t\t\t\t\t\tkn", this);
    QLabel *SecondTree = new QLabel(this);
    SecondTree->setPixmap(PictureOfTree->pixmap());

    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    QVBoxLayout* LayoutLeft = new QVBoxLayout();
    QVBoxLayout* LayoutCenter = new QVBoxLayout();
    QVBoxLayout* LayoutRight = new QVBoxLayout();

    LayoutLeft->setContentsMargins(0, 0, 0, 0);
    LayoutLeft->addWidget(NamesReporter, 0, Qt::AlignCenter);
    LayoutLeft->addWidget(PictureOfTree, 0, Qt::AlignCenter);

    LayoutCenter->setContentsMargins(80, 80, 80, 10);
    LayoutCenter->setSpacing(20);

    PictureOfTitle->setFixedSize(600, 200);
    LayoutCenter->addWidget(PictureOfTitle, 0, Qt::AlignCenter);


    LayoutCenter->addWidget(Celsius, 0, Qt::AlignRight);
    Temperature->setFixedSize(550, 40);
    LayoutCenter->addWidget(Temperature, 0, Qt::AlignCenter);

    LayoutCenter->addWidget(WindSpeedLabel, 0, Qt::AlignRight);
    WindSpeed->setFixedSize(550, 40);
    LayoutCenter->addWidget(WindSpeed, 0, Qt::AlignCenter);


    TableOfWeather->setFixedSize(500, 200);
    LayoutCenter->addWidget(TableOfWeather, 0, Qt::AlignCenter);

    SumbitData->setFixedSize(550, 40);
    LayoutCenter->addWidget(SumbitData, 0, Qt::AlignCenter);


    LayoutCenter->addStretch();
    LayoutLeft->setContentsMargins(0, 0, 0, 0);
    LayoutRight->addWidget(DataAndTimeReport, 0, Qt::AlignLeft);
    LayoutRight->addWidget(SecondTree, 0, Qt::AlignRight);


    mainLayout->addStretch();
    mainLayout->addLayout(LayoutLeft);
    mainLayout->addStretch();
    mainLayout->addLayout(LayoutCenter);
    mainLayout->addStretch();
    mainLayout->addLayout(LayoutRight);
    mainLayout->addStretch();
    setLayout(mainLayout);

}

void ForestDataForm::TakeActualData()
{
    QDateTime CurrentDateTime = QDateTime::currentDateTime();
    QString DateString = CurrentDateTime.toString("dd.MM.yyyy");
    QString TimeString = CurrentDateTime.toString("hh:mm:ss\n");

    DataAndTimeReport->setText("Time: " + TimeString +"Date: " + DateString);
}
ForestDataForm::ForestDataForm(QWidget *parent) : QWidget(parent)
{
    InitializationField();
    SettingField();
    PlacementComponents();

}
