#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void my_print(int fd);

int main(int argc, char *argv[]) {

    int fd;

    if (!(argc > 1)) {
        fd = 0;
        my_print(fd);
        close(fd);
    } else {
        for(int i=1; i < argc; i++) {
            fd = open(argv[i], O_RDONLY);
            my_print(fd);
            close(fd);
        }
    }
}

void my_print(int fd) {
    char buf[2048];
    int count;
    while(1) {
        count = read(fd, buf, sizeof buf);
        if (count == 0) {
            break;
        } else if (count == -1) {
            perror("Open");
            exit(1);
        }
        write(1, buf, count);
    }
}
