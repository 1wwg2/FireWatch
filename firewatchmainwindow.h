#ifndef FIREWATCHMAINWINDOW_H
#define FIREWATCHMAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QStackedWidget>


#include "mainmenubar.h"
#include "toolpanel.h"
#include "forestdataform.h"
#include "scheduleofweather.h"
#include "assistancetovictim.h"

class FireWatchMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    MainMenuBar* Bar;
    ToolPanel* Panel;

    QStackedWidget* stackedWidget;
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
