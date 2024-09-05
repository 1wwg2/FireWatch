#ifndef MAINMENUBAR_H
#define MAINMENUBAR_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFrame>
#include <QWidgetAction>
#include <QHBoxLayout>
#include <QDesktopServices>
#include <QUrl>
#include <QIcon>
#include <QStyle>
#include <QScopedPointer>

#include "helpdialog.h"
/*TODO: Добавить Картинку первой мед помощи
        Реализовать считывание labeltext в qdialog, через считывание txt файла
        Добавить хот кеи*/

class MainMenuBar : public QMenuBar
{
    Q_OBJECT
private:
      QScopedPointer<HelpDialog> InstructionsForHelpPeople;
    QAction* AboutProgramAction;
    QAction* FirstHelpVictimAction;
    QMenu* SettingsMenu;

    QMenu*  ChangeLang;
    QAction* LangUsaAction;
    QAction* LangRuAction;
    QAction* LangUaAction;


    QMenu* ChangeTheme;
    QAction* LightThemeAction;
    QAction* DarkThemeAction;

    void InitializationField();
    void SettingField();
    void PlacementComponents();
private slots:
    void OpenAboutProjectUrl();
    void OpenHelpRules();
public:
    MainMenuBar(QWidget* parent = nullptr);
};

#endif // MAINMENUBAR_H
