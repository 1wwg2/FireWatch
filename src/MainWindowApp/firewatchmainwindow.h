#ifndef FIREWATCHMAINWINDOW_H
#define FIREWATCHMAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QStackedWidget>

#include "src/ControlPanels/mainmenubar.h"
#include "src/ControlPanels/toolpanel.h"
#include "src/FormForReport/forestdataform.h"
#include "src/MakeShedules/scheduleofweather.h"
#include "src/HelpVictimDialog/assistancetovictim.h"

class FireWatchMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    MainMenuBar* Bar;
    ToolPanel* Panel;
    QStackedWidget* StackedWidget;
    ForestDataForm* FormToEnterData;
    ScheduleOfWeather* Shedules;
    AssistanceToVictim* DataOfVictim;

    void InitializationField(const QString& NameWorker);
    void SettingField();
    void PlacementComponents();

private slots:
    void SelectForestDataForm();
    void SelectScheduleOfWeather();
    void SelectAssistanceToVictim();

public:
    FireWatchMainWindow(const QString& NameWorker, QMainWindow* parent = nullptr);

};

#endif // FIREWATCHMAINWINDOW_H
