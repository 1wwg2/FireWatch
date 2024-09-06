#ifndef FIREWATCHMAINWINDOW_H
#define FIREWATCHMAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>

#include "mainmenubar.h"
#include "toolpanel.h"

class FireWatchMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    MainMenuBar* Bar;
    ToolPanel* Panel;

    void InitializationField();
    void SettingField();
    void PlacementComponents();
public:
    FireWatchMainWindow(QMainWindow* parent = nullptr);

};

#endif // FIREWATCHMAINWINDOW_H
