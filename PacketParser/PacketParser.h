#ifndef PACKETPARSER_H
#define PACKETPARSER_H

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <pcap.h>
#include <libnet.h>
#include <netinet/in.h>

class PacketParser {
private:
    friend class Packet;

    struct pcap_pkthdr *header;
    const u_char *source;
    pcap_t *handle;
    int res;
    char errbuf[PCAP_ERRBUF_SIZE];

    void getEthernetInfo(const u_char *source);
    int getIPInfo(const u_char *source);
    void getPortInfo(const u_char *source);

public:
    PacketParser(char *str);
    ~PacketParser();

    int getRes();
    pcap_t* getHandle();

    void run();
};

#endif // PACKETPARSER_H
