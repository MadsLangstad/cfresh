# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11

# Library paths and includes for json-c
JSON_INCLUDE_DIRS = -I/usr/local/Cellar/json-c/0.18/include -I/usr/local/Cellar/json-c/0.18/include/json-c
JSON_LIB_DIRS = -L/usr/local/Cellar/json-c/0.18/lib
JSON_LIBS = -ljson-c

# Library paths and includes for libxml2
XML_INCLUDE_DIRS = $(shell xml2-config --cflags)
XML_LIBS = $(shell xml2-config --libs)

# Targets
BINARIES = json_serialization xml_serialization

all: $(BINARIES)

json_serialization: json_serialization.c
	$(CC) $(CFLAGS) $(JSON_INCLUDE_DIRS) -o $@ $< $(JSON_LIB_DIRS) $(JSON_LIBS)

xml_serialization: xml_serialization.c
	$(CC) $(CFLAGS) $(XML_INCLUDE_DIRS) -o $@ $< $(XML_LIBS)

clean:
	rm -f $(BINARIES)