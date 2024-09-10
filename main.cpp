#include "logintoapp.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
   //  QPalette palette;
   //  palette.setColor(QPalette::Window, Qt::white);
   //  palette.setColor(QPalette::WindowText, Qt::black);
   //  palette.setColor(QPalette::Base, Qt::white);
   //  palette.setColor(QPalette::AlternateBase, Qt::lightGray);
   //  palette.setColor(QPalette::ToolTipBase, Qt::white);
   //  palette.setColor(QPalette::ToolTipText, Qt::black);
   //  palette.setColor(QPalette::Text, Qt::black);
   //  palette.setColor(QPalette::Button, Qt::white);
   //  palette.setColor(QPalette::ButtonText, Qt::black);
   //  palette.setColor(QPalette::BrightText, Qt::red);
   //  palette.setColor(QPalette::Link, QColor(42, 130, 218));

   // app.setPalette(palette);
    FireWatchMainWindow* fire = new FireWatchMainWindow();
    fire->show();
    return app.exec();
}
