TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    PacketParser.cpp \
    Packet.cpp

HEADERS += \
    PacketParser.h \
    Packet.h
