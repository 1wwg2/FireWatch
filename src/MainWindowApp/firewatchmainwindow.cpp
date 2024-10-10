#include "firewatchmainwindow.h"

void FireWatchMainWindow::InitializationField(const QString& NameWorker)
{
    Bar = new MainMenuBar(this);
    Panel = new ToolPanel(this);

    stackedWidget = new QStackedWidget(this);
    FormToEnterData = new ForestDataForm(NameWorker, this);
    Shedules = new ScheduleOfWeather(this);

}

void FireWatchMainWindow::SettingField()
{
    stackedWidget->addWidget(FormToEnterData);
    stackedWidget->addWidget(Shedules);
    // stackedWidget->addWidget(DataOfVictim);
}

void FireWatchMainWindow::PlacementComponents()
{
    setMenuBar(Bar);
    addToolBar(Panel);
    setCentralWidget(stackedWidget);

    setWindowIcon(QIcon(":/resourses/LoginForm/FirewatchIcon.png"));
    setMinimumSize(700, 700);
}

void FireWatchMainWindow::SelectForestDataForm()
{
   stackedWidget->setCurrentIndex(0);
}

void FireWatchMainWindow::SelectScheduleOfWeather()
{
    stackedWidget->setCurrentIndex(1);
}

void FireWatchMainWindow::SelectAssistanceToVictim()
{
    AssistanceToVictim* DataOfVictimq = new AssistanceToVictim(this);
    DataOfVictimq->show();
}

FireWatchMainWindow::FireWatchMainWindow(const QString& NameWorker, QMainWindow* parent) : QMainWindow(parent)
{
    InitializationField(NameWorker);
    SettingField();
    PlacementComponents();

    connect(Panel->GetForestDataForm(), &QAction::triggered, this, &FireWatchMainWindow::SelectForestDataForm);
    connect(Panel->GetGraphBuildForm(), &QAction::triggered, this, &FireWatchMainWindow::SelectScheduleOfWeather);
    connect(Panel->GetHelpVictimForm(), &QAction::triggered, this, &FireWatchMainWindow::SelectAssistanceToVictim);

    showMaximized();

}

