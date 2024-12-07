/**
 * @file memory_mapped_files.c
 * @brief Demonstrates the use of memory-mapped files in C using mmap.
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/**
 * @brief Creates a file and writes initial data to it.
 * 
 * @param filename The name of the file.
 * @param data The string to write.
 */
void create_and_write_file(const char *filename, const char *data) {
    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    size_t length = strlen(data);
    if (write(fd, data, length) != (ssize_t)length) {
        perror("write failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Extend the file size if necessary
    if (ftruncate(fd, length) == -1) {
        perror("ftruncate failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
    printf("Created and wrote to file '%s'.\n", filename);
}

/**
 * @brief Maps a file into memory, modifies its content, and unmaps it.
 * 
 * @param filename The name of the file.
 */
void modify_file_with_mmap(const char *filename) {
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    // Get the size of the file
    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    size_t filesize = sb.st_size;

    // Memory-map the file
    char *map = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Modify the first character
    map[0] = 'h';

    // Optionally, modify more data
    // Example: Append a new line if space allows
    if (filesize >= 2) {
        map[filesize - 1] = '\n';
    }

    // Synchronize the mapped memory with the file
    if (msync(map, filesize, MS_SYNC) == -1) {
        perror("msync failed");
    }

    // Unmap the file
    if (munmap(map, filesize) == -1) {
        perror("munmap failed");
    }

    close(fd);
    printf("Modified file '%s' using mmap.\n", filename);
}

/**
 * @brief Reads and displays the content of a file.
 * 
 * @param filename The name of the file.
 */
void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }

    printf("Content of '%s':\n", filename);
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main(void) {
    const char *filename = "mmap_example.txt";
    const char *initial_data = "Hello, Memory-Mapped Files!\n";

    // Create and write initial data to the file
    create_and_write_file(filename, initial_data);

    // Read and display the initial content
    read_file(filename);

    // Modify the file using mmap
    modify_file_with_mmap(filename);

    // Read and display the modified content
    read_file(filename);

    return 0;
}
