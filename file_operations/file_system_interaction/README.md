# File System Interaction in C

This directory contains examples of interacting with the file system in C. The provided examples demonstrate how to:

- **`directory_listing.c`**: List the contents of a directory.
- **`file_stat.c`**: Retrieve and display file statistics using the `stat` system call.

## Contents

### `directory_listing.c`

Demonstrates how to list all files and directories within a specified directory using the POSIX API (`opendir`, `readdir`, `closedir`).

### `file_stat.c`

Shows how to obtain and display various metadata of a file (such as size, permissions, and modification time) using the `stat` system call.

## Compilation Instructions

To compile the examples, navigate to this directory and use the provided `Makefile`:

```bash
make
This will generate two executables:

directory_listing
file_stat
Usage
1. Directory Listing
bash
Copy code
./directory_listing <directory_path>
Example:

bash
Copy code
./directory_listing /home/user/documents
Sample Output:

diff
Copy code
Contents of directory '/home/user/documents':
- report.docx
- presentation.pptx
- photos/
- notes.txt
2. File Statistics
bash
Copy code
./file_stat <file_path>
Example:

bash
Copy code
./file_stat /home/user/documents/report.docx
Sample Output:

yaml
Copy code
Statistics for file '/home/user/documents/report.docx':
Size: 15234 bytes
Permissions: -rw-r--r--
Last Modified: 2024-04-27 14:35:22
Notes
Ensure you have the necessary permissions to read the directories and files you intend to interact with.
These examples are intended for Unix-like operating systems. Modifications may be required for compatibility with Windows.
License
This project is licensed under the MIT License. See the LICENSE file for details.
```
