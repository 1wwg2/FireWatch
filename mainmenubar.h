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

class MainMenuBar : public QMenuBar
{
    Q_OBJECT
private:
    QAction* AboutProgramAction;
    QAction* ExploitationAction;
    QAction* FirstHelpVictimAction;
    QAction* FAQAction;
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
public slots:
   void OpenAboutProjectUrl();
public:
    MainMenuBar(QWidget* parent = nullptr);
};

#endif // MAINMENUBAR_H
