#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("example.txt", "w"); // Open for writing
    if (fp == NULL) {
        perror("Error opening file for writing");
        return EXIT_FAILURE;
    }

    const char *text = "Hello, World!\nWelcome to file writing in C.\n";
    if (fprintf(fp, "%s", text) < 0) {
        perror("Error writing to file");
        fclose(fp);
        return EXIT_FAILURE;
    }

    printf("Data written successfully to example.txt\n");

    if (fclose(fp) != 0) {
        perror("Error closing the file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
