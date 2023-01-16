#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    int fd;
    char buf[2048];
    int count;

    void print(int fd) {
        while(1) {
            count = read(fd, buf, sizeof buf);
            if (count == 0 || count == -1) {
                break;
            }
            write(1, buf, count);
        }
    }

    if (!(argc > 1)) {
        fd = 0;
        print(fd);
    } else {
        for(int i=1; i < argc; i++) {
            fd = open(argv[i], O_RDONLY);
            print(fd);
        }
    }
}