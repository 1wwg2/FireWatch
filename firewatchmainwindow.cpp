#include "firewatchmainwindow.h"

void FireWatchMainWindow::InitializationField()
{
    Bar = new MainMenuBar(this);
    Panel = new ToolPanel(this);

    stackedWidget = new QStackedWidget(this);

    FormToEnterData = new ForestDataForm(this);
    Shedules = new ScheduleOfWeather(this);
    DataOfVictim = new AssistanceToVictim(this);
}

void FireWatchMainWindow::SettingField()
{
    stackedWidget->addWidget(FormToEnterData);
    stackedWidget->addWidget(Shedules);
    stackedWidget->addWidget(DataOfVictim);
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
     stackedWidget->setCurrentIndex(2);
    //Это тест, потом подумать, скорее всего это будет модальный диалог. Может сохранять дату в .тхт лог,
    // может высылать на почту
}

FireWatchMainWindow::FireWatchMainWindow(QMainWindow* parent) : QMainWindow(parent)
{
    InitializationField();
    SettingField();
    PlacementComponents();


    connect(Panel->GetForestDataForm(), &QAction::triggered, this, &FireWatchMainWindow::SelectForestDataForm);
    connect(Panel->GetGraphBuildForm(), &QAction::triggered, this, &FireWatchMainWindow::SelectScheduleOfWeather);
    connect(Panel->GetHelpVictimForm(), &QAction::triggered, this, &FireWatchMainWindow::SelectAssistanceToVictim);

    showMaximized();

    // showMaximized();
}

