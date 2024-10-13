#include "src/LoginToApp/logintoapp.h"

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
   //LoginToApp* fire = new LoginToApp();
    FireWatchMainWindow* fire = new FireWatchMainWindow("1");
    fire->show();

    return app.exec();
}


// test
/* CREATE TABLE employees (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    full_name TEXT NOT NULL,
    password TEXT NOT NULL
    );

CREATE TABLE reports (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    employee_id INTEGER,
    temperature REAL NOT NULL,
    wind_speed REAL NOT NULL,
    weather TEXT NOT NULL,
    report_date DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (employee_id) REFERENCES employees (id)
    )


INSERT INTO employees (full_name, password) VALUES ('Имя Фамилия', 'ваш_пароль');*/
