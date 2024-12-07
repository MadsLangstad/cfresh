/**
 * @file file_stat.c
 * @brief Retrieves and displays statistics of a specified file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>  // Added to declare strcspn

/**
 * @brief Displays the statistics of the given file.
 * 
 * @param filepath The path to the file.
 */
void display_file_stat(const char *filepath) {
    struct stat file_stat;

    if (stat(filepath, &file_stat) == -1) {
        perror("stat failed");
        exit(EXIT_FAILURE);
    }

    printf("Statistics for file '%s':\n", filepath);
    printf("Size: %lld bytes\n", (long long)file_stat.st_size);

    // File permissions
    printf("Permissions: ");
    printf( (S_ISDIR(file_stat.st_mode)) ? "d" : "-");
    printf( (file_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (file_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (file_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (file_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (file_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (file_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (file_stat.st_mode & S_IROTH) ? "r" : "-");
    printf( (file_stat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (file_stat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    // Last modification time
    char timebuf[80];
    struct tm *tm_info;

    tm_info = localtime(&file_stat.st_mtime);
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Last Modified: %s\n", timebuf);
}

int main(void) {  // Changed from int main()
    char filepath[1024];

    printf("Enter the file path to retrieve its statistics: ");
    if (fgets(filepath, sizeof(filepath), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }

    // Remove the trailing newline character from fgets
    filepath[strcspn(filepath, "\n")] = '\0';

    display_file_stat(filepath);

    return 0;
}
