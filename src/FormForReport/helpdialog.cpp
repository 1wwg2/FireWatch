#include "helpdialog.h"

HelpDialog::HelpDialog(QDialog* parent) : QDialog(parent)
{
    textBrowser = new QTextBrowser(this);
    setFixedSize(700, 1000);
    setModal(false);
    setWindowTitle("First Help Instructions");
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(textBrowser);

    LoadFileContent(":/resourses/MenuBar/FirstAid/FirstHelpInstruction.html");

}

void HelpDialog::LoadFileContent(const QString& FilePath)
{
    QFile file(FilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Unable to open file.");
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    textBrowser->setHtml(content);

    file.close();
}
