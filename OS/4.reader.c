#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024

int main()
{
int fd;
char *myfifo = "/storage/emulated/0/clg/pops/";
char buf[MAX_BUF];

// Open, read, and display message from the FIFO
fd = open(myfifo, O_RDONLY);
int bytes_read = read(fd, buf, MAX_BUF - 1);
buf[bytes_read] = '\0';  // add null terminator
printf("Writer: %s\n", buf);

close(fd);

return 0;
}