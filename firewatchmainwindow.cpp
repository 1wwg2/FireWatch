#include "firewatchmainwindow.h"

void FireWatchMainWindow::InitializationField()
{
    Bar = new MainMenuBar(this);
    Panel = new ToolPanel(this);
}

void FireWatchMainWindow::SettingField()
{

}

void FireWatchMainWindow::PlacementComponents()
{
    setMenuBar(Bar);
    addToolBar(Panel);
}

FireWatchMainWindow::FireWatchMainWindow(QMainWindow* parent) : QMainWindow(parent)
{
    InitializationField();
    PlacementComponents();
    setWindowIcon(QIcon(":/resourses/LoginForm/FirewatchIcon.png"));
    setMinimumSize(700, 700);
   // showMaximized();

}

