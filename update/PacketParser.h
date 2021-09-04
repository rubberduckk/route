#ifndef PACKETPARSER_H
#define PACKETPARSER_H

#include <iostream>
#include <pcap.h>
#include <libnet.h>
#include <netinet/in.h>
#include "Packet.h"
using namespace std;

class PacketParser {
private:
    struct pcap_pkthdr *header;
    const u_char *source;
    pcap_t *handle;
    int res;
    int pos;
    char errbuf[PCAP_ERRBUF_SIZE];

    void getEthernetInfo(const u_char *source, Packet *ptr);
    int getIPInfo(const u_char *source, Packet *ptr);
    int getPortInfo(const u_char *source, Packet *ptr);
public:
    PacketParser(char *str);
    ~PacketParser();
    int getRes();
    bool run(Packet *ptr);
};

#endif // PACKETPARSER_H
