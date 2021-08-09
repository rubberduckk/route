#include <iostream>
#include <iomanip>
#include <pcap.h>
#include <libnet.h>
#include <netinet/in.h>
#include "PacketParser.h"

using namespace std;

int main(int argc, char* argv[])
{
    PacketParser p(dev);

    char *dev = argv[1];    // interface name
    while(true){
        int res = p.getRes();

        if (res == 0)
            continue;
        if (res == -1 || res == -2) {
            cout << "pcap_next_ex return " << res << endl;
            break;
        }

        p.run();
    }
    /*
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(%s) return nullptr =%s\n", dev, errbuf);
        return -1;
    }

    while (true) {
        struct pcap_pkthdr *header;
        const u_char *packet;   // same as 'source' in PacketParser.cpp
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0)
            continue;
        if (res == 1 || res == -2) {
            cout << "pcap_next_ex return " << res << "(" << pcap_geterr(handle) << ")" << endl;
            break;
        }
        printPacketInfo(source, header->caplen);
    }
    pcap_close(handle);
    */
}
