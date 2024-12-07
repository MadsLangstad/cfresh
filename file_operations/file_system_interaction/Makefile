# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11

# Targets
BINARIES = directory_listing file_stat

# Default target
all: $(BINARIES)

directory_listing: directory_listing.c
	$(CC) $(CFLAGS) -o $@ $<

file_stat: file_stat.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean target
clean:
	rm -f $(BINARIES)
