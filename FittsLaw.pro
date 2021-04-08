QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

HEADERS += \
    ./src/fittsmodel.h \
    ./utils/graphicwidget.h \
    ./src/mainview.h \
    ./src/experienceview.h \
    ./src/fittscontroller.h \
    ./src/resultsview.h

SOURCES += \
    ./utils/graphicwidget.cpp \
    ./src/experienceview.cpp \
    ./src/fittscontroller.cpp \
    ./src/fittsmodel.cpp \
    ./src/mainview.cpp \
    ./src/resultsview.cpp \
    main.cpp \


FORMS += \
    ./gui/experienceview.ui \
    ./gui/mainView.ui \
    ./gui/resultsview.ui

INCLUDEPATH +=  \
    ./utils \
    ./src \
    ./gui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourceFile.qrc
