TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpcap

SOURCES += \
        Packet.cpp \
        PacketParser.cpp \
        PacketStatic.cpp \
        main.cpp

HEADERS += \
    Packet.h \
    PacketParser.h \
    PacketStatic.h
