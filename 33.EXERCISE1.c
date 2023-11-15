#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
    int n, fd;
    char buff[50];

    // Message printing on the display
    printf("Enter text to write in the file:\n");

    // Read from keyboard, specifying 0 as fd for std input device
    // Here, n stores the number of characters
    n = read(0, buff, 50);

    // creating a new file using open.
    fd = open("file", O_CREAT | O_RDWR, 0777);

    // Writing input data to file (fd)
    write(fd, buff, n);

    // Write to display (1 is standard fd for output device)
    write(1, buff, n);

    // Closing the file
    close(fd);

    return 0;
}
