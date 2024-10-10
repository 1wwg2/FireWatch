#include "assistancetovictim.h"

void AssistanceToVictim::SettingFields()
{
    QTime currentTime = QTime::currentTime();
    QDate currentDate = QDate::currentDate();
    TimeNow = new QLabel("Time report: " + currentTime.toString("HH:mm ") + currentDate.toString("dd.MM.yyyy"), this);
    responsibleLabel = new QLabel(tr("Name & Surname of victim:"), this);
    responsibleLine = new QLineEdit(this);

    descriptionLabel = new QLabel(tr("Description problem:"), this);
    description = new QTextEdit(this);

    descriptionL = new QLabel(tr("Victim`s contraindication:"), this);
    descriptionVictim = new QTextEdit(this);

    PhoneNumber = new QLabel(tr("Phone number person:"), this);
    emailLine = new QLineEdit(this);

    okBtn     = new QPushButton(tr("ok"));
    cancelBtn = new QPushButton(tr("cancel"));
}

 void AssistanceToVictim::PlacementComponents()
{

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(TimeNow);
    mainLayout->addWidget(responsibleLabel);
    mainLayout->addWidget(responsibleLine);
    mainLayout->addSpacing(10);

    mainLayout->addWidget(descriptionLabel);
    mainLayout->addWidget(description);
    mainLayout->addSpacing(10);

    mainLayout->addWidget(descriptionL);
    mainLayout->addWidget(descriptionVictim);
    mainLayout->addSpacing(10);


    QHBoxLayout* emailLabelsLayout = new QHBoxLayout;
    emailLabelsLayout->addWidget(PhoneNumber);

    mainLayout->addLayout(emailLabelsLayout);
    mainLayout->addWidget(emailLine);
    mainLayout->addSpacing(10);

    QHBoxLayout* deadlineLabelsLayout = new QHBoxLayout;

    QHBoxLayout* deadLineLayout = new QHBoxLayout;

    mainLayout->addLayout(deadlineLabelsLayout);
    mainLayout->addLayout(deadLineLayout);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(cancelBtn);
    buttonsLayout->addWidget(okBtn);
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
        out << responsibleLabel->text() + " " << responsibleLine->text() << "\n";
        out << descriptionLabel->text() + " " << description->toPlainText() << "\n";
        out << descriptionL->text()  + " " << descriptionVictim->toPlainText() << "\n";
        out << PhoneNumber->text() + " " << emailLine->text() << "\n";

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
    connect(okBtn,     SIGNAL(clicked()), SLOT(MakeLogFile()));
    connect(cancelBtn, SIGNAL(clicked()), SLOT(reject()));

    setWindowTitle(tr("Report extremal situation"));
    setFixedSize(500,500);
}
