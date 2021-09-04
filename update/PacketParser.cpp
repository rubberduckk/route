#include "PacketParser.h"

// constructor
PacketParser::PacketParser(char *str) {
    this->handle = pcap_open_live(str, BUFSIZ, 1, 1000, errbuf);
    if (this->handle == NULL) {
        fprintf(stderr, "pcap_open_live(%s) return nullptr - %s\n", str, errbuf);
        exit(-1);
    }
}

int PacketParser::getRes() {
    return this->res;
}

void PacketParser::getEthernetInfo(const u_char *source, Packet *ptr) {
    // static header size: 14 bytes
    struct libnet_ethernet_hdr *eth = (libnet_ethernet_hdr *)source;

    // save mac address
    ptr->savemac(eth->ether_shost, eth->ether_dhost);
    //**** ptr->smac = eth->ether_shost;
    //**** ptr->dmac = eth->ether_dhost;
}

int PacketParser::getIPInfo(const u_char *source, Packet *ptr) {
    // static header size: 20 bytes
    struct libnet_ipv4_hdr *ipv = (libnet_ipv4_hdr *)source;

    // save ip address
    ptr->saveip(ntohl(ipv->ip_src.s_addr), ntohl(ipv->ip_dst.s_addr));

    return ipv->ip_hl*4;
}

int PacketParser::getPortInfo(const u_char *source, Packet *ptr) {
    // static header size: 20 bytes
    struct libnet_tcp_hdr *tcp = (libnet_tcp_hdr *)source;

    // save port address
    ptr->saveport(ntohs(tcp->th_sport), ntohs(tcp->th_dport));

    return tcp->th_off*4;
}

bool PacketParser::run(Packet *ptr) {
    this->res = pcap_next_ex(this->handle, &this->header, &this->source);
    this->pos = 0;
    ptr->saveheader(this->header);

    libnet_ipv4_hdr *ipv = (libnet_ipv4_hdr *)(this->source + 14);
    if(ipv->ip_p != 6)  return false;   // judge if the one is a TCP

    getEthernetInfo(this->source, ptr);
    pos = getIPInfo(this->source + 14, ptr);
    pos += getPortInfo(this->source + 14 + pos, ptr);

    return true;
}

// destructor
PacketParser::~PacketParser() {
    pcap_close(this->handle);
}
