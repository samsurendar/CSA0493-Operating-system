#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
    int fd = open("test.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        return 1;
    }
    printf("File status flags: %d\n", flags);
    off_t offset = lseek(fd, 10, SEEK_SET);
    if (offset == -1) {
        perror("lseek");
        return 1;
    }
    printf("File offset: %ld\n", (long) offset);
    struct stat st;
    if (stat("test.txt", &st) == -1) {
        perror("stat");
        return 1;
    }
    printf("File size: %ld bytes\n", (long) st.st_size);
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }
    return 0;
}

