#include "Packet.h"
using namespace std;

Packet::Packet(){}

void Packet::printinfo(){
    cout << endl;
    printf("mac: %02x:%02x:%02x:%02x:%02x:%02x\t%02x:%02x:%02x:%02x:%02x:%02x\n", this->smac[0], this->smac[1], this->smac[2], this->smac[3], this->smac[4], this->smac[5], this->dmac[0], this->dmac[1], this->dmac[2], this->dmac[3], this->dmac[4], this->dmac[5]);
    //cout << this->smac << "\t"<< this->dmac << endl;
    cout << "ip: " << ((this->sip & 0xFF000000) >> 24) << "." << ((this->sip & 0x00FF0000) >> 16) << "." << ((this->sip & 0x0000FF00) >> 8) << "." << (this->sip & 0x000000FF) << "\t" << ((this->dip & 0xFF000000) >> 24) << "." << ((this->dip & 0x00FF0000) >> 16) << "." << ((this->dip & 0x0000FF00) >> 8) << "." << (this->dip & 0x000000FF) << endl;
    cout << "port: " << this->sport << "\t"<< this->dport << endl;
    cout << endl << "---------------------------------------------------------------" << endl;
}

void Packet::saveip(uint32_t sip, uint32_t dip){
    this->sip = sip;
    this->dip = dip;
}

void Packet::saveport(uint16_t sport, uint16_t dport){
    this->sport = sport;
    this->dport = dport;
}

void Packet::savemac(u_char *smac, u_char *dmac){
    this->smac = smac;
    this->dmac = dmac;
}
