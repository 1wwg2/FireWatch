#include "src/LoginToApp/logintoapp.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LoginToApp* fire = new LoginToApp();
    fire->show();
    return app.exec();
}
