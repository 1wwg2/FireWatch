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

void LoginToApp::CheckData()
{
    if(LoginUser->text() == "" && PasswordUser->text() == "")
    {
        FireWatchMainWindow* fire = new FireWatchMainWindow();
        fire->show();
        close();
    }
    else
    {
        QMessageBox* BoxError = new QMessageBox(this);
        BoxError->setIcon(QMessageBox::Critical);
        BoxError->setWindowTitle("Login Failed");
        BoxError->setText("Your Name or Password is incorrect.\nPlease try again.");
        BoxError->exec();
        PasswordUser->clear();
    }
}

LoginToApp::LoginToApp(QWidget* parent) : QWidget(parent)
{
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


