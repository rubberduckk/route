#include "PacketStatic.h"

void PacketStatic::insertlist(){
    this->whitemac.insert(make_pair<string, bool>("00:0c:29:fe:79:65", true));
}

void PacketStatic::adrlist(){
    this->adrstatic["00:0c:29:fe:79:65"];
}

void PacketStatic::saveheader(pcap_pkthdr *header){
    this->header = header;
    //cout << this->header->len << endl;
}

void PacketStatic::savemac(string smac, string dmac){
    this->smac = smac;
    this->dmac = dmac;
}

void PacketStatic::statistic(){
    //Data tmp;
    if(whitemac.count(this->smac)){
        /*
        tmp = adrstatic[this->smac];
        tmp.tx += this->header->len;
        adrstatic[this->smac] = tmp;
        */
        adrstatic[this->smac].tx += this->header->len;
        //cout << this->smac << endl;
        //cout << adrstatic[this->smac].tx << endl;
    }
    if(whitemac.count(this->dmac)){
        /*
        tmp = adrstatic[this->dmac];
        tmp.rx += this->header->len;
        adrstatic[this->dmac] = tmp;
        */
        adrstatic[this->dmac].rx += this->header->len;
        //cout << this->dmac << endl;
        //cout << adrstatic[this->dmac].tx << endl;
    }
}

void PacketStatic::printdata(){
    cout << this->adrstatic[string("00:0c:29:fe:79:65")].tx << "\t" << this->adrstatic[string("00:0c:29:fe:79:65")].rx  << endl;
}

void PacketStatic::run(){
    insertlist();
    statistic();
    printdata();
}
