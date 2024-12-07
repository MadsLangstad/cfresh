/**
 * @file binary_file_handling.c
 * @brief Demonstrates reading from and writing to binary files in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

/**
 * @brief Writes an array of Employee structures to a binary file.
 * 
 * @param filename The name of the file to write to.
 * @param employees Array of Employee structures.
 * @param count Number of employees in the array.
 */
void write_binary_file(const char *filename, Employee *employees, size_t count) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    size_t written = fwrite(employees, sizeof(Employee), count, file);
    if (written != count) {
        perror("Error writing to file");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
    printf("Successfully wrote %zu employees to %s\n", count, filename);
}

/**
 * @brief Reads Employee structures from a binary file and displays them.
 * 
 * @param filename The name of the file to read from.
 */
void read_binary_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    Employee emp;
    printf("Reading employees from %s:\n", filename);
    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", emp.id, emp.name, emp.salary);
    }

    fclose(file);
}

int main(void) {
    const char *filename = "employees.dat";

    // Create sample employee data
    Employee employees[3] = {
        {1, "Alice Smith", 70000.0},
        {2, "Bob Johnson", 80000.0},
        {3, "Charlie Lee", 75000.0}
    };

    // Write to binary file
    write_binary_file(filename, employees, 3);

    // Read from binary file
    read_binary_file(filename);

    return 0;
}
