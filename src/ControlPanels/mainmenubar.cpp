#include "mainmenubar.h"

void MainMenuBar::InitializationField()
{
    InstructionsForHelpPeople.reset(new HelpDialog());

    AboutProgramAction = new QAction("&About Program", this);
    FirstHelpVictimAction = new QAction("&First Help Victim", this);
    SettingsMenu = new QMenu("&Settings", this);

    ChangeTheme = new QMenu("Theme");
    LightThemeAction = new QAction(QIcon(":/resourses/MenuBar/DarkAndLightTheme/Light.png"), "Light");
    DarkThemeAction = new QAction(QIcon(":/resourses/MenuBar/DarkAndLightTheme/Dark.png"), "Dark");

}

void MainMenuBar::SettingField()
{
    SettingsMenu->addMenu(ChangeTheme);
    ChangeTheme->setIcon(QIcon(":/resourses/MenuBar/DarkAndLightTheme/ChangeTheme.png"));
    ChangeTheme->addAction(LightThemeAction);
    ChangeTheme->addAction(DarkThemeAction);
}

void MainMenuBar::PlacementComponents()
{
    addAction(AboutProgramAction);
    addAction(FirstHelpVictimAction);
    addMenu(SettingsMenu);
}

void MainMenuBar::OpenAboutProjectUrl()
{
    QDesktopServices::openUrl(QUrl("https://github.com/1wwg2/FireWatch/blob/main/README.md"));
}

void MainMenuBar::OpenHelpRules()
{
    InstructionsForHelpPeople->show();
}

void MainMenuBar::SetLightTheme()
{
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    palette.setColor(QPalette::WindowText, Qt::black);
    palette.setColor(QPalette::Base, Qt::white);
    palette.setColor(QPalette::AlternateBase, Qt::lightGray);
    palette.setColor(QPalette::ToolTipBase, Qt::white);
    palette.setColor(QPalette::ToolTipText, Qt::black);
    palette.setColor(QPalette::Text, Qt::black);
    palette.setColor(QPalette::Button, Qt::white);
    palette.setColor(QPalette::ButtonText, Qt::black);
    palette.setColor(QPalette::BrightText, Qt::red);
    palette.setColor(QPalette::Link, QColor(42, 130, 218));

    qApp->setPalette(palette);
}
void MainMenuBar::SetDarkTheme()
{
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(30, 30, 30));
    palette.setColor(QPalette::WindowText, QColor(230, 230, 230));
    palette.setColor(QPalette::Base, QColor(40, 40, 40));
    palette.setColor(QPalette::AlternateBase, QColor(55, 55, 55));
    palette.setColor(QPalette::ToolTipBase, QColor(50, 50, 50));
    palette.setColor(QPalette::ToolTipText, QColor(230, 230, 230));
    palette.setColor(QPalette::Text, QColor(230, 230, 230));
    palette.setColor(QPalette::Button, QColor(50, 50, 50));
    palette.setColor(QPalette::ButtonText, QColor(230, 230, 230));
    palette.setColor(QPalette::BrightText, QColor(255, 0, 0));
    palette.setColor(QPalette::Link, QColor(42, 130, 218));

    qApp->setPalette(palette);


}

MainMenuBar::MainMenuBar(QWidget* parent) : QMenuBar(parent)
{
    InitializationField();
    SettingField();
    PlacementComponents();

    connect(AboutProgramAction, &QAction::triggered, this, &MainMenuBar::OpenAboutProjectUrl);
    connect(FirstHelpVictimAction, &QAction::triggered, this, &MainMenuBar::OpenHelpRules);
    connect(LightThemeAction, &QAction::triggered, this, &MainMenuBar::SetLightTheme);
    connect(DarkThemeAction, &QAction::triggered, this, &MainMenuBar::SetDarkTheme);
}
