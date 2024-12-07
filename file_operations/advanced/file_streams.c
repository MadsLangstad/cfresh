/**
 * @file file_streams.c
 * @brief Demonstrates the use of different file streams in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Writes text to a file using fwrite.
 * 
 * @param filename The name of the file.
 * @param data The string to write.
 */
void write_with_fwrite(const char *filename, const char *data) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("fopen for writing failed");
        exit(EXIT_FAILURE);
    }

    size_t len = fwrite(data, sizeof(char), strlen(data), file);
    if (len != strlen(data)) {
        perror("fwrite failed");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
    printf("Data written to %s using fwrite.\n", filename);
}

/**
 * @brief Reads text from a file using fread.
 * 
 * @param filename The name of the file.
 */
void read_with_fread(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("fopen for reading failed");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    size_t len = fread(buffer, sizeof(char), sizeof(buffer) - 1, file);
    if (ferror(file)) {
        perror("fread failed");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    buffer[len] = '\0'; // Null-terminate the string
    fclose(file);
    printf("Data read from %s using fread:\n%s\n", filename, buffer);
}

/**
 * @brief Writes text to a file using fprintf.
 * 
 * @param filename The name of the file.
 * @param data The string to write.
 */
void write_with_fprintf(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen for writing failed");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s", data);
    fclose(file);
    printf("Data written to %s using fprintf.\n", filename);
}

/**
 * @brief Reads text from a file using fgets.
 * 
 * @param filename The name of the file.
 */
void read_with_fgets(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen for reading failed");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    printf("Data read from %s using fgets:\n", filename);
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main(void) {
    const char *filename = "stream_example.txt";
    const char *data = "Hello, World!\nThis is an example of file streams in C.\n";

    // Write using fwrite
    write_with_fwrite(filename, data);

    // Read using fread
    read_with_fread(filename);

    // Write using fprintf
    write_with_fprintf(filename, "Appending a new line using fprintf.\n");

    // Read using fgets
    read_with_fgets(filename);

    return 0;
}
