TARGET = fossilinkd

CONFIG += cmdline

QT -= gui
QT += dbus

CONFIG += link_pkgconfig
PKGCONFIG += mlite5

DEFINES += APP_NAME=\\\"$$TARGET\\\" APP_VERSION=\\\"$$VERSION\\\"

SOURCES += \
    src/service.cpp

HEADERS += \
    src/manager.h \
    src/settings.h


INSTALLS += systemd
systemd.files = $${TARGET}.service
systemd.path = /usr/lib/systemd/user


# unnecesary includes, just so QtCreator could find headers... :-(
INCLUDEPATH += $$[QT_HOST_PREFIX]/include/mlite5
