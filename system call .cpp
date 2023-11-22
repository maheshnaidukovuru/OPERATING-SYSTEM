//system call
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX_SIZE 100
int main() {
    char fileName[] = "sample.txt";
    char buffer[MAX_SIZE];
    int fileDescriptor = open(fileName, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fileDescriptor == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    printf("Enter data to write to the file (Ctrl+D to end):\n");
    while (fgets(buffer, MAX_SIZE, stdin) != NULL) {
        write(fileDescriptor, buffer, sizeof(buffer));
    }
    close(fileDescriptor);
    fileDescriptor = open(fileName, O_RDONLY);
    if (fileDescriptor == -1) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    printf("\nContents of the file:\n");
    ssize_t bytesRead;
    while ((bytesRead = read(fileDescriptor, buffer, sizeof(buffer))) > 0) { 
        write(STDOUT_FILENO, buffer, bytesRead);
    }
    close(fileDescriptor);
    return 0;
}

