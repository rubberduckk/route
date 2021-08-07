#include <iostream>
#include <iomanip>
#include <pcap.h>
#include <libnet.h>
#include <netinet/in.h>
#include "PacketParser.h"

using namespace std;

class PacketParser {
private:
    const u_char *source;
    int res;
public:
    PacketParser();
    void getEthernetInfo(const u_char *source);
    int getIPInfo(const u_char *source);
    int getPortInfo(const u_char *source);
    void printPacketInfo(const u_char *source);
};

void PacketParser::getEthernetInfo(constr u_char *source) {
    // static header size: 14 bytes
    struct libnet_ethernet_hdr *eth = (libnet_ethernet_hdr *)source;

    // print source mac address
    for (int i=0; i<ETHER_ADDR_LEN; i++) {
        cout << "Src MAC: " << setw(2) << setfill('0') << hex << eth->ether_shost[i] << ":";
        if ((i+1) == ETHER_ADDR_LEN -1)
            cout << setw(2) << setfill('0') << hex << eth->ether_shost[++i]; i++;
    }
    cout << "/t";
    // print destination mac address
    for (int i=0; i<ETHER_ADDR_LEN; i++) {
        cout << "Dst MAC: "<< setw(2) << setfill('0') << hex << eth->ether_dhost[i] << ":";
        if ((i+1) == ETHER_ADDR_LEN -1)
            cout << setw(2) << setfill('0') << hex << eth->ether_dhost[++i]; i++;
    }
}

int PacketParser::getIPInfo(const u_char *source) {
    // static header size: 20 bytes
    struct libnet_ipv4_hdr *ipv = (libnet_ipv4_hdr *)source;

    // print source ip address
    cout << "Src IP: " << ntohl(ipv->ip_src) << "\t";
    // print destination ip address
    cout << "Dst IP: " << ntohl(ipv->ip_dst) << endl;

    return ipv->ip_hl*4;
}

int PacketParser::getPortInfo(const u_char *source) {
    // static header size: 20 bytes
    struct libnet_tcp_hdr *tcp = (libnet_tcp_hdr *)source;

    // print source port address
    cout << "Src Port: " << ntohs(tcp->th_sport) << "\t";
    // print destination port address
    cout << "Dst Port: " << ntohs(tcp->th_dport) << endl;

    return tcp->th_off*4;
}

