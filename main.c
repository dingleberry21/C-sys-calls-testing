#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

int main(void) {
    char *buff = "Man, I LOVE Shrek!";
    int fd = creat("./shrek", S_IRWXU);
    while (fd == -1) {
        int err = errno;
        perror("ERROR");
        if (err == EINTR || err == EAGAIN) {
            fd = creat("./shreck", S_IRWXU);
        } else {
            printf("Fuck this shit I'm out.\n");
            exit(1);
        }
    }
    errno = 0;
    ssize_t written = write(fd, buff, strlen(buff));
    if (written == -1) {
        perror("ERROR");
        exit(1);
    }
    printf("Shit written (bytes): %ld\n", written);
    printf("Closing the file.\n");
    close(fd);

    return 0;
}