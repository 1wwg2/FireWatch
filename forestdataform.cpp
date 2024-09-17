#include "forestdataform.h"

void ForestDataForm::InitializationField()
{
    NamesReporter = new QLabel("Reported by ", this);
    DataAndTimeReport = new QLabel(this);
    PictureOfTitle = new QLabel(this);
    PictureOfTree = new QLabel("Picturetree", this);
    Temperature = new QLineEdit(this);
    WindSpeed = new QLineEdit(this);
    SumbitData = new QPushButton("Submit", this);
    Timer = new QTimer(this);
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
}

void ForestDataForm::PlacementComponents()
{
    QLabel* Celsius = new QLabel("Temperature \t\t\t\t\t\t\t\t°C", this);
    QLabel* WindSpeedLabel = new QLabel(" Wind Speed\t\t\t\t\t\t\t\tM/S", this);
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
    LayoutCenter->setSpacing(10);

    PictureOfTitle->setFixedSize(600, 200);
    LayoutCenter->addWidget(PictureOfTitle, 0, Qt::AlignCenter);


    LayoutCenter->addWidget(Celsius, 0, Qt::AlignRight);
    Temperature->setFixedSize(550, 40);
    Temperature->setValidator(new CustomValidator(this));
    Temperature->setPlaceholderText("Enter temperature: ");
    LayoutCenter->addWidget(Temperature, 0, Qt::AlignCenter);

    LayoutCenter->addWidget(WindSpeedLabel, 0, Qt::AlignRight);
    WindSpeed->setFixedSize(550, 40);
    WindSpeed->setValidator(new CustomValidator(this));
    WindSpeed->setPlaceholderText("Enter wind speed M/S:");
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

    DataAndTimeReport->setText("Time : " + TimeString +"Date: " + DateString);
}



void ForestDataForm::SentDataFromDay()
{
    if(Temperature->text().isEmpty())
    {
        QMessageBox* BoxError = new QMessageBox(this);
        BoxError->setIcon(QMessageBox::Critical);
        BoxError->setWindowTitle("Error!");
        BoxError->setText("Temperature form is empty!.\nPlease enter data from your device.");
        BoxError->exec();
    }
    else if(WindSpeed->text().isEmpty())
    {
        QMessageBox* BoxError = new QMessageBox(this);
        BoxError->setIcon(QMessageBox::Critical);
        BoxError->setWindowTitle("Error!");
        BoxError->setText("Wind Speed form is empty!.\nPlease enter data from your device.");
        BoxError->exec();
    }
    else if(TableOfWeather->GetState().isEmpty())
    {
        QMessageBox* BoxError = new QMessageBox(this);
        BoxError->setIcon(QMessageBox::Critical);
        BoxError->setWindowTitle("Error!");
        BoxError->setText("Wheather state form is empty!.\nPlease enter data from your device.");
        BoxError->exec();
    }
    else
    {
        QDialog* DataConfirmation = new QDialog();
        DataConfirmation->setWindowTitle("Confirm Data Log");
        DataConfirmation->setFixedSize(300, 300);

        QPushButton *OkButton = new QPushButton("OK");
        QPushButton *CancelButton = new QPushButton("Cancel");
        QIcon OkIcon = QApplication::style()->standardIcon(QStyle::SP_DialogOkButton);
        QIcon CancelIcon = QApplication::style()->standardIcon(QStyle::SP_DialogCancelButton);
        OkButton->setIcon(OkIcon);
        OkButton->setDefault(true);
        CancelButton->setIcon(CancelIcon);



        QHBoxLayout *ButtonLayout = new QHBoxLayout();
        ButtonLayout->addWidget(CancelButton);
        ButtonLayout->addWidget(OkButton);


        QVBoxLayout* DataPositioning = new QVBoxLayout();
        QLabel* DataLog = new QLabel(
            QString("Temperature: " + Temperature->text()
                    + "\nWind Speed: " + WindSpeed->text()
                    + "\nWheather state is "
                    + TableOfWeather->GetState()
                    + "\n" +  NamesReporter->text()
                    + "\n\nDate of report submission\n"
                    +  DataAndTimeReport->text())
                                                    , this);

        DataPositioning->addWidget(DataLog);
        DataPositioning->addLayout(ButtonLayout);
        DataConfirmation->setLayout(DataPositioning);

        connect(OkButton, &QPushButton::clicked, DataConfirmation, &QDialog::accept);
        connect(CancelButton, &QPushButton::clicked, DataConfirmation, &QDialog::reject);


        DataConfirmation->exec();

        if(DataConfirmation->result() == QDialog::Accepted)
        {
            qDebug() << "LALALALALALA";
        }
        else
        {
            DataConfirmation->close();
        }

    }
}

ForestDataForm::ForestDataForm(QWidget *parent) : QWidget(parent)
{
    InitializationField();
    SettingField();
    PlacementComponents();

    connect(SumbitData, &QPushButton::clicked, this, &ForestDataForm::SentDataFromDay);
    connect(Timer, &QTimer::timeout, this, &ForestDataForm::TakeActualData);
    Timer->start(1000);
    TakeActualData();
}

