#ifndef USERINFO_H
#define USERINFO_H
#include <iostream>
#include <string>
using namespace std;

class userInfo
{
    string name;
    string mac;
    string ip;
public:
    userInfo();
    void changeName(string c_name){name = c_name;};
    void changeMac(string c_mac){mac = c_mac;};
    void changeIp(string c_ip){ip = c_ip;};
    string getName(){return this->name;};
    string getMac(){return this->mac;};
    string getIp(){return this->ip;};
};

#endif // USERINFO_H
