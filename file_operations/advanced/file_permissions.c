/**
 * @file file_permissions.c
 * @brief Demonstrates how to manage file permissions in C using chmod.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

/**
 * @brief Changes the permissions of a file.
 * 
 * @param filename The name of the file.
 * @param mode The new permissions (e.g., 0644).
 */
void change_file_permissions(const char *filename, mode_t mode) {
    if (chmod(filename, mode) == -1) {
        perror("chmod failed");
        exit(EXIT_FAILURE);
    }
    printf("Permissions of '%s' changed to %o\n", filename, mode);
}

/**
 * @brief Displays the current permissions of a file.
 * 
 * @param filename The name of the file.
 */
void display_file_permissions(const char *filename) {
    struct stat file_stat;
    if (stat(filename, &file_stat) == -1) {
        perror("stat failed");
        exit(EXIT_FAILURE);
    }

    printf("Current permissions of '%s': %o\n", filename, file_stat.st_mode & 0777);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <mode>\n", argv[0]);
        fprintf(stderr, "Example: %s example.txt 0755\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    mode_t mode = strtol(argv[2], NULL, 8); // Convert octal string to mode_t

    display_file_permissions(filename);
    change_file_permissions(filename, mode);
    display_file_permissions(filename);

    return 0;
}
