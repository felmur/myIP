QT -= gui

QT += core network

LIBS = -ljsoncpp

TEMPLATE = lib
VERSION = 1.0.3

DEFINES += MYIP_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    myip.cpp

HEADERS += \
    myIP_global.h \
    myip.h


target.path = /usr/lib
inc.path = /usr/include
inc.files = myip.h myIP_global.h
doc.path = /usr/share/libmyIP
doc.files = README.md LICENSE

INSTALLS += target inc doc

DISTFILES += \
    LICENSE \
    README.md
