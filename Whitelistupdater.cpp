#include "Whitelistupdater.h"
#define INOTIFY_PATH "/home/minseo/WhiteListUpdater"
#define BUF_SIZE 1024

WhiteListUpdater::WhiteListUpdater(){}

void WhiteListUpdater::saveData(){
    fin.open(pathname);
    if(fin.fail()){
        cout << "Could not find the file : " << pathname << endl;
        exit(1);
    }
    string word;
    int num = 0;
    userInfo user;
    while (!fin.eof()) {
        fin >> word;
        if(num == 1){
            user.changeMac(word);
        }
        else if(num == 2){
            user.changeIp(word);
        }
        else if(num == 3){
            user.changeName(word);
        }
        else if(num == 4){
            whitemac[user.getMac()] = user;
            cout << whitemac[user.getMac()].getMac() << endl;
            num = -1;
        }
        num++;
    }
    cout << "----------------------" << endl;
    fin.close();
}

void WhiteListUpdater::updater(PacketStatic *ps){
    int fd;
    int wd;
    fd = inotify_init();
    if (fd < 0) {
      perror("inotify_init");
      exit(EXIT_FAILURE);
    }else cout << "success_init" << endl;

    wd = inotify_add_watch(fd, INOTIFY_PATH, IN_MODIFY);
    if (wd == -1){
        cout << "add error" << endl;
        exit(1);
    }else cout << "success_add" << endl;

    ssize_t len, i = 0;

    for (;;){
        char buf[BUF_SIZE] __attribute__((aligned(4)));
        i = 0;
        len = read (fd, buf, BUF_SIZE);
        while (i < len) {
            struct inotify_event *event = (struct inotify_event *) &buf[i];
            if (event->mask & IN_MODIFY){
                saveData();
                ps->insertlist(this->whitemac);
            }
            i += sizeof(inotify_event) + event->len;
        }
    }
}
