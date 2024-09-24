QT = core gui widgets sql charts

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/HelpVictimDialog/assistancetovictim.cpp \
        src/FormForReport/customtablewidget.cpp \
        src/MainWindowApp/firewatchmainwindow.cpp \
        src/FormForReport/forestdataform.cpp \
        src/FormForReport/helpdialog.cpp \
        src/LoginToApp/logintoapp.cpp \
        main.cpp \
        src/ControlPanels/mainmenubar.cpp \
        src/MakeShedules/scheduleofweather.cpp \
        src/ControlPanels/toolpanel.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/HelpVictimDialog/assistancetovictim.h \
    src/FormForReport/customtablewidget.h \
    src/MainWindowApp/firewatchmainwindow.h \
    src/FormForReport/forestdataform.h \
    src/FormForReport/helpdialog.h \
    src/LoginToApp/logintoapp.h \
    src/ControlPanels/mainmenubar.h \
    src/MakeShedules/scheduleofweather.h \
    src/ControlPanels/toolpanel.h

RESOURCES += \
    resourses.qrc

DISTFILES +=
