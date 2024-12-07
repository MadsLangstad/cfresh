/**
 * @file directory_listing.c
 * @brief Lists the contents of a specified directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/**
 * @brief Lists all files and directories within the specified directory.
 * 
 * @param path The path to the directory.
 */
void list_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    printf("Contents of directory '%s':\n", path);
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        printf("- %s\n", entry->d_name);
    }

    closedir(dir);
}

int main(void) {  // Changed from int main()
    char path[1024];

    printf("Enter the directory path to list its contents: ");
    if (fgets(path, sizeof(path), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }

    // Remove the trailing newline character from fgets
    path[strcspn(path, "\n")] = '\0';

    list_directory(path);

    return 0;
}
