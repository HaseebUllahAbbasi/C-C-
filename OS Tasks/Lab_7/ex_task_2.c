#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
/* This program reads first then messagees are written for other program
*/
int main()
{
    //created file descriptor
    int fd1;

    // FIFO file path
    char *myfifo = "myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);

    char reading_message[80], writing_message[80];
    while (1)
    {
        // First open in read only and read
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, reading_message, 80);

        // Print the read string and close
        printf("User1: %s\n", reading_message);
        close(fd1);

        printf("now this process will write  message and another waits \n" );

        // Now open in write mode and write
        // string taken from user.
        fd1 = open(myfifo,O_WRONLY);
        fgets(writing_message, 80, stdin);
        write(fd1, writing_message, strlen(writing_message)+1);
        close(fd1);
    }
    return 0;
}
