#ifndef WHITELISTUPDATER_H
#define WHITELISTUPDATER_H
#include "PacketStatic.h"
#include <iostream>
#include <string>
#include <pcap.h>
#include <sys/inotify.h>
#include <vector>
#include <unistd.h>  // using read()
#include <fstream>   // using ifstream
#include <cstring>   // using strerror
#include <unordered_map>
#include <errno.h>
#include "userinfo.h"

using namespace std;

class WhiteListUpdater
{
    string pathname = "/home/minseo/WhiteListUpdater/test.txt";
    ifstream fin;   //define read file
    unordered_map<string, userInfo> whitemac;
    int flag;
public:
    WhiteListUpdater();
    void saveData();
    void updater(PacketStatic *ps);
};

#endif // WHITELISTUPDATER_H
