#include "PacketStatic.h"

void PacketStatic::insertlist(unordered_map<string, userInfo> whitemac){
    this->whitemac = whitemac;
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
    unordered_map<string, Data>::iterator it;
    for(it = adrstatic.begin(); it != adrstatic.end(); it++){
        cout << it->second.tx << "\t" << it->second.rx << endl;
    }
    cout << endl << "---------------------------------------------------------------" << endl;
}

void PacketStatic::run(){
    statistic();
    printdata();
}
