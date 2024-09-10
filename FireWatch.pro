QT = core gui widgets

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        assistancetovictim.cpp \
        customtablewidget.cpp \
        firewatchmainwindow.cpp \
        forestdataform.cpp \
        helpdialog.cpp \
        logintoapp.cpp \
        main.cpp \
        mainmenubar.cpp \
        scheduleofweather.cpp \
        toolpanel.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    assistancetovictim.h \
    customtablewidget.h \
    firewatchmainwindow.h \
    forestdataform.h \
    helpdialog.h \
    logintoapp.h \
    mainmenubar.h \
    scheduleofweather.h \
    toolpanel.h

RESOURCES += \
    resourses.qrc

DISTFILES +=
