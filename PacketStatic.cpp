#include "PacketStatic.h"

void PacketStatic::insertlist(){
    this->whitemac.insert(make_pair<string, bool>("00:0c:29:fe:79:65", true));
}

void PacketStatic::saveheader(pcap_pkthdr *header){
    this->header = header;
}

void PacketStatic::savemac(string smac, string dmac){
    this->smac = smac;
    this->dmac = dmac;
}

void PacketStatic::statistic(){
    //Data tmp;
    if(whitemac.count(this->smac)){
        adrstatic[this->smac].tx += this->header->len;
    }
    if(whitemac.count(this->dmac)){
        adrstatic[this->dmac].rx += this->header->len;
    }
}

void PacketStatic::printdata(){
    cout << this->adrstatic[string("00:0c:29:fe:79:65")].tx << "\t" << this->adrstatic[string("00:0c:29:fe:79:65")].rx  << endl;
    cout << endl << "---------------------------------------------------------------" << endl;
}

void PacketStatic::run(){
    insertlist();
    statistic();
    printdata();
}
