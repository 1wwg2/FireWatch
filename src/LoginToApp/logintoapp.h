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
    const QString dbPath = "/home/vitaliy/Cpp/PetProjects/FireWatch/dump/employ.db";
    const QString UrlApi("https://api.openweathermap.org/data/2.5/forecast?lat=50.00&lon=36.99&appid=6c1d47b799f721b19e70f329e97f00e3&units=metric");
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
