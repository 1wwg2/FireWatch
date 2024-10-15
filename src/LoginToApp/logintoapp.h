#ifndef LOGINTOAPP_H
#define LOGINTOAPP_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QScreen>
#include <QFont>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>

#include "src/MainWindowApp/firewatchmainwindow.h"

namespace SettingPathDb
{
    const QString dbPath = "Path_To_Your_File_Db/dump/employ.db";
    const QString UrlApi("Url_To_Your_API");
}

class LoginToApp : public QWidget
{
    Q_OBJECT

private:
    QLabel* LogoApp;
    QLabel* LogoUser;
    QLineEdit* LoginUser;
    QLabel* LogoPass;
    QLineEdit* PasswordUser;
    QPushButton* EnterData;

    void InitializationField();
    void SettingField();
    void PlacementComponents();
    void CenterWindow();
    void CheckWorkDataBase();

private slots:
    void CheckData();
public:
   explicit LoginToApp(QWidget* parent = nullptr);

};

#endif // LOGINTOAPP_H
