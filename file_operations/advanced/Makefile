# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
LDFLAGS =

# Executables
BINARIES = binary_file_handling file_permissions file_streams memory_mapped_files

# Default target
all: $(BINARIES)

# Rules for each binary
binary_file_handling: binary_file_handling.c
	$(CC) $(CFLAGS) -o $@ $^

file_permissions: file_permissions.c
	$(CC) $(CFLAGS) -o $@ $^

file_streams: file_streams.c
	$(CC) $(CFLAGS) -o $@ $^

memory_mapped_files: memory_mapped_files.c
	$(CC) $(CFLAGS) -o $@ $^

# Clean target to remove binaries and intermediate files
clean:
	rm -f $(BINARIES)

# Phony targets
.PHONY: all clean
