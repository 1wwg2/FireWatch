#include "assistancetovictim.h"

void AssistanceToVictim::SettingFields()
{
    QTime currentTime = QTime::currentTime();
    QDate currentDate = QDate::currentDate();
    TimeNow = new QLabel("Time report: " + currentTime.toString("HH:mm ") + currentDate.toString("dd.MM.yyyy"), this);
    ResponsibleLabel = new QLabel(tr("Name & Surname of victim:"), this);
    ResponsibleLine = new QLineEdit(this);

    DescriptionVictimPeculiarityLabel = new QLabel(tr("Description problem:"), this);
    DescriptionProblem = new QTextEdit(this);

    DescriptionProblemLabel = new QLabel(tr("Victim`s contraindication:"), this);
    DescriptionVictimPeculiarity = new QTextEdit(this);

    PhoneNumber = new QLabel(tr("Phone number person:"), this);
    EmailLine = new QLineEdit(this);

    OkBtn     = new QPushButton(tr("ok"));
    CancelBtn = new QPushButton(tr("cancel"));
}

 void AssistanceToVictim::PlacementComponents()
{

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(TimeNow);
    mainLayout->addWidget(ResponsibleLabel);
    mainLayout->addWidget(ResponsibleLine);
    mainLayout->addSpacing(10);

    mainLayout->addWidget(DescriptionVictimPeculiarityLabel);
    mainLayout->addWidget(DescriptionProblem);
    mainLayout->addSpacing(10);

    mainLayout->addWidget(DescriptionProblemLabel);
    mainLayout->addWidget(DescriptionVictimPeculiarity);
    mainLayout->addSpacing(10);


    QHBoxLayout* emailLabelsLayout = new QHBoxLayout;
    emailLabelsLayout->addWidget(PhoneNumber);

    mainLayout->addLayout(emailLabelsLayout);
    mainLayout->addWidget(EmailLine);
    mainLayout->addSpacing(10);

    QHBoxLayout* deadlineLabelsLayout = new QHBoxLayout;

    QHBoxLayout* deadLineLayout = new QHBoxLayout;

    mainLayout->addLayout(deadlineLabelsLayout);
    mainLayout->addLayout(deadLineLayout);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(CancelBtn);
    buttonsLayout->addWidget(OkBtn);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);
}

void AssistanceToVictim::MakeLogFile()
{

    const QString folderPath = "/home/vitaliy/Cpp/PetProjects/FireWatch/VictimsLog/";  // Пример для Windows

    QDir dir(folderPath);
    if (!dir.exists())
    {
        dir.mkpath(folderPath);  // Создаем всю структуру папок, если её нет
    }
    QTime currentTime = QTime::currentTime();
    QDate currentDate = QDate::currentDate();
    QFile file(folderPath + currentTime.toString("HH:mm:ss_") + currentDate.toString("dd.MM.yyyy_") + "victim_report.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);

        out << TimeNow->text() << "\n";
        out << ResponsibleLabel->text() + " " << ResponsibleLine->text() << "\n";
        out << DescriptionVictimPeculiarityLabel->text() + " " << DescriptionProblem->toPlainText() << "\n";
        out << DescriptionProblemLabel->text()  + " " << DescriptionVictimPeculiarity->toPlainText() << "\n";
        out << PhoneNumber->text() + " " << EmailLine->text() << "\n";

        file.close();
        qDebug() << "Данные успешно записаны в файл.";
    }
    else
    {
        qDebug() << "Ошибка при открытии файла для записи.";
    }

    accept();
}

AssistanceToVictim::AssistanceToVictim(QWidget *parent) : QDialog(parent)
{
    SettingFields();
    PlacementComponents();
    connect(OkBtn,     &QPushButton::clicked, this, &AssistanceToVictim::MakeLogFile);
    connect(CancelBtn, &QPushButton::clicked, this, &QDialog::reject);

    setWindowTitle(tr("Report extremal situation"));
    setFixedSize(500,500);
}
