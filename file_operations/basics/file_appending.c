#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("example.txt", "a"); /*
					   * Open for appending
					   **/
    if (fp == NULL) {
        perror("Error opening file for appending");
        return EXIT_FAILURE;
    }

    const char *additional_text = "Appending a new line to the file.\n";
    if (fprintf(fp, "%s", additional_text) < 0) {
        perror("Error appending to file");
        fclose(fp);
        return EXIT_FAILURE;
    }

    printf("Data appended successfully to example.txt\n");

    if (fclose(fp) != 0) {
        perror("Error closing the file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

