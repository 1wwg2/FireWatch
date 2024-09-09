#include "forestdataform.h"

// QLabel* NamesReporter;
// QLabel* DataAndTimeReport;
// QLabel* PictureOfTree;
// QLineEdit* Temperature;
// QLineEdit* WindSpeed;
// QComboBox* WeatherCondition;
// QPushButton* SumbitData;

void ForestDataForm::InitializationField()
{
    NamesReporter = new QLabel("Reported by ", this);
    DataAndTimeReport = new QLabel("Date:\nTime:", this);
    PictureOfTitle = new QLabel(this);
    PictureOfTree = new QLabel("Picturetree", this);
    Temperature = new QLineEdit("Enter Temp", this);
    WindSpeed = new QLineEdit("Enter W/S", this);
    WeatherCondition = new QComboBox(this);
    SumbitData = new QPushButton("Submit", this);
}
void ForestDataForm::SettingField()
{
    QPixmap ToLogoUser(":/resourses/LoginForm/FireWatchForm.png");
    QPixmap scaledToLogoUser = ToLogoUser.scaled(700, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    PictureOfTitle->setPixmap(scaledToLogoUser);

    QPixmap TreePicture(":/resourses/LoginForm/FirTree.png");
    QPixmap scaledTreePicture = TreePicture.scaled(300, 1000, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    PictureOfTree->setPixmap(scaledTreePicture);



}


void ForestDataForm::PlacementComponents()
{
    QLabel *secondTree = new QLabel(this);
    secondTree->setPixmap(PictureOfTree->pixmap());

    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    QVBoxLayout* Layout1 = new QVBoxLayout();
    QVBoxLayout* Layout2 = new QVBoxLayout();
    QVBoxLayout* Layout3 = new QVBoxLayout();


    Layout1->setContentsMargins(0, 0, 0, 0);
    Layout1->addWidget(NamesReporter);
    Layout1->addWidget(PictureOfTree);

    // Place PictureOfTitle and other widgets in Layout2

    Layout2->addWidget(PictureOfTitle, 0, Qt::AlignCenter);
    PictureOfTitle->setContentsMargins(0, 90, 0, 0);
    Layout2->addWidget(Temperature);
    Temperature->setContentsMargins(0, 0, 0, 0);
    Temperature->setFixedSize(1200, 50);
    Layout2->addWidget(WindSpeed);
    WindSpeed->setContentsMargins(0, 0, 0, 0);
    WindSpeed->setFixedSize(1200, 50);
    Layout2->addWidget(WeatherCondition);
    Layout2->addWidget(SumbitData);
    Layout2->setContentsMargins(10, 0, 10, 500);

    // Place DataAndTimeReport and secondTree in Layout3
    Layout3->addWidget(DataAndTimeReport);
    Layout3->addWidget(secondTree);

    // Add Layouts to mainLayout
    mainLayout->addLayout(Layout1);
    mainLayout->addLayout(Layout2);
    mainLayout->addLayout(Layout3);

    setLayout(mainLayout);


}

ForestDataForm::ForestDataForm(QWidget *parent) : QWidget(parent)
{
    InitializationField();
    SettingField();
    PlacementComponents();

}
