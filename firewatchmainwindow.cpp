#include "firewatchmainwindow.h"

void FireWatchMainWindow::InitializationField()
{
      Bar = new MainMenuBar(this);
}

void FireWatchMainWindow::SettingField()
{

}

void FireWatchMainWindow::PlacementComponents()
{
    setMenuBar(Bar);
}

FireWatchMainWindow::FireWatchMainWindow(QMainWindow* parent) : QMainWindow(parent)
{
    InitializationField();
    PlacementComponents();
    setMinimumSize(700, 700);
   // showMaximized();

}

