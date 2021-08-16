#ifndef WHITELISTUPDATER_H
#define WHITELISTUPDATER_H
#include <iostream>
#include <string>
#include <pcap.h>
#include <sys/inotify.h>
#include <vector>
#include <unistd.h>  // using read()
#include <fstream>   // using ifstream
#include <cstring>   // using strerror
using namespace std;

class WhiteListUpdater
{
    string pathname = "test.txt";
    ifstream fin;   //define read file
    vector <string> user_mac;
    vector <string> white_mac;
    struct user_info{
        string name;
        string mac;
    };
    struct white_info{
        string name;
        string mac;
    };

    struct user_info user_list[50];
    struct white_info white_list[50];

public:
    WhiteListUpdater();
    ~WhiteListUpdater();
    static void __handle_inotify_event(const struct inotify_event *event);
    void whitelist();
    void updater();
};

#endif // WHITELISTUPDATER_H
