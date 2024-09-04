#include "mainmenubar.h"

void MainMenuBar::InitializationField()
{
    AboutProgramAction = new QAction("About Program", this);
    ExploitationAction = new QAction("Exploitation", this);
    FirstHelpVictimAction = new QAction("First Help Victim", this);
    SettingsMenu = new QMenu("Settings", this);
    FAQAction = new QAction("FAQ", this);

    ChangeLang = new QMenu("Language", this);
    LangUsaAction = new QAction("American", this);
    LangRuAction = new QAction("Russian", this);
    LangUaAction = new QAction("Ukrainian", this);

    ChangeTheme = new QMenu("Theme", this);
    LightThemeAction = new QAction("Light", this);
    DarkThemeAction = new QAction("Dark", this);

}

void MainMenuBar::SettingField()
{
    SettingsMenu->addMenu(ChangeLang);
    ChangeLang->addAction(LangUsaAction);
    ChangeLang->addAction(LangRuAction);
    ChangeLang->addAction(LangUaAction);


    SettingsMenu->addMenu(ChangeTheme);
    ChangeTheme->addAction(LightThemeAction);
    ChangeTheme->addAction(DarkThemeAction);
}

void MainMenuBar::PlacementComponents()
{
    addAction(AboutProgramAction);
    addAction(ExploitationAction);
    addAction(FirstHelpVictimAction);
    addMenu(SettingsMenu);
    addAction(FAQAction);
}

void MainMenuBar::OpenAboutProjectUrl()
{
    QDesktopServices::openUrl(QUrl("https://github.com/1wwg2")); //поставить ссылку на рид.md
}

MainMenuBar::MainMenuBar(QWidget* parent) : QMenuBar(parent)
{
    InitializationField();
    SettingField();
    PlacementComponents();

    connect(AboutProgramAction, &QAction::triggered, this, &MainMenuBar::OpenAboutProjectUrl);
}
