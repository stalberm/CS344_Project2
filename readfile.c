#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    if (argc != 2) {}
    char *file_name = argv[1];

    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {perror("open");}
    char buf[2048];
    int count;
    count = read(fd, buf, sizeof buf);
    write(1, buf, count);
    close(fd);
}
