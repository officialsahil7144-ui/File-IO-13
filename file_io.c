#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    int fd;
    char message[] = "Linux low-level file I/O demonstration\n";
    char buffer[100] = {0};

    fd = open("file_io.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("Error opening file for writing");
        return 1;
    }

    if (write(fd, message, strlen(message)) == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    close(fd);

    fd = open("file_io.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening file for reading");
        return 1;
    }

    ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);

    if (bytes == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    buffer[bytes] = '\0';
    printf("File contents:\n%s", buffer);
    printf("Bytes read: %zd\n", bytes);

    close(fd);
    return 0;
}
