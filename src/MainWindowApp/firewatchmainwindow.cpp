#include "firewatchmainwindow.h"

void FireWatchMainWindow::InitializationField(const QString& NameWorker)
{
    Bar = new MainMenuBar(this);
    Panel = new ToolPanel(this);

    StackedWidget = new QStackedWidget(this);
    FormToEnterData = new ForestDataForm(NameWorker, this);
    Shedules = new ScheduleOfWeather(this);

}

void FireWatchMainWindow::SettingField()
{
    StackedWidget->addWidget(FormToEnterData);
    StackedWidget->addWidget(Shedules);
}

void FireWatchMainWindow::PlacementComponents()
{
    setMenuBar(Bar);
    addToolBar(Panel);
    setCentralWidget(StackedWidget);

    setWindowIcon(QIcon(":/resourses/LoginForm/FirewatchIcon.png"));
    setMinimumSize(700, 700);
}

void FireWatchMainWindow::SelectForestDataForm()
{
    StackedWidget->setCurrentIndex(0);
}

void FireWatchMainWindow::SelectScheduleOfWeather()
{
    StackedWidget->setCurrentIndex(1);
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
    setMinimumSize(1000, 1000);
    showMaximized();

}
