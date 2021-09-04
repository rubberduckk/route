#ifndef PACKET_H
#define PACKET_H

#include <iostream>
#include <cstdio>
#include <pcap.h>
#include <libnet.h>
#include <netinet/in.h>
#include <string>
#include "PacketStatic.h"
using namespace std;

class Packet {
private:
    string strsmac, strdmac;
    uint32_t sip, dip;
    uint16_t sport, dport;
    struct pcap_pkthdr *header;
public:
    Packet();
    void saveip(uint32_t sip, uint32_t dip);
    void saveport(uint16_t sport, uint16_t dport);
    void savemac(u_char *smac, u_char *dmac);
    void saveheader(pcap_pkthdr *header);
    void printinfo(PacketStatic *ps);
};

#endif // PACKET_H
