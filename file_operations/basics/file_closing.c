#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("example.txt", "r+"); /* 
					    * Open for reading and writing
					    * */
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    /* Perform some operations */
    fseek(fp, 0, SEEK_END);
    fprintf(fp, "Adding a line before closing.\n");

    /* Closing the file */
    if (fclose(fp) != 0) {
        perror("Error closing the file");
        return EXIT_FAILURE;
    }

    printf("File closed successfully.\n");
    return EXIT_SUCCESS;
}

