#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("example.txt", "r"); /* Open for reading
					   * The 'r' creates a new file
					   **/
    if (fp == NULL) {
        perror("Error opening file for reading");
        return EXIT_FAILURE;
    }

    char buffer[256];
    printf("Contents of example.txt:\n");

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    if (ferror(fp)) {
        perror("Error reading from file");
        fclose(fp);
        return EXIT_FAILURE;
    }

    if (fclose(fp) != 0) {
        perror("Error closing the file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

