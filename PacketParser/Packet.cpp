#include "Packet.h"

void Packet::getElements(uint8_t one, uint8_t another) {
    macInfo.insert(one, another);

    if (macInfo.find(one) != macInfo.end())
        cout << "There's no data just pushed" << endl;
}

void Packet::getElements(in_addr one, in_addr another) {
    ipInfo.insert(one, another);

    if (ipInfo.find(one) != ipInfo.end())
        cout << "There's no data just pushed" << endl;
}

void Packet::getElements(uint16_t one, uint16_t another) {
    portInfo.insert(one, another);

    if (portInfo.find(one) != portInfo.end())
        cout << "There's no data just pushed" << endl;
}

