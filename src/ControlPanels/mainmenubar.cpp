#include "mainmenubar.h"

void MainMenuBar::InitializationField()
{
    InstructionsForHelpPeople.reset(new HelpDialog());

    AboutProgramAction = new QAction("&About Program", this);
    FirstHelpVictimAction = new QAction("&First Help Victim", this);
    SettingsMenu = new QMenu("&Settings", this);

    ChangeLang = new QMenu("Language");
                                            /*TODO: Не забыть попробовать поубирать зис, чтоб убрать проблему с wayland*/
    LangUsaAction = new QAction(QIcon(":/resourses/MenuBar/CountryLogos/USD.png"), "American");
    LangRuAction = new QAction(QIcon(":/resourses/MenuBar/CountryLogos/RUB.png"), "Russian");
    LangUaAction = new QAction(QIcon(":/resourses/MenuBar/CountryLogos/UAH.png"), "Ukrainian", this);

    ChangeTheme = new QMenu("Theme");
    LightThemeAction = new QAction(QIcon(":/resourses/MenuBar/DarkAndLightTheme/Light.png"), "Light");
    DarkThemeAction = new QAction(QIcon(":/resourses/MenuBar/DarkAndLightTheme/Dark.png"), "Dark");

}

void MainMenuBar::SettingField()
{
    SettingsMenu->addMenu(ChangeLang);
    ChangeLang->setIcon(QIcon(":/resourses/MenuBar/DarkAndLightTheme/ChangeLanguage.png"));
    ChangeLang->addAction(LangUsaAction);
    ChangeLang->addAction(LangRuAction);
    ChangeLang->addAction(LangUaAction);

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
    QDesktopServices::openUrl(QUrl("https://github.com/1wwg2/FireWatch/blob/main/README.md")); //поставить ссылку на рид.md
}

void MainMenuBar::OpenHelpRules()
{
    InstructionsForHelpPeople->show();
}


void MainMenuBar::SetDarkTheme()
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

MainMenuBar::MainMenuBar(QWidget* parent) : QMenuBar(parent)
{
    InitializationField();
    SettingField();
    PlacementComponents();

    connect(AboutProgramAction, &QAction::triggered, this, &MainMenuBar::OpenAboutProjectUrl);
    connect(FirstHelpVictimAction, &QAction::triggered, this, &MainMenuBar::OpenHelpRules);
}
