#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
int main(void) { 
    const char *path = "io_demo.txt"; 
    const char *message = "Low-level file I/O using write().\n"; 
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644); 
    if (fd == -1) { perror("open"); return EXIT_FAILURE; } 
    ssize_t n = write(fd, message, strlen(message)); 
    if (n == -1) { perror("write"); close(fd); return EXIT_FAILURE; } 
    if (close(fd) == -1) { perror("close"); return EXIT_FAILURE; } 
    printf("Wrote %ld bytes to %s\n", (long)n, path); 
    printf("Address of local variable: %p\n", (void *)&n); 
    return EXIT_SUCCESS; 
} 
