#include "PacketParser.h"
using namespace std;

// constructor
PacketParser::PacketParser(char *str) {
    this->handle = pcap_open_live(str, BUFSIZ, 1, 1000, errbuf);
    if (this->handle == NULL) {
        fprintf(stderr, "pcap_open_live(%s) return nullptr - %s\n", str, errbuf);
        exit(-1);
    }
}

int PacketParser::getRes() { return this->res; }

pcap_t* PacketParser::getHandle() { return this->handle; }

void PacketParser::getEthernetInfo(const u_char *source) {
    // static header size: 14 bytes
    struct libnet_ethernet_hdr *eth = (libnet_ethernet_hdr *)source;

    // save mac address
    for (int i=0; i<ETHER_ADDR_LEN; i++)
         getElements(eth->ether_shost[i], eth->ether_dhost[i]);
}

int PacketParser::getIPInfo(const u_char *source) {
    // static header size: 20 bytes
    struct libnet_ipv4_hdr *ipv = (libnet_ipv4_hdr *)source;

    // save ip address
    getElements(ntohl(ipv->ip_src.s_addr), ntohl(ipv->ip_dst.s_addr));

    return ipv->ip_hl*4;
}

void PacketParser::getPortInfo(const u_char *source) {
    // static header size: 20 bytes
    struct libnet_tcp_hdr *tcp = (libnet_tcp_hdr *)source;

    // save port address
    getElements(ntohs(tcp->th_sport), ntohs(tcp->th_dport));
}

void PacketParser::run() {
    this->res = pcap_next_ex(this->handle, &this->header, &this->source);

    this->getEthernetInfo(this->source);
    this->getIPInfo(this->source);
    this->getPortInfo(this->source);
}

// destructor
PacketParser::~PacketParser() {
    pcap_close(this->handle);
}
