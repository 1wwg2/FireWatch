#include "logintoapp.h"


void LoginToApp::InitializationField()
{
    LogoApp = new QLabel(this);
    LogoUser = new QLabel(this);
    LoginUser = new QLineEdit(this);
    LogoPass = new QLabel(this);
    PasswordUser = new QLineEdit(this);
    EnterData = new QPushButton(this);
}

void LoginToApp::SettingField()
{
    QWidget::setWindowTitle("Login FireWatch");
    LogoApp->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QPixmap ToLogoApp(":/resourses/LoginForm/FirewatchLogo.png"); // не забыть поправить пути к файлам
    LogoApp->setPixmap(ToLogoApp);

    QPixmap ToLogoUser(":/resourses/LoginForm/FiremanLogo.png");
    QPixmap scaledToLogoUser = ToLogoUser.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    LogoUser->setPixmap(scaledToLogoUser);

    QPixmap ToLogoPassword(":/resourses/LoginForm/LogoPass.png");
    QPixmap scaledToLogoPassword = ToLogoPassword.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    LogoPass->setPixmap(scaledToLogoPassword);

    LoginUser->setFixedSize(350, 40);
    LoginUser->setStyleSheet("font-size: 24px;");
    LoginUser->setPlaceholderText("Full Name: ");

    PasswordUser->setFixedSize(350, 40);
    PasswordUser->setStyleSheet("font-size: 24px;");
    PasswordUser->setPlaceholderText("Password: ");
    PasswordUser->setEchoMode(QLineEdit::Password);

    EnterData->setText("Enter");
    EnterData->setFixedSize(200, 30);
}

void LoginToApp::PlacementComponents()
{
    QVBoxLayout* mainContainer = new QVBoxLayout();
    mainContainer->setContentsMargins(0, 20, 30, 0);
    mainContainer->addWidget(LogoApp, 0, Qt::AlignCenter);

    QHBoxLayout* LoginForm = new QHBoxLayout();
    LoginForm->setContentsMargins(0, 30, 46, 0);

    LoginForm->addStretch();
    LoginForm->addWidget(LogoUser, 0, Qt::AlignCenter);

    LoginForm->addWidget(LoginUser, 0, Qt::AlignCenter);
    LoginForm->addStretch();

    QHBoxLayout* LoginPassword = new QHBoxLayout();
    LoginPassword->setContentsMargins(0, 20, 46, 20);

    LoginPassword->addStretch();
    LoginPassword->addWidget(LogoPass, 0, Qt::AlignCenter);
    LoginPassword->addWidget(PasswordUser, 0, Qt::AlignCenter);
    LoginPassword->addStretch();

    QHBoxLayout* ButtonLayout = new QHBoxLayout();
    ButtonLayout->addStretch();
    ButtonLayout->setContentsMargins(1, 10, 0, 50);
    ButtonLayout->addWidget(EnterData, 0, Qt::AlignCenter);
    ButtonLayout->addStretch();

    mainContainer->addLayout(LoginForm);
    mainContainer->addLayout(LoginPassword);
    mainContainer->addLayout(ButtonLayout);

    setLayout(mainContainer);
}


void LoginToApp::CenterWindow()
{
    QList<QScreen*> screens = QApplication::screens();

    QScreen* screen = screens.value(0);
    QRect screenGeometry = screen->availableGeometry();

    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();

    QSize windowSize = size();
    int windowWidth = windowSize.width();
    int windowHeight = windowSize.height();

    int x = screenGeometry.x() + (screenWidth - windowWidth) / 2;
    int y = screenGeometry.y() + (screenHeight - windowHeight) / 2;

    move(x, y);
}

void LoginToApp::CheckWorkDataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = "/home/vitaliy/Qt_Projects/FireWatch/dump/employ.db";

    if (!QFile::exists(dbPath)) {
        QMessageBox::critical(this, "Ошибка базы данных", "Файл базы данных не существует. Пожалуйста, проверьте путь к файлу.");
        return;
    }

    db.setDatabaseName(dbPath);

    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка базы данных", "Пожалуйста, свяжитесь с технической поддержкой и сохраните данные другим способом.");
        return;
    }
    qDebug() << "База данных успешно открыта.";
}

void LoginToApp::CheckData()
{
    QString username = LoginUser->text().trimmed();
    QString password = PasswordUser->text().trimmed();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both your name and password.");
        return;
    }

    qDebug() << "Trying to login with Username:" << username << "and Password:" << password;

    QSqlQuery query;
    query.prepare("SELECT id FROM employees WHERE full_name = :full_name AND password = :password");
    query.bindValue(":full_name", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        QMessageBox::critical(this, "Database Error", query.lastError().text());
        return;
    }

    if (query.next()) {
        qDebug() << "Login successful!";
        FireWatchMainWindow* fire = new FireWatchMainWindow();
        fire->show();
        close();
    } else {
        qDebug() << "Login failed!";
        QMessageBox::critical(this, "Login Failed", "Your Name or Password is incorrect.\nPlease try again.");
        PasswordUser->clear();
    }
}



LoginToApp::LoginToApp(QWidget* parent) : QWidget(parent)
{
    CheckWorkDataBase();
    InitializationField();
    SettingField();
    PlacementComponents();
    setFixedSize(900, 600);
    CenterWindow();

    connect(EnterData, &QPushButton::clicked, this, &LoginToApp::CheckData);
    // ИКОНКА ОБЯЗАТЕЛЬНО
    // НЕ ЗАБЫВАТЬ ПРО АРХИТЕКТУРУ ДИРЕКТОРИЙ ИКОНОК И КАРТИНОК
    // TODO: Модальные окна обработки ошибок с паролем и дата базой

}


