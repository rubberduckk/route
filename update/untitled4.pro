TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpcap
LIBS += -lpthread

SOURCES += \
        Packet.cpp \
        PacketParser.cpp \
        PacketStatic.cpp \
        Whitelistupdater.cpp \
        main.cpp \
        userinfo.cpp

HEADERS += \
    Packet.h \
    PacketParser.h \
    PacketStatic.h \
    Whitelistupdater.h \
    userinfo.h
