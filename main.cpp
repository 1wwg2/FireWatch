#include "src/LoginToApp/logintoapp.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LoginToApp* fire = new LoginToApp();
    fire->show();
    return app.exec();
}


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
