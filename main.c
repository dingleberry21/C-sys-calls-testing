#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
    char *buff = "Man, I LOVE Shrek!";
    int fd = creat("./shrek", S_IRWXU);
    if (fd == -1) {
        perror("ERROR");
        exit(1);
    }
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