#ifndef PACKET_H
#define PACKET_H

#include <iostream>
#include <pcap.h>
#include <libnet.h>
#include <netinet/in.h>
#include <map>
#include <string>

using namespace std;

class Packet {
private:
    map<uint8_t, uint8_t> macInfo;
    map<in_addr, in_addr> ipInfo;
    map<uint16_t, uint16_t> portInfo;
public:
    Packet();

    void getElements(uint8_t one, uint8_t another);     // for mac
    void getElements(in_addr one, in_addr another);     // for ip
    void getElements(uint16_t one, uint16_t another);   // for port
};

#endif // PACKET_H
