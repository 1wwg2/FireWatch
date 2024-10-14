-- Create login and pass 
 CREATE TABLE employees (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    full_name TEXT NOT NULL,
    password TEXT NOT NULL
    );

-- Information from weather and enviroment 
CREATE TABLE reports (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    employee_id INTEGER,
    temperature REAL NOT NULL,
    wind_speed REAL NOT NULL,
    weather TEXT NOT NULL,
    report_date DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (employee_id) REFERENCES employees (id)
    )

-- If you need to add employ
-- INSERT INTO employees (full_name, password) VALUES ('Name', 'Password')
