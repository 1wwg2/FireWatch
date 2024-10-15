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
    QLineEdit* ResponsibleLine;
    QLineEdit* EmailLine;
    QTextEdit* DescriptionProblem;
    QTextEdit* DescriptionVictimPeculiarity;
    QLabel* TimeNow;
    QLabel* ResponsibleLabel;
    QLabel* DescriptionProblemLabel;
    QLabel* DescriptionVictimPeculiarityLabel;
    QLabel* PhoneNumber;
    QPushButton* OkBtn;
    QPushButton* CancelBtn;

    void SettingFields();
    void PlacementComponents();

private slots:
    void MakeLogFile();

public:
    explicit AssistanceToVictim(QWidget *parent = nullptr);
};

#endif // ASSISTANCETOVICTIM_H
