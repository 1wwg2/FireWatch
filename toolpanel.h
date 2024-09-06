#ifndef TOOLPANEL_H
#define TOOLPANEL_H

#include <QToolBar>

class ToolPanel : public QToolBar
{
    Q_OBJECT
private:
    QAction* ForestDataForm;
    QAction* GraphBuildForm;
    QAction* HelpVictimForm;

    void InitializationField();
    void SettingField();
private slots:

public:
    ToolPanel(QWidget* parent = nullptr);
};

#endif // TOOLPANEL_H
