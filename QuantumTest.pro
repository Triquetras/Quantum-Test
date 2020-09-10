QT += quick qml

CONFIG += c++11


HEADERS += \
    appcore.h \
    filetablemodel.h

SOURCES += \
        appcore.cpp \
        filetablemodel.cpp \
        main.cpp

CODECFORSRC     = UTF-8

RESOURCES += qml.qrc

QML_IMPORT_PATH =

QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
