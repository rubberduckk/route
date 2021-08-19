#include "Whitelistupdater.h"
#define INOTIFY_PATH "/home/minseo/test0/test.txt"
#define BUF_SIZE 1024

void WhiteListUpdater::__handle_inotify_event(const struct inotify_event *event){
    if (event->mask & IN_ACCESS)
            printf("IN_ACCESS ");
        if (event->mask & IN_ATTRIB)
            printf("IN_ATTRIB ");
        if (event->mask & IN_CLOSE_NOWRITE)
            printf("IN_CLOSE_NOWRITE ");
        if (event->mask & IN_CLOSE_WRITE)
            printf("IN_CLOSE_WRITE ");
        if (event->mask & IN_CREATE)
            printf("IN_CREATE ");
        if (event->mask & IN_DELETE)
            printf("IN_DELETE ");
        if (event->mask & IN_ISDIR)
            printf("IN_ISDIR ");
        if (event->mask & IN_MODIFY)
            printf("IN_MODIFY ");
        if (event->mask & IN_MOVE_SELF)
            printf("IN_MOVE_SELF ");
        if (event->mask & IN_MOVED_FROM)
            printf("IN_MOVED_FROM ");
        if (event->mask & IN_MOVED_TO)
            printf("IN_MOVED_TO ");
        if (event->mask & IN_OPEN)
            printf("IN_OPEN ");
        if (event->len > 0)
            printf(": name = %s\n", event->name);
}

WhiteListUpdater::WhiteListUpdater(){
    fin.open(pathname);
    if(fin.fail()){
        cout << "Could not find the file : " << pathname << endl;
        exit(1);
    }
}

WhiteListUpdater::~WhiteListUpdater(){fin.close();}

void WhiteListUpdater::saveData(){
    string word;
    int num = 0;
    userInfo user;
    while (!fin.eof()) {
        fin >> word;   // divide file by word
        if(num == 1){
            user.changeMac(word);
        }
        else if(num == 2){
            user.changeIp(word);
        }
        else if(num == 3){
            user.changeName(word);
        }
        if(num == 4){
            whitemac[user.getMac()]=user;    // save  userinfo on map
            //cout << whitemac[user.getMac()].getName() << endl;
            num = -1;
        }
        num++;
    }
}

void WhiteListUpdater::updater(){
    char buf[BUF_SIZE] __attribute__ ((aligned(__alignof__(struct inotify_event))));
    // Return the struct to the value of the inotify_event type and place it in that unit.
    char *ptr;
    const struct inotify_event *event; //

    int fd = inotify_init();  // initalization inotify instance
    if(fd == -1){
        cout << "error!! : inialization fail"<<endl;
        exit(1);
    }
    int wd = inotify_add_watch(fd, INOTIFY_PATH, IN_MODIFY);  // add watch target
    if(wd == -1){  // if add_watch fail
        cout << "error!! : failed to add watch target "<<endl;
        exit(1);
    }

    while(1){
        ssize_t size = read(fd, buf, sizeof(buf));  //Maximum size that the current system can handle
        if (size == -1 && errno != EAGAIN){
            perror("read");
            fprintf(stderr, "read : %s", strerror(errno));
            exit(1);
        }
        if (size <= 0) break;
        for (ptr = buf; ptr < buf + size; ptr += sizeof(struct inotify_event) + event->len) {
            event = (struct inotify_event *)ptr;
            __handle_inotify_event(event);
         }
         int ret = inotify_rm_watch(fd, wd);
         if (ret < 0) {
             fprintf(stderr, "error! : Failed to rm watch [fd : %d] [wd : %d] [%s]", fd, wd, strerror(errno));
             perror("inotify_rm_watch");
             exit(1);
         }
    }
}
