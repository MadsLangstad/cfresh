# Makefile for file_operations/basics

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# List of source files
SOURCES = file_writing.c file_reading.c file_appending.c file_closing.c

# Generate list of executables by removing .c extension
TARGETS = $(SOURCES:.c=)

# Default target: build all executables
all: $(TARGETS)

# Pattern rule to build each executable from its source file
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up generated executables
clean:
	rm -f $(TARGETS)

# PHONY targets (not associated with files)
.PHONY: all clean

