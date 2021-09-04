#include "Packet.h"

Packet::Packet(){}

void Packet::printinfo(PacketStatic *ps){
    cout << endl;
    cout << "mac: " << this->strsmac << "\t" << this->strdmac << endl;
    cout << "ip: " << ((this->sip & 0xFF000000) >> 24) << "." << ((this->sip & 0x00FF0000) >> 16) << "." << ((this->sip & 0x0000FF00) >> 8) << "." << (this->sip & 0x000000FF) << "\t" << ((this->dip & 0xFF000000) >> 24) << "." << ((this->dip & 0x00FF0000) >> 16) << "." << ((this->dip & 0x0000FF00) >> 8) << "." << (this->dip & 0x000000FF) << endl;
    cout << "port: " << this->sport << "\t"<< this->dport << endl;
    ps->savemac(this->strsmac, this->strdmac);
    ps->saveheader(this->header);
}

void Packet::saveip(uint32_t sip, uint32_t dip){
    this->sip = sip;
    this->dip = dip;
}

void Packet::saveport(uint16_t sport, uint16_t dport){
    this->sport = sport;
    this->dport = dport;
}

void Packet::saveheader(pcap_pkthdr *header){
    this->header = header;
}

void Packet::savemac(u_char *smac, u_char *dmac){
    char tmp[32];
    sprintf(tmp, "%02x:%02x:%02x:%02x:%02x:%02x", smac[0], smac[1], smac[2], smac[3], smac[4], smac[5]);
    this->strsmac = (string)tmp;
    sprintf(tmp, "%02x:%02x:%02x:%02x:%02x:%02x", dmac[0], dmac[1], dmac[2], dmac[3], dmac[4], dmac[5]);
    this->strdmac = (string)tmp;
}
