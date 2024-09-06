#include "toolpanel.h"

void ToolPanel::InitializationField()
{
    ForestDataForm = new QAction(QIcon(":/resourses/ToolPanel/Trees.png"), "Enter data", this);
    GraphBuildForm = new QAction(QIcon(":/resourses/ToolPanel/Weather.png"), "Schedule Weather", this);
    HelpVictimForm = new QAction(QIcon(":/resourses/ToolPanel/Help.png"), "Help Victim", this);
}

void ToolPanel::SettingField()
{
    setMovable(false);
    setFixedHeight(50);
    setIconSize(QSize(32, 32));
    addAction(ForestDataForm);
    addAction(GraphBuildForm);
    addAction(HelpVictimForm);
}

ToolPanel::ToolPanel(QWidget* parent) : QToolBar(parent)
{
    InitializationField();
    SettingField();
}
