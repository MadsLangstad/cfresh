# Serialization in C

This directory contains examples of serialization and deserialization in C, focusing on two widely used data interchange formats:

- **JSON (JavaScript Object Notation)**
- **XML (eXtensible Markup Language)**

## Contents

### `json_serialization.c`

Demonstrates how to serialize and deserialize JSON data using the [json-c](https://github.com/json-c/json-c) library.

### `xml_serialization.c`

Shows how to serialize and deserialize XML data using the [libxml2](http://xmlsoft.org/) library.

## Prerequisites

Before compiling and running the examples, ensure you have the necessary libraries installed:

### Installing Dependencies

#### On **Ubuntu/Debian**:

```bash
sudo apt-get update
sudo apt-get install libjson-c-dev libxml2-dev
On macOS (using Homebrew):
bash
Copy code
brew install json-c libxml2
brew link libxml2 --force
Note:
Ensure that the libraries are correctly linked during compilation. The provided Makefile handles the linking process.
Compilation Instructions
Navigate to this directory and use the provided Makefile to compile the examples:

bash
Copy code
make
This will generate two executables:

json_serialization
xml_serialization
Usage
1. JSON Serialization
bash
Copy code
./json_serialization
Sample Output:

yaml
Copy code
Serialized JSON:
{
    "id": 1,
    "name": "Alice Smith",
    "salary": 70000.0
}

Deserialized JSON:
ID: 1
Name: Alice Smith
Salary: 70000.00
2. XML Serialization
bash
Copy code
./xml_serialization
Sample Output:

javascript
Copy code
Serialized XML:
<Employee>
    <ID>2</ID>
    <Name>Bob Johnson</Name>
    <Salary>80000.00</Salary>
</Employee>

Deserialized XML:
ID: 2
Name: Bob Johnson
Salary: 80000.00
Files Overview
json_serialization.c:

Uses the json-c library to create a JSON object, serialize it to a string, and then deserialize it back to access individual fields.
xml_serialization.c:

Utilizes the libxml2 library to create an XML document, serialize it to a file, and then parse the file to retrieve and display the data.
Error Handling
Both examples include basic error handling. If you encounter issues related to library linking or missing dependencies, ensure that:

The required libraries are installed.
The Makefile correctly references the library paths.
License
This project is licensed under the MIT License. See the LICENSE file for details.
```
