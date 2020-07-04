// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
/*
you have to write first then ,then you can read
*/
int main()
{
    //created file descriptor
    int fd;
    // FIFO file path
    char *myfifo = "myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);

    char reading_message[80], writing_message[80];
    while(1)
    {
        printf("now this process will write  message and another waits \n" );

        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);
        // Take an input arr2ing from user.
        // 80 is maximum length
        fgets(writing_message, 80, stdin);

        // Write the input arr2ing on FIFO
        // and close it
        write(fd, writing_message, strlen(writing_message)+1);
        close(fd);

        // Open FIFO for Read only
        fd = open(myfifo, O_RDONLY);

        // Read from FIFO
        read(fd, reading_message, sizeof(reading_message));

        // Print the read message
        printf("User2: %s\n", reading_message);

        close(fd);
    }
    return 0;
}
