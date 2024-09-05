#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QTextBrowser>

class HelpDialog : public QDialog
{
    Q_OBJECT
private:
      QTextBrowser* textBrowser;

    void LoadFileContent(const QString& FilePath);

public:
    HelpDialog(QDialog* parent = nullptr);

};

#endif // HELPDIALOG_H
