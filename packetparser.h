#ifndef PACKETPARSER_H
#define PACKETPARSER_H

#include <iostream>
#include <iomanip>
#include <pcap.h>
#include <libnet.h>
#include <netinet/in.h>

class PacketParser
{
private:
    const u_char *source;

    void getEthernetInfo(const u_char *source);
    int getIPInfo(const u_char *source);
    int getPortInfo(const u_char *source);

public:
    PacketParser();
    void printPacketInfo(const u_char *source);
};

#endif // PACKETPARSER_H
