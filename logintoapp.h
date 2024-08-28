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
private slots:
    void CheckData();
public:
   explicit LoginToApp(QWidget* parent = nullptr);

};

#endif // LOGINTOAPP_H
