#ifndef PACKETSTATIC_H
#define PACKETSTATIC_H
#include <iostream>
#include <unordered_map>
#include <string>
#include <pcap.h>
#include "userinfo.h"
using namespace std;

struct Data{
    int tx = 0;
    int rx = 0;
};

class PacketStatic {
private:
    struct pcap_pkthdr *header;
    string smac, dmac;
    unordered_map <string, userInfo> whitemac;
    unordered_map <string, Data> adrstatic;
public:
    void insertlist(unordered_map<string, userInfo> whitemac);
    void saveheader(pcap_pkthdr *header);
    void statistic();
    void savemac(string smac, string dmac);
    void printdata();
    void run();
};

#endif // PACKETSTATIC_H
