#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
int fd;
char *myfifo = "/storage/emulated/0/clg/pops/";

// Create the FIFO (named pipe)
mkfifo(myfifo, 0666);

printf("Run Reader process to read the FIFO File\n");

fd = open(myfifo, O_WRONLY);
write(fd, "Hi", sizeof("Hi"));
close(fd);

unlink(myfifo); // remove the FIFO file
return 0;
}