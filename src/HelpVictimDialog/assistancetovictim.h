#ifndef ASSISTANCETOVICTIM_H
#define ASSISTANCETOVICTIM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QTime>
#include <QFile>
#include <QDir>
#include <QStandardPaths>

class AssistanceToVictim : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* responsibleLine;
    QLineEdit* emailLine;
    QTextEdit* description;
    QTextEdit* descriptionVictim;

    QLabel* TimeNow;
    QLabel* responsibleLabel;
    QLabel* descriptionL;
    QLabel* descriptionLabel;
    QLabel* PhoneNumber;
    QPushButton* okBtn;
    QPushButton* cancelBtn;

    void SettingFields();
    void PlacementComponents();
private slots:

    void MakeLogFile();
public:
    explicit AssistanceToVictim(QWidget *parent = nullptr);
};

#endif // ASSISTANCETOVICTIM_H
