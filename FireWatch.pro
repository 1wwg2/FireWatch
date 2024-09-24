QT = core gui widgets sql charts

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        $$PWD/src/HelpVictimDialog/assistancetovictim.cpp \
        $$PWD/src/FormForReport/customtablewidget.cpp \
        $$PWD/src/MainWindowApp/firewatchmainwindow.cpp \
        $$PWD/src/FormForReport/forestdataform.cpp \
        $$PWD/src/FormForReport/helpdialog.cpp \
        $$PWD/src/LoginToApp/logintoapp.cpp \
        main.cpp \
        $$PWD/src/ControlPanels/mainmenubar.cpp \
        $$PWD/src/MakeShedules/scheduleofweather.cpp \
        $$PWD/src/ControlPanels/toolpanel.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    $$PWD/src/HelpVictimDialog/assistancetovictim.h \
    $$PWD/src/FormForReport/customtablewidget.h \
    $$PWD/src/MainWindowApp/firewatchmainwindow.h \
    $$PWD/src/FormForReport/forestdataform.h \
    $$PWD/src/FormForReport/helpdialog.h \
    $$PWD/src/LoginToApp/logintoapp.h \
    $$PWD/src/ControlPanels/mainmenubar.h \
    $$PWD/src/MakeShedules/scheduleofweather.h \
    $$PWD/src/ControlPanels/toolpanel.h

RESOURCES += \
    resourses.qrc

DISTFILES +=
